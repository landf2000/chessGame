#include "rook.h"
using namespace std;

Rook::Rook(int x, int y, char c, shared_ptr<Board> b) {
	setX(x);
	setY(y);
	setColour(c);
	setBoard(b);
	setHasMoved(false);
}


void Rook::move(int x, int y) {
	setX(x);
	setY(y);
	setHasMoved(true);
}


bool Rook::canCastle(int x, int y) {
	int rX = getX();
	char c = getColour();
	if(!getHasMoved()){

		//check if theres no pieces in between king and rook
		if(c == 'B'){
			if(rX == 0){
				for(int i = 1; i < 4; i++){
					if(getBoard()->getBoard()[0][i]->getColour() != 'E') return false;
				}
			}
			if(rX == 7){
				for(int i = 6; i > 4; i--){
					if(getBoard()->getBoard()[0][i]->getColour() != 'E') return false;
				}
			}
		}
		//check if theres no pieces in between king and rook
		if(c == 'W'){
			if(rX == 0){
				for(int i = 1; i < 4; i++){
					if(getBoard()->getBoard()[7][i]->getColour() != 'E') return false;
				}
			}
			if(rX == 7){
				for(int i = 6; i > 4; i--){
					if(getBoard()->getBoard()[7][i]->getColour() != 'E') return false;
				}
			}
		}
	}

	return true;
}


bool Rook::isLegal(int x, int y) {
	/*if ((getBoard()->getBoard()[y][x]->print() == "k" || getBoard()->getBoard()[y][x]->print() == "K") && getBoard()->getBoard()[y][x]->getColour() == getColour()
			&& !getHasMoved() && !(getBoard()->isCheck(getColour()))) {
  } else */if ((x == getX() && y == getY()) || getBoard()->getBoard()[y][x]->getColour() == getColour()) {
		// move into itself or trying to capture friendly
		return false;
	} else if (x == getX() && y < getY()) {
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
	return false;
}

string Rook::print() {
	string retval = "";
	if(getColour() == 'B'){
		retval += "r";
	}else{
		retval += "R";
	}
	return retval;
}


bool Rook::noMoves(){
	int rX = getX();
	int rY = getY();
	int moves = 0;
	char c = getColour();

	//check moves to the right
	for(int x = rX + 1; x < 8; x++){
		if(isLegal(x, rY) && !getBoard()->isMoveCheck(rX, rY, x, rY, c)) moves++;
	}

	//check moves to the left
	for(int x = rX - 1; x >= 0; x--){
		if(isLegal(x, rY) && !getBoard()->isMoveCheck(rX, rY, x, rY, c)) moves++;
	}

	//check moves up
	for(int y = rY + 1; y < 8; y++){
		if(isLegal(rX, y) && !getBoard()->isMoveCheck(rX, rY, rX, y, c)) moves++;
	}

	//check moves down
	for(int y = rY - 1; y >= 8; y--){
		if(isLegal(rX, y) && !getBoard()->isMoveCheck(rX, rY, rX, y, c)) moves++;
	}

	if(moves > 0) return false;
	return true;
}
