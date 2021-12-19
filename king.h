#ifndef __KING__H__
#define __KING__H__
#include "piece.h"
using namespace std;

class King : public Piece {
	public:
		King(int x, int y, char c, shared_ptr<Board> b);
		void move(int x, int y) override;
		bool canCastle(int x, int y);
		bool noMoves() override;
		bool isLegal(int x, int y) override;
		string print() override;
};

#endif
