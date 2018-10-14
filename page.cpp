#include "page.h"
#include <fstream>
#include <iostream>
#define Height (24)
#define Width (80)

void filter(string &s){
//	cout<<s.length()<<endl;
	while(s.length() < Width) s.push_back(' ');
	while(s.length() > Width) s.pop_back();
}
Page::Page(void){
	for(int i=0;i<Height;i++) a[i] = string(Width,' ');
}
Page::Page(string filepath){
	ifstream fin;
	fin.open(filepath);
	if(!fin.is_open()){
		cout<<"can't find "+filepath<<endl;
		return ;
	}
	string s; int i=0;
	while (!fin.eof()) {
		if(i == Height) break;
		getline(fin, s); 

		filter(s);cout<<s<<endl;
		a[i++] = s;
	}
	while (i != Height) a[i++] = string(Width,' ');
	fin.close();
}
void Page::setLine(int i,string s){
	filter(s);
	a[i] = s;
}
void Page::print(void){
	for(int i=0;i<Height;i++) cout<<a[i]<<endl;
}
void Page::insPic(int x,int y,Pic p){
	int h = p.getHeight(), w = p.getWidth();
	vector<string> b = p.getA();
	for(int i=0;i<h;i++) 
		for(int j=0;j<w;j++) 
			a[x+i][y+j] = b[i][j];
	return ;
}
void Page::centerInsPic(int i,Pic p){
	int tb = (Width - p.getWidth()) / 2;
	insPic(i,tb,p);
}
void Page::centerInsPic(Pic p){
	int tb = (Height - p.getHeight()) / 2;
	centerInsPic(tb,p);
}
void Page::insStr(int x,int y,string s){
	for(int i=0;i<s.size();i++) a[x][y+i] = s[i];
}
void Page::centerInsStr(int i,string s){
	int tb = (Width - s.size())/2;
	insStr(i,tb,s);
}
void Page::out(){
	for(int i=0;i<Height;i++) cout<<a[i]<<endl;
	return ;
}
#undef Height
#undef Width