#include <cstdio>
#include <cstdlib>

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
int play(Dealer &dealer, Player &player, CardHeap &heap){
	
}
void game(){
	Option opt;
	Dealer dealer = Dealer(opt.getDiffculty());
	Player player = Player(opt.getName(), opt.getMedal());
	CardHeap heap = CardHeap(opt.getDeckSum());
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