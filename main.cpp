#include <cstdio>
#include <cstdlib>
#include<iostream>
#include "player.h"
#include "dealer.h"
#include "page.h"
#include "cardHeap.h"
#include "option.h"
#include "UI.h"

using namespace std;
void init(){

#if defined(__linux__)
	system("resize -s 25 80");
#elif defined(_WIN32)
	system("mode con cols=80 lines=25");
#endif
}
UI ui;
void mainMenu();
void result(Dealer &dealer, Player &player, int win){
	if(win>0) ui.win();
	else if(win<0) ui.lose();
	else ui.push();
	ui.result(dealer,player,win);
}
int play(Dealer &dealer, Player &player, CardHeap &heap){
	int medal = player.getMedal();
	int bet = ui.getBet(medal);
	while(bet < 50 || bet > min(medal,200)) bet = ui.getBet(medal);
	player.addMedal(-bet);	
	ui.gameInit(medal,bet);
	if(heap.tryReset()) ui.modal("Reshuffle!");
	player.clearHand();
	dealer.clearHand();

	Card c = heap.pop();
	dealer.addCard(c);
	ui.modal("The first card is "+c.getFigureS());
	ui.firstCard(c);
	
	c = heap.pop();
	player.addCard(c);
	ui.getCard(c,1);
	int flag1=0,flag2=0;
	while(1){
		if(dealer.judge()){
			ui.modal("Dealer : HIT!");
			c = heap.pop();
			dealer.addCard(c);
			ui.updateDealer(dealer.getHand().getTot());
			if(dealer.getHand().getPoints()>21){
				ui.bust();
				player.addMedal(bet*2);
				result(dealer, player, 1);
				break;
			}
		} else {
			ui.modal("Dealer : STAND!");
			flag1=1;
		}
		if(flag1&&flag2){
			int x = player.getHand().getPoints() - dealer.getHand().getPoints();
			if(x>0) player.addMedal(bet*2);
			if(x==0) player.addMedal(bet);
			result(dealer, player, x);
			break;
		} else flag2=0;
		int op = ui.getOp();
		while(op<1||op>4) op = ui.getOp();
		int db;
		bool flag=0;
		switch(op){
		case 1:
			c = heap.pop();
			player.addCard(c);
			ui.getCard(c,player.getHand().getTot());
			if(player.getHand().getPoints()>21){
				ui.bust();
				result(dealer, player, -1);
				flag = 1;
			}
			break;
		case 2:
			flag2=1;
			break;
		case 3:
			if(medal < bet) ui.modal("Not have enough medal");
			else {
				player.addMedal(-bet);
				bet *= 2;
				ui.updateMedal(medal, bet);
			}
			op = ui.getOp();
			while(op!=1&&op!=2&&op!=4){
				if(op == 3) ui.modal("You have done it"); 
				op = ui.getOp();
			}
			switch(op){
			case 1:
				c = heap.pop();
				player.addCard(c);
				ui.getCard(c,player.getHand().getTot());
				break;
			case 2:
				flag2=1;
				break;
			case 4:
				db = bet / 2;
				player.addBet(-db); 	bet -= db;
				player.addMedal(db);	medal += db;
				result(dealer, player, -1);
				break;
			}
			break;
		case 4:
			db = bet / 2;
			player.addBet(-db); 	bet -= db;
			player.addMedal(db);	medal += db;
			result(dealer, player, -1);
			break; 
		}
		if(flag) break;
		if(flag1&&flag2){
			int x = player.getHand().getPoints() - dealer.getHand().getPoints();
			if(x>0) player.addMedal(bet*2);
			if(x==0) player.addMedal(bet);
			result(dealer, player, x);
			break;
		} else flag1=0;

	}
	string s = "Continue playing?(y/n)";
	int x = ui.confirm(s);
	while(x == -1) x = ui.confirm(s);
	return x;
}
void game(){
	Option opt; opt.load();
	Dealer dealer = Dealer(opt.getDiffculty());
	cout<<"aaa"<<endl;
	Player player = Player(opt.getName(), opt.getMedal());
	cout<<"bbb"<<endl;
	cout<<opt.getDeckSum()<<endl;
	CardHeap heap = CardHeap(opt.getDeckSum());
	cout<<"ccc"<<endl;
	int x = play(dealer,player,heap);
	while(x) x = play(dealer,player,heap);
	mainMenu();
}
void option(){
	Option x = ui.option();
	x.save();
	mainMenu();
}
void help(){
	ui.help();
	mainMenu();
}
void quit(){
	string s = "Do you really want to quit?(y/n)";
	int x = ui.confirm(s);	
	while(x == -1) x = ui.confirm(s);
	if(x) return ;
	else mainMenu();
}
void mainMenu(){
	int x = ui.mainMenu();
	while(x<1||x>4) x = ui.mainMenu();
	switch(x){
		case 1:
			game();
			break;
		case 2:
			option();
			break;
		case 3:
			help();
			break;
		case 4:
			quit();
			break; 
	}
}
int main(){
	init();
	ui.welcome();
	mainMenu();
	return 0;
}
