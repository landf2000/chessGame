#ifndef __PIECE__H__
#define __PIECE__H__
#include "board.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Piece{
	bool hasMoved;
	char colour;
	int xPos;
	int yPos;
	shared_ptr<Board> boardObj;

	public:
		~Piece();
		virtual bool isLegal(int x, int y) = 0;
		virtual string print() = 0;
		virtual bool noMoves() = 0;
		virtual void move(int x, int y);
		virtual bool canCastle(int x, int y) = 0;
		//setters
		void setX(int x);
		void setY(int y);
		void setColour(char c);
		//getters
		int getX();
		int getY();
		char getColour();

		shared_ptr<Board> getBoard();
		void setBoard(shared_ptr<Board> b);

		bool getHasMoved();
		void setHasMoved(bool m);
};

#endif
