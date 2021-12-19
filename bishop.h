#ifndef __BISHOP__H__
#define __BISHOP__H__
#include "piece.h"
using namespace std;

class Bishop : public Piece{
	public:
		Bishop(int x, int y, char c, shared_ptr<Board> b);
		bool isLegal(int x, int y) override;
		string print() override;
		bool noMoves() override;
		bool canCastle(int x, int y) override;
};
#endif
