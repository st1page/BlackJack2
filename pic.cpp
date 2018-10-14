#include "pic.h"

#include <iostream>
#include <fstream>
#include <algorithm>

Pic::Pic(int w,int h){
	cout<<w<<" "<<h<<endl;
	width = w;
	height = h;
	for(int i=0;i<h;i++) a.push_back(string(width,' '));
}
Pic::Pic(string filepath){
	ifstream fin;
	fin.open(filepath);
	if(!fin.is_open()){
		cout<<"can't find "+filepath<<endl;
		return ;
	}
	string s;
	a.clear(); width = 0;
	while (!fin.eof()) {
		getline(fin, s);
		width = max(width, (int)s.size());
		a.push_back(s);
	}
	height = a.size();
	fin.close();
}
int Pic::getWidth(){
	return width;
}
int Pic::getHeight(){
	return height;
}
vector<string> Pic::getA(){
	return a;
}
void Pic::insStr(int x,int y,string s){
	for(int i=0;i<s.size();i++) {
		if(y+i>=width) break;
		a[x][y+i] = s[i];
	}
}
void Pic::centerInsStr(int i,string s){
	int tb = (width - s.size()) / 2;
	insStr(i,tb,s);
}
string Pic::getLine(int i) {
	if(i >= height) return string(width,' ');
	return a[i];
}
void Pic::setLine(int i,string s){ 
	while(s.size() != width) s.push_back(' ');
	a[i] = s;
}
Pic Pic::operator +(Pic& right){
	int w,h;
	w = getWidth() + right.getWidth();
	h = max(getHeight(), right.getHeight());
	Pic res(w, h);
	for(int i=0;i<h;i++) res.setLine(i, getLine(i) + right.getLine(i));
	return res;
}
void Pic::debug(){
	for(int i=0;i<getHeight();i++) cout<<a[i]<<endl;
}
