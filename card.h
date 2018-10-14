#ifndef __CARD_H__
#define __CARD_H__

#include <string>
using namespace std;

class Card{
	private: 
		int key;
	public:
		Card(void);
		Card(int x);
		int getKey(void);
		int getPattern(void);
		int getFigure(void);
		int getValue(void);		
};
#endif