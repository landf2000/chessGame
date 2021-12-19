#include "bishop.h"
using namespace std;

Bishop::Bishop(int x, int y, char c, shared_ptr<Board> b) {
	setX(x);
	setY(y);
	setColour(c);
	setBoard(b);
	setHasMoved(false);
}

bool Bishop::canCastle(int x, int y){
	return false;
}

bool Bishop::isLegal(int x, int y) {
	int deltaX = abs(x - getX());
	int deltaY = abs(y - getY());

	if ((deltaX != deltaY) || (x == getX() && y == getY()) || getBoard()->getBoard()[y][x]->getColour() == getColour()) {
		// non diagonal move or capturing friendly
		return false;
	} else if (x > getX() && y > getY()) {
		for (int i = 1; i < deltaX; ++i) {
			if (getBoard()->getBoard()[getY() + i][getX() + i]->print() != " " && getBoard()->getBoard()[getY() + i][getX() + i]->print() != "_") {
				return false;
			}
		}
		return true;
	} else if (x > getX() && y < getY()) {
		for (int i = 1; i < deltaX; ++i) {
			if (getBoard()->getBoard()[getY() - i][getX() + i]->print() != " " && getBoard()->getBoard()[getY() - i][getX() + i]->print() != "_") {
				return false;
			}
		}
		return true;
	} else if (x < getX() && y < getY()) {
		for (int i = 1; i < deltaX; ++i) {
			if (getBoard()->getBoard()[getY() - i][getX() - i]->print() != " " && getBoard()->getBoard()[getY() - i][getX() - i]->print() != "_") {
				return false;
			}
		}
		return true;
	} else if (x < getX() && y > getY()) {
		for (int i = 1; i < deltaX; ++i) {
			if (getBoard()->getBoard()[getY() + i][getX() - i]->print() != " " && getBoard()->getBoard()[getY() + i][getX() - i]->print() != "_") {
				return false;
			}
		}
		return true;
	}
	return false;
}

string Bishop::print() {
	string retval = "";
	if(getColour() == 'B'){
		 retval += "b";
	}else{
		retval += "B";
	}
	return retval;
}

bool Bishop::noMoves(){
	int bX = getX();
	int bY = getY();
	int moves = 0;
	char c = getColour();

	for(int x = bX + 1 , y = bY + 1; x < 8 && y < 8; x++, y++){
		if(isLegal(x, y) && !getBoard()->isMoveCheck(bX, bY, x, y, c)) moves++;
	}

	for(int x = bX + 1, y = bY - 1; x < 8 && y >= 0; x++, y--){
		if(isLegal(x, y) && !getBoard()->isMoveCheck(bX, bY, x, y, c)) moves++;
	}

	for(int x = bX - 1, y = bY - 1; x >=0  && y >= 0; x--, y--){
		if(isLegal(x, y) && !getBoard()->isMoveCheck(bX, bY, x, y, c)) moves++;
	}

	for(int x = bX - 1, y = bY + 1; x >= 0 && y < 8; x--, y++){
		if(isLegal(x, y) && !getBoard()->isMoveCheck(bX, bY, x, y, c)) moves++;
	}

	if(moves > 0) return false;

	return true;
}
