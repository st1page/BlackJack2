#include "UI.h"

#include <vector>
#include <cstring>
#include <iostream>

#include "cardPic.h"
#include "modalPic.h"

using namespace std;

const string src = "./source/";
int gtDigit();
int gtYN();
int gtNum();
void pause();
void UI::welcome(){
	page = Page(src+"welcom");
	page.out();
	pause();
	return ;
}
int UI::confirm(string s){
	page = Page(src+"confirm");
	page.centerInsStr(13,s);
	page.out();
	int x = gtYN();
	page.out();
	return x;
}
int UI::mainMenu(){
	page = Page(src+"mainMenu");
	page.out();
	int x = gtDigit();
	page.out();
	return x;
}
Option UI::option(){
	Option res; string s; int x;
	cout<<"\n\n\n";
	cout<< "Enter your name:";
	getline(cin,s);
	cout<< "Enter the initial medal (100-10000)";
	x = gtNum(); 
	while(x<100 || x>10000) {
		cout<< "Enter the initial medal (100-10000)";
		x = gtNum(); 
	}
	res.setMedal(x);
	cout<< "Enter the sum of decks (1-4)";
	x = gtDigit();
	while(x<1 || x>4) {
		cout<< "Enter the sum of decks (1-4)";
		x = gtNum(); 
	}
	res.setDeckSum(x);
	return res;
}

void UI::modal(string s,string header,string footer){
	int len = max( max(s.size(), header.size() ), footer.size()); 
	int w,h;
	cout<<len<<endl;
	if(len <= 20) {
		w = 25; h = 5;
	} else if(len <= 50){
 		w = 60; h = 7;
	} else {
		w = len + 6;
		h = 7;
	}
	ModalPic p = ModalPic(w,h);
	p.setHeader(header);
	p.setFooter(footer);
	p.setContent(vector<string>(1,s) );
	Page npage = page;
	npage.centerInsPic(p);
	npage.out(); 
	pause();
	page.out();
}
void UI::modal(Pic p,string header,string footer){
	int w = max((int)max(header.size(), footer.size()), p.getWidth())+6;
	int h = p.getHeight() + 4;
	
	ModalPic mp = ModalPic(w,h);
	mp.setHeader(header);
	mp.setFooter(footer);
	mp.setContent(p.getA());
	Page npage = page;
	npage.centerInsPic(mp);
	npage.out(); 
	pause();
	page.out();
}
void UI::help(){ //unfinushed
	modal("Sorry is not finished");
}
int UI::getBet(int medal){
	page = Page(src+"confirm");
	int mx = min(medal, 200);
	page.centerInsStr(13,"You have "+to_string(medal)+" medals. How much to bet? (50-" +to_string(mx)+ ")");
	page.out();
	int x = gtNum();
	page.out();
	return x;
}
void UI::updateMedal(int medal,int bet){
	page.insStr(2,12,"            ");
	page.insStr(3,12,"            ");
	page.insStr(2,12,to_string(medal));
	page.insStr(3,12,to_string(bet));
	page.out();
} 
void UI::gameInit(int medal,int bet){
	page = Page(src+"game");
	updateMedal(medal,bet);
	page.out();
}
void UI::updateDealer(int tot){
	if(tot == 2) page.insPic(14, 66, CardPic());
	page.insStr(14, 48, to_string(tot)+" cards");
	page.out();
}
void UI::firstCard(Card x){
	CardPic p = CardPic(x);
	page.insPic(12, 61, p);
	page.insStr(14, 48, "1 card");
	page.insStr(17, 56, x.getFigureS());
	page.out();
}
void UI::getCard(Card x,int i){
	modal("You get a "+x.getFigureS());
	int y = 8 * i - 5;
	CardPic p(x);
	page.insPic(5,y,p);
	page.out();
}
int UI::getOp(){
	int x = gtDigit();
	page.out();
	return x;
}
void UI::win(){
	modal(Pic(src+"win"));
}		
void UI::lose(){
	modal(Pic(src+"lose"));
}
void UI::bust(){
	modal(Pic(src+"bust"));
}
void UI::push(){
	modal(Pic(src+"push"));
}
void UI::result(Dealer dealer, Player player, int win){
	dealer.debug(); player.debug();
	page = Page(src+"result");
	vector<Card> cards = player.getHand().getCards();
	for(int i=0;i<cards.size();i++) {
		CardPic cp(cards[i]);
		page.insPic(5,8*i+4,cp);
	}
	cards = dealer.getHand().getCards();
	for(int i=0;i<cards.size();i++) {
		CardPic cp(cards[i]);
		page.insPic(12,8*i+4,cp);
	}
	page.insStr(19,13,to_string(player.getHand().getPoints()));
	page.insStr(20,13,to_string(dealer.getHand().getPoints()));
	page.out();
	pause(); 
}
inline int isYN(char ch){ return (ch=='y'||ch=='Y'||ch=='n'||ch=='N'); }
int gtDigit(){
	string s; getline(cin,s);
	int st=0,n=s.size()-1;
	while(isspace(s[n]) && n>=st) n--;
	while(isspace(s[st]) && n>=st) st++;
	if(!isdigit(s[st])) return -1;
	if(n!=st) return -1;
	return s[st]-'0';
}
int gtYN(){
	string s; getline(cin,s);
	int st=0,n=s.size()-1;
	while(isspace(s[n]) && n>=st) n--;
	while(isspace(s[st]) && n>=st) st++;
	if(!isYN(s[st])) return -1;
	if(n!=st) return -1;
	if(s[st]=='Y'||s[st]=='y') return 1;
	else return 0;
}
int gtNum(){
	string s; getline(cin,s);
	int st=0,n=s.size()-1;
	while(isspace(s[n]) && n>=st) n--;
	while(isspace(s[st]) && n>=st) st++;
	for(int i=st;i<=n;i++) if(!isdigit(s[i])) return -1;
	int x=0;
	for(int i=st;i<=n;i++) x = x * 10 + s[i] - '0'; 
	return x;
}
void pause(){
	string s; getline(cin,s);
}
