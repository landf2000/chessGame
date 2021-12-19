#include "pawn.h"

Pawn::Pawn(int x, int y, char c, shared_ptr<Board> b) {
	setX(x);
	setY(y);
	setColour(c);
	setBoard(b);
	setHasMoved(false);
}


void Pawn::move(int x, int y) {
	setX(x);
	setY(y);
	setHasMoved(true);
}


void Pawn::enPassant(){
	setHasMoved(false);
	// do something
}


bool Pawn::isLegal(int x, int y){
	int deltaX = abs(x - getX());
	int deltaY = abs(y - getY());
	int halfY = (y + getY()) / 2; // midway point of movement


	if ((getColour() == 'B' && y < getY()) || (getColour() == 'W' && y > getY())) {
		// prevent moving backwards as pawns can only go forward
		return false;
	} else if (deltaX == 1 && deltaY == 1 && (getBoard()->getBoard()[y][x]->getColour() != getColour()) &&
							(getBoard()->getBoard()[y][x]->getColour() != 'E')) {
		// capture diagonally
		return true;
  } else if (deltaY == 2 && !getHasMoved() && deltaX == 0 && (getBoard()->getBoard()[y][x]->getColour() == 'E') &&
							(getBoard()->getBoard()[halfY][x]->getColour() == 'E')) {
		// move forward 2 spaces if not moved and area is clear
		return true;
	} else if (deltaY == 1 && deltaX == 0 && (getBoard()->getBoard()[y][x]->getColour() == 'E')) {
		// move forward 1
		return true;
		}
	return false;
}

string Pawn::print(){
	string retval = "";
	if(getColour() == 'B'){
		retval += "p";
	}else{
		retval += "P";
	}
	return retval;
}


bool Pawn::noMoves(){
	int pX = getX();
	int pY = getY();
	int moves = 0;
	char c = getColour();

	if((pY + 1 < 8) && isLegal(pX, pY + 1) && !getBoard()->isMoveCheck(pX, pY, pX, pY + 1, c)) moves++;
	if((pY - 1 >= 0) && isLegal(pX, pY - 1) && !getBoard()->isMoveCheck(pX, pY, pX, pY - 1, c)) moves++;
	if((pY + 1 < 8) && (pX + 1 < 8) && isLegal(pX + 1, pY + 1) && !getBoard()->isMoveCheck(pX, pY, pX + 1, pY + 1, c)) moves++;
	if((pY + 1 < 8) && (pX - 1 >= 0) && isLegal(pX + 1, pY - 1) && !getBoard()->isMoveCheck(pX, pY, pX + 1, pY - 1, c)) moves++;
	if((pY - 1 >= 0) && (pX + 1 < 8) && isLegal(pX + 1, pY - 1) && !getBoard()->isMoveCheck(pX, pY, pX + 1, pY - 1, c)) moves++;
	if((pY - 1 >= 0) && (pX - 1 >= 0) && isLegal(pX - 1, pY - 1) && !getBoard()->isMoveCheck(pX, pY, pX - 1, pY - 1, c)) moves++;

	if(moves > 0) return false;

	return true;
}

bool Pawn::canCastle(int x, int y){
	return false;
}
