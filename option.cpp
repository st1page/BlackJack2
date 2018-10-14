#include "option.h"

#include <iostream>
#include <fstream>

const string filepath = "./source/option";

Option::Option(){
	medal = 1000; 
	decksum = 1;
	difficulty = 1;
	name = "Player";
}
int Option::getMedal(){
	return medal;
}
void Option::setMedal(int x){
	medal = x;
}
int Option::getDeckSum(){
	return decksum;
}
void Option::setDeckSum(int x){
	decksum = x;
}
int Option::getDiffculty(){
	return difficulty;
}
void Option::setDiffculty(int x){
	difficulty = x;
} 
string Option::getName(){
	return name;
}
void Option::setName(string s){
	name = s;
}
void Option::save(){
	ofstream fout;
	fout.open(filepath);
	if(!fout.is_open()){
		cout<<"can't find "+filepath<<endl;
		return ;
	}
	unsigned int hash;
	hash = difficulty | (decksum <<2) | (medal<<5);
	fout <<hash << " "<<name<<endl; 
	fout.close();
}
void Option::load(){
	ifstream fin;
	fin.open(filepath);
	if(!fin.is_open()){
		cout<<"can't find "+filepath<<endl;
			return ;
	}
	unsigned hash = 0;
	fin >> hash >>name;
	if(hash) {
		difficulty = hash|3;
		decksum = (hash>>2)|7;
		medal = (hash>>5);
	}
	fin.close();
}