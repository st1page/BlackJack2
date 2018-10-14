#include "modalPic.h"
#include <iostream>
ModalPic::ModalPic(int w,int h):Pic(w, h){
	cout<<w<<" "<<h<<endl;
	for(int i=0;i<h;i++) a[i][0] = a[i][w-1] = '#';
	std::cout<< a[0][0]<<endl;	
	for(int j=0;j<w;j++) a[0][j] = a[h-1][j] = '#';
}
void ModalPic::setHeader(string s){
	centerInsStr(0,s);
}
void ModalPic::setFooter(string s){
	centerInsStr(height-1,s);
}
void ModalPic::setContent(vector<string> a){
	int tb = (height - a.size()) / 2;
	for(int i=0;i<a.size();i++)  centerInsStr(tb+i,a[i]);
}

