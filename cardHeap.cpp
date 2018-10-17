#include "cardHeap.h"

#include<algorithm>
short a[1000];
void CardHeap::genCards(){
	srand(time(0));
	cards.clear();
	for(int i=0;i<siz;i++) a[i] = i%52;
	random_shuffle(a,a+siz);
	cards.reserve(siz);
	for(int i=0;i<siz;i++) cards.push_back(Card(a[i]));
}
CardHeap::CardHeap(int x = 1){ //x副牌
	siz = x * 52;
	genCards();
} 
Card CardHeap::pop(void){
	Card x = cards.back();
	cards.pop_back();
	return x;
}
bool CardHeap::tryReset(){
	if(2*cards.size() <= siz) {
		genCards();
		return true;
	} else return false;
}