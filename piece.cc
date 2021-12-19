#include "piece.h"
using namespace std;

Piece::~Piece(){}

void Piece::move(int x, int y) {
	setX(x);
	setY(y);
}

void Piece::setX(int x){
	xPos = x;
}

void Piece::setY(int y){
	yPos = y;
}

void Piece::setColour(char c){
	colour = c;
}

void Piece::setBoard(shared_ptr<Board> b) {
	boardObj = b;
}

shared_ptr<Board> Piece::getBoard() {
	return boardObj;
}

int Piece::getX(){
	return xPos;
}

int Piece::getY(){
	return yPos;
}

char Piece::getColour(){
	return colour;
}


bool Piece::getHasMoved() {
	return hasMoved;
}


void Piece::setHasMoved(bool m) {
	hasMoved = m;
}

