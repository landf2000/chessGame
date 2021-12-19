#include "king.h"
using namespace std;

King::King(int x, int y, char c, shared_ptr<Board> b) {
	setX(x);
	setY(y);
	setColour(c);
	setBoard(b);
	setHasMoved(false);
}


void King::move(int x, int y) {
	setX(x);
	setY(y);
	setHasMoved(true);
}


bool King::isLegal(int x, int y) {
	int deltaX = abs(x - getX());
	int deltaY = abs(y - getY());

	if ((x == getX() && y == getY()) || (getBoard()->getBoard()[y][x]->getColour() == getColour())) {
		// moving into itself or trying to capture friendly
		return false;
	} else if ((deltaX == 0 || deltaX == 1) && (deltaY == 0 || deltaY == 1)) {
		// move to adjacent block
		return true;
	}
	return false;
}


bool King::canCastle(int x, int y) {
	int kX = getX();
	int kY = getY();
	char c = getColour();
	if(getHasMoved()) return false;
	if(getBoard()->getBoard()[0][0]->print() == "r" && c == 'B'){
		if(getBoard()->getBoard()[0][0]->canCastle(x, y) && y == 0 && x == 2 && !getBoard()->isMoveCheck(kX, kY, x, y, c)){
			return true;

		}
	}
	if(getBoard()->getBoard()[0][7]->print() == "r" && c == 'B'){
		if(getBoard()->getBoard()[0][7]->canCastle(x, y) && y == 0 && x == 6 && !getBoard()->isMoveCheck(kX, kY, x, y, c)){
			return true;

		}
	}
	if(getBoard()->getBoard()[7][0]->print() == "R" && c == 'W'){
		if(getBoard()->getBoard()[7][0]->canCastle(x, y) && y == 7 && x == 2 && !getBoard()->isMoveCheck(kX, kY, x, y, c)){
			return true;

		}
	}
	if(getBoard()->getBoard()[7][7]->print() == "R" && c == 'W'){
		if(getBoard()->getBoard()[7][7]->canCastle(x, y) && y == 7 && x == 6 && !getBoard()->isMoveCheck(kX, kY, x, y, c)){
			return true;

		}
	}
	return false;
}

string King::print(){
	string retval = "";
	if(getColour() == 'B'){
		retval += "k";
	}else{
		retval += "K";
	}
	return retval;
}

bool King::noMoves(){
	int kX = getX();
	int kY = getY();
	int moves = 0;
	char c = getColour();

	if((kX + 1 < 8) && isLegal(kX + 1, kY) && !getBoard()->isMoveCheck(kX, kY, kX + 1, kY, c)) moves++;
	if((kX - 1 >= 0) && isLegal(kX - 1, kY) && !getBoard()->isMoveCheck(kX, kY, kX - 1, kY, c)) moves++;
	if((kY + 1 < 8) && isLegal(kX, kY + 1) && !getBoard()->isMoveCheck(kX, kY, kX, kY + 1, c)) moves++;
	if((kY - 1 >= 0) && isLegal(kX, kY - 1) && !getBoard()->isMoveCheck(kX, kY, kX, kY - 1, c)) moves++;
	if((kY - 1 >= 0) && (kX - 1 >= 0) && isLegal(kX - 1, kY - 1) && !getBoard()->isMoveCheck(kX, kY, kX - 1, kY - 1, c)) moves++;
	if((kY + 1 < 8) && (kX + 1 < 8) && isLegal(kX + 1, kY + 1) && !getBoard()->isMoveCheck(kX, kY, kX + 1, kY + 1, c)) moves++;
	if((kY + 1 < 8) && (kX - 1 >= 0) && isLegal(kX - 1, kY + 1) && !getBoard()->isMoveCheck(kX, kY, kX - 1, kY + 1, c)) moves++;
	if((kY - 1 >= 0) && (kX + 1 < 8) && isLegal(kY - 1, kX + 1) && !getBoard()->isMoveCheck(kX, kY, kX - 1, kY + 1, c)) moves++;

	if(moves > 0) return false;
	return true;
}
