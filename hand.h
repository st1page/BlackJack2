#ifndef __HAND_H__
#define __HAND_H__

#include<vector>

#include "card.h"

using namespace std;
class Hand{
	private: 
		vector < Card > cards;
		int A_tot,sum;
	public:
		Hand(void);
		int getTot(void);
		void addCard(Card x);
		vector < Card > getCards(void);
		int getPoints(void);
};
#endif