#ifndef __UI_H__
#define __UI_H__


#include "pic.h"
#include "page.h"
#include "card.h"
#include "option.h"
#include "dealer.h"
#include "player.h"

using namespace std;

class UI{
	private: 
		Page page;
	public:
		void welcome();
		int confirm(string s);
		int mainMenu();
		Option option();
		void help(); //unfinushed
		void modal(string s, string header="", string footer="");
		void modal(Pic p, string header="", string footer="");
		int getBet(int medal);
		void updateMedal(int medal,int bet);
		void updateDealer(int tot);
		void gameInit(int medal,int bet);
		void firstCard(Card x);
		void getCard(Card x,int i);
		int getOp();
		void win();
		void lose();
		void bust();
		void push();
		void result(Dealer dealer, Player player, int win);
};

#endif