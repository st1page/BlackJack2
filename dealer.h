#ifndef __DEALER_H__
#define __DEALER_H__

#include<vector>

#include "player.h"

using namespace std;
class Dealer: public Player{
	private: 
		short difficulty; // not finished
		short heapMemory[11];
		bool AI_judge(int round); // not finished
		bool nomal_judge();
	public:
		Dealer(int d);
		bool judge(int round);
		void mem_init(int x);
		void mem_change(Card card);
};
#endif