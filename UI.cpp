#include "UI.h"

#include <cstring>
#include <iostream>

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
	return gtYN();
}
int UI::mainMenu(){
	page = Page(src+"mainMenu");
	page.out();
	return gtDigit();
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

void UI::modal(string s,string header = "",string footer = ""){
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
}
void UI::modal(Pic p,string header = "",string footer = ""){
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
}
void UI::help(){ //unfinushed
	modal("Sorry is not finished");
}
void UI::play(){

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