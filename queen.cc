#include "queen.h"
using namespace std;

Queen::Queen(int x, int y, char c, shared_ptr<Board> b) {
	setX(x);
	setY(y);
	setColour(c);
	setBoard(b);
	setHasMoved(false);
}

bool Queen::isLegal(int x, int y) {
	int deltaX = abs(x - getX());
	int deltaY = abs(y - getY());

	if ((x == getX() && y == getY()) || (getBoard()->getBoard()[y][x]->getColour() == getColour())) {
		// moving into itself or trying to capture friendly
		return false;
	} else if (deltaX == deltaY) {
		// diagonal movement
		if (x > getX() && y > getY()) {
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
	} else if (getX() == x || getY() == y) {
		// horizontal/verical movement
		if (x == getX() && y < getY()) {
			for (int i = y + 1; i < getY(); ++i) {
				if (getBoard()->getBoard()[i][x]->print() != " " && getBoard()->getBoard()[i][x]->print() != "_") {
					return false;
				}
			}
			return true;
		} else if (x == getX() && y > getY()) {
			for (int i = getY() + 1; i < y; ++i) {
				if (getBoard()->getBoard()[i][x]->print() != " " && getBoard()->getBoard()[i][x]->print() != "_") {
					return false;
				}
			}
			return true;
		} else if (y == getY() && x < getX()) {
			for (int i = x + 1; i < getX(); ++i) {
				if (getBoard()->getBoard()[y][i]->print() != " " && getBoard()->getBoard()[y][i]->print() != "_") {
					return false;
				}
			}
			return true;
		} else if (y == getY() && x > getX()) {
			for (int i = getX() + 1; i < x; ++i) {
				if (getBoard()->getBoard()[y][i]->print() != " " && getBoard()->getBoard()[y][i]->print() != "_") {
					return false;
				}
			}
			return true;
		}
	}
	return false;
}

string Queen::print() {
	string retval = "";
	if(getColour() == 'B'){
		retval += "q";
	}else{
		retval += "Q";
	}
	return retval;
}

bool Queen::noMoves(){
	int qX = getX();
	int qY = getY();
	int moves = 0;
	char c = getColour();

	//check moves to the right
	for(int x = qX + 1; x < 8; x++){
		if(isLegal(x, qY) && !getBoard()->isMoveCheck(qX, qY, x, qY, c)) moves++;
	}

	//check moves to the left
	for(int x = qX - 1; x >= 0; x--){
		if(isLegal(x, qY) && !getBoard()->isMoveCheck(qX, qY, x, qY, c)) moves++;
	}

	//check moves up
	for(int y = qY + 1; y < 8; y++){
		if(isLegal(qX, y) && !getBoard()->isMoveCheck(qX, qY, qX, y, c)) moves++;
	}

	//check moves down
	for(int y = qY - 1; y >= 8; y--){
		if(isLegal(qX, y) && !getBoard()->isMoveCheck(qX, qY, qX, y, c)) moves++;
	}

	for(int x = qX + 1 , y = qY + 1; x < 8 && y < 8; x++, y++){
		if(isLegal(x, y) && !getBoard()->isMoveCheck(qX, qY, x, y, c)) moves++;
	}

	for(int x = qX + 1, y = qY - 1; x < 8 && y >= 0; x++, y--){
		if(isLegal(x, y) && !getBoard()->isMoveCheck(qX, qY, x, y, c)) moves++;
	}

	for(int x = qX - 1, y = qY - 1; x >=0  && y >= 0; x--, y--){
		if(isLegal(x, y) && !getBoard()->isMoveCheck(qX, qY, x, y, c)) moves++;
	}

	for(int x = qX - 1, y = qY + 1; x >= 0 && y < 8; x--, y++){
		if(isLegal(x, y) && !getBoard()->isMoveCheck(qX, qY, x, y, c)) moves++;
	}

	if(moves > 0) return false;

	return true;
}

bool Queen::canCastle(int x, int y){
	return false;
}
