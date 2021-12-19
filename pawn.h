#ifndef __PAWN__H__
#define __PAWN__H__
#include "piece.h"
#include <iostream>
#include <string>

class Pawn : public Piece{
	public:
		Pawn(int x, int y, char c, shared_ptr<Board> b);
		void enPassant();
		bool isLegal(int x, int y) override;
		string print() override;
		void move(int x, int y) override;
		bool noMoves() override;
		bool canCastle(int x, int y) override;
};

#endif
