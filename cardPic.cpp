#include "cardPic.h"

string pattern[5][6] ={
	{	".------.",
		"| _  _ |",
		"|( \\/ )|",
		"| \\  / |",
		"|  \\/  |",
		"`------'"  },
	{	".------.",
		"|  /\\  |",
		"| /  \\ |",
		"| \\  / |",
		"|  \\/  |",
		"`------'"  },
	{	".------.",
		"|  _   |",
		"| ( )  |",
		"|(_x_) |",
		"|  Y   |",
		"`------'"  },
	{	".------.",
		"|  .   |",
		"| / \\  |",
		"|(_,_) |",
		"|  I   |",
		"`------'"  }, 
	{	".------.",
		"|xxxxxx|",
		"|xxxxxx|",
		"|xxxxxx|",
		"|xxxxxx|",
		"`------'"  },  };


const int x1 = 1, y1 = 1;
const int x2 = 4, y2 = 6;
CardPic::CardPic(void):Pic(8, 6){
	for(int i=0;i<6;i++) setLine(i, pattern[4][i]);
}
CardPic::CardPic(Card x):Pic(8, 6){
	int ptn = x.getPattern();
	string fig = x.getFigureS();
	for(int i=0;i<6;i++) setLine(i, pattern[ptn][i]);	
	insStr(x1, y1, fig);
	if( fig.size() == 2) insStr(x2, y2-1, fig);
	else insStr(x2, y2, fig);
}
int CardPic::getKey(void){
	return key;
}
/*
int main(){
	for(int i=0;i<4;i++) {
		for(int j=0;j<6;j++) cout<<pattern[i][j]<<endl;
		cout<<endl;
	}

}*/ 