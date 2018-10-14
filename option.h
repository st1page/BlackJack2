#ifndef __OPTION_H__
#define __OPTION_H__

#include <string>
using namespace std;
class Option{
	private: 
		int medal,decksum,difficulty;
		string name;
	public:
		Option();
		int getMedal();
		void setMedal(int x);
		int getDeckSum();
		void setDeckSum(int x);
		int getDiffculty();
		void setDiffculty(int x); 
		string getName();
		void setName(string s);
		void save();
		void load();
};
#endif