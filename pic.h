#ifndef __PIC_H__
#define __PIC_H__

#include <string>
#include <vector>

using namespace std;
class Pic{
	protected: 
		int width,height;
		vector<string> a;
	public:
		Pic(int w,int h);
		Pic(string filepath);
		int getWidth();
		int getHeight();
		vector<string> getA();
		void insStr(int x,int y,string s);
		void centerInsStr(int i,string s);
		string getLine(int i);
		void setLine(int i,string s); // i:[0,hegiht)
		Pic operator +(Pic &other);
		void debug();
};
#endif