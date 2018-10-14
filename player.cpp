#include "player.h"

Player::Player(string nm,int md){
	name = nm;
	medal = md;
}
void Player::addCard(Card x){
	hand.addCard(x);
}
void Player::addmedal(int x){
	medal += x;
}
string Player::getName(){
	return name;
}
void Player::setName(string s){
	name = s; 
}