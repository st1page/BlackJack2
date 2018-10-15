#include "player.h"
#include<iostream>
Player::Player(string nm,int md){
	name = nm;
	medal = md;
	bet = 0;
}
void Player::debug(){
	cout<<name<<" debug "<<endl;
	vector < Card > cards = hand.getCards(); 
	for(int i=0;i<cards.size();i++) cout<<cards[i].getFigure()<<endl;
	cout<<"=========="<<endl;
}
void Player::clearHand(){
	hand = Hand();
}
Hand Player::getHand(){
	return hand;
}
void Player::addCard(Card x){
	hand.addCard(x);
}
void Player::addMedal(int x){
	medal += x;
}
int Player::getMedal(){
	return medal;
}
void Player::addBet(int x){
	bet += x;
}
int Player::getBet(){
	return bet;
}
string Player::getName(){
	return name;
}
void Player::setName(string s){
	name = s; 
}