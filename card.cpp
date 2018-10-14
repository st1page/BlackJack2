#include"card.h"

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
int Card::getValue(void){
	int x = key % 13 + 1; 
	if( x > 10) x =10;
	if( x == 1) x =11; 
	return x;
}
