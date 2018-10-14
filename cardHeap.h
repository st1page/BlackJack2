#ifndef __CARDHEAP_H__
#define __CARDHEAP_H__

#include<vector>

#include "card.h"

using namespace std;
class CardHeap{
	private: 
		vector < Card > cards;
		int siz;
		void genCards(void);
	public:
		CardHeap(int x); //几副牌
		Card pop(void);
		bool tryReset();
};
#endif