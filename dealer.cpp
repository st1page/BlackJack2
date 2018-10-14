#include "dealer.h"
Dealer::Dealer(int d):Player("Dealer",0){
	for(int i=0;i<=10;i++) heapMemory[i] = 0;
	difficulty = d;
}
bool Dealer::AI_judge(int round){ // not finished
	return nomal_judge();
} 
bool Dealer::nomal_judge(){
	int points = hand.getPoints();
	return (points <= 17);
}
bool Dealer::judge(int round){
	return nomal_judge();
}
void Dealer::mem_init(int x){	
	for(int i=1;i<=9;i++) heapMemory[i] = x;
	heapMemory[10] = 4 * x;
} 
void Dealer::mem_change(Card card){
	int x = card.getValue();
	if(x == 11) x = 1;
	heapMemory[x]--;
}
