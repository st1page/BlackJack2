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
	public:
		Player(string nm,int md);
		void addCard(Card x);
		void addmedal(int x);
		string getName();
		void setName(string s);
};
#endif