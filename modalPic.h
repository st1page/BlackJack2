#ifndef __MODALPIC_H__
#define __MODALPIC_H__

#include "pic.h"
#include <string>
#include <vector>
using namespace std;

class ModalPic: public Pic{
	public:
		ModalPic(int w,int h);
		void setHeader(string s);
		void setFooter(string s);
		void setContent(vector<string> a);
};
#endif