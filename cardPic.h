#ifndef __CARDPIC_H__
#define __CARDPIC_H__

#include <string>

#include "pic.h"
#include "card.h"

using namespace std;

class CardPic: public Pic{
	private: 
		int key;
	public:
		CardPic(void);
		CardPic(Card x);
		int getKey(void);
};
#endif