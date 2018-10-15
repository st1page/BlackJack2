#ifndef __PLAYER_H__
#define __PLAYER_H__

#include<vector>

#include "hand.h"
#include "card.h"

using namespace std;
class Player{
	protected: 
		string name;
		Hand hand;
		int medal;
		int bet;
	public:
		void debug();
		Player(string nm,int md);
		void clearHand();
		Hand getHand();
		void addCard(Card x);
		void addMedal(int x);
		void addBet(int x);
		int getMedal();
		int getBet();
		string getName();
		void setName(string s);
};
#endif