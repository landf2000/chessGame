#include "empty.h"
using namespace std;

Empty::Empty(int x, int y, char c, shared_ptr<Board> b){
	setX(x);
	setY(y);
	setColour('E');
	setBoard(b);
}


bool Empty::isLegal(int x, int y){
	return false;
}

string Empty::print(){
	string retval = "";
	if((getX() % 2) == (getY() % 2)){
		retval += " "; //blank for white tile
	}else{
		retval += "_"; // underscore for black tile
	}
	return retval;
}

bool Empty::noMoves(){
	return true;
}

bool Empty::canCastle(int x, int y){
	return false;
}
