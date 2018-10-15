#ifndef __PAGE_H__
#define __PAGE_H__

#include<string>
#include<vector>

#include "pic.h"

#define Height (24)
#define Width (80)

using namespace std;
class Page{
	private: 
		string a[Height];
	public:
		Page(void);
		Page(string filepath);
		void setLine(int i,string s);
		void print(void);
		void insPic(int x,int y,Pic p);
		void insPicBottom(int x,int y,Pic p);
		void centerInsPic(int i,Pic p);
		void centerInsPic(Pic p);
		void insStr(int x,int y,string s);
		void centerInsStr(int i,string s);
		void out(void);
};
#undef Height
#undef Width
#endif