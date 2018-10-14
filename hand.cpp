#include "hand.h"

Hand::Hand(void) {
	cards.clear();
	A_tot = sum = 0;
}
void Hand::addCard(Card x) {
	cards.push_back(x);
	if( x.getFigure() == 1) A_tot++;
	sum += x.getValue();
}
vector < Card > Hand::getCards(void) {
	return cards;
}
int Hand::getPoints(void) {
	 int res = sum, t = A_tot;
	 while(res > 21 && t){
	 	res -= 10; t--;
	 } 
	 return res;
}