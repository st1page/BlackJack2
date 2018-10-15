#include"card.h"

string figure[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
Card::Card(void) { }
Card::Card(int x) {
	key = x % 52; 
}
int Card::getKey(void){
	return key;
}
int Card::getPattern(void) {
	return key / 13;
}
int Card::getFigure(void) {
	return key % 13 + 1;
}
string Card::getFigureS(void){
	return figure[key % 13];
}
int Card::getValue(void){
	int x = key % 13 + 1; 
	if( x > 10) x =10;
	if( x == 1) x =11; 
	return x;
}
