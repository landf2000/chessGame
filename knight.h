#ifndef __KNIGHT__H__
#define __KNIGHT__H__
#include "piece.h"
using namespace std;

class Knight : public Piece{
	public:
		Knight(int x, int y, char c, shared_ptr<Board> b);
		bool isLegal(int x, int y) override;
		string print() override;
		bool noMoves() override;
		bool canCastle(int x, int y) override;

};
#endif
