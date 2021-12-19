#include "knight.h"
using namespace std;

Knight::Knight(int x, int y, char c, shared_ptr<Board> b) {
	setX(x);
	setY(y);
	setColour(c);
	setBoard(b);
	setHasMoved(false);
}

bool Knight::isLegal(int x, int y){
	int deltaX = abs(x - getX());
	int deltaY = abs(y - getY());

	if (((deltaX == 2 && deltaY == 1) || (deltaX == 1 && deltaY == 2)) &&
			getBoard()->getBoard()[y][x]->getColour() != getColour()) {
				return true;
	}
	return false;
}

string Knight::print(){
	string retval = "";
	if(getColour() == 'B'){
		retval += "n";
	}else{
		retval += "N";
	}
	return retval;
}

bool Knight::noMoves(){
	int nX = getX();
	int nY = getY();
	int moves = 0;
	char c = getColour();


	//move right and down
	if((nX + 2 < 8) && (nY + 1 < 8) && isLegal(nX + 2, nY + 1) && !getBoard()->isMoveCheck(nX, nY, nX + 2, nY + 1, c)) moves++;
	//move right and up
	if((nX + 2 < 8) && (nY - 1 >= 0) && isLegal(nX + 2, nY - 1) && !getBoard()->isMoveCheck(nX, nY, nX + 2, nY - 1, c)) moves++;
	//move left and down
	if((nX - 2 >= 0) && (nY + 1 < 8) && isLegal(nX - 2, nY + 1) && !getBoard()->isMoveCheck(nX, nY, nX - 2, nY + 1, c)) moves++;
	//move left and up
	if((nX - 2 >= 0) && (nY - 1 >= 0) && isLegal(nX + 2, nY - 1) && !getBoard()->isMoveCheck(nX, nY, nX + 2, nY - 1, c)) moves++;
	//move up and right
	if((nX + 1 < 8) && (nY - 2 >= 0) && isLegal(nX + 1, nY - 2) && !getBoard()->isMoveCheck(nX, nY, nX + 1, nY - 2, c)) moves++;
	//move down and right
	if((nX + 1 < 8) && (nY + 2 < 8) && isLegal(nX + 1, nY + 2) && !getBoard()->isMoveCheck(nX, nY, nX + 1, nY + 2, c)) moves++;
	//move up and left
	if((nX - 1 >= 0) && (nY - 2 >= 0) && isLegal(nX - 1, nY - 2) && !getBoard()->isMoveCheck(nX, nY, nX - 1, nY - 2, c)) moves++;
	//move down and left
	if((nX - 1 >= 0) && (nY + 2 < 8) && isLegal(nX - 1, nY + 2) && !getBoard()->isMoveCheck(nX, nY, nX - 1, nY + 2, c)) moves++;

	if(moves > 0) return false;

	return true;
}

bool Knight::canCastle(int x, int y){
	return false;
}
