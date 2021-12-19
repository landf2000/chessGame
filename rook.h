#ifndef __ROOK__H__
#define __ROOK__H__
#include "piece.h"
using namespace std;

class Rook : public Piece{
	public:
		Rook(int x, int y, char c, shared_ptr<Board> b);
		bool isLegal(int x, int y) override;
		string print() override;
		void move(int x, int y) override;
		bool noMoves() override;
		bool canCastle(int x, int y);
};
#endif
