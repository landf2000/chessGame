#ifndef __BOARD__H__
#define __BOARD__H__
#include <vector>
#include <string>
#include <memory>
using namespace std;

class Piece;

class Board : public enable_shared_from_this<Board> {
	shared_ptr<Piece> whiteKing;
	shared_ptr<Piece> blackKing;
	vector<vector<shared_ptr<Piece>>> board;

	public:
		Board();
		void setDefault();

		string printBoard();
		string printPiece(int x, int y);

		void addPiece(char type, int x, int y);
		void removePiece(int x, int y);
		void movePiece(int fromX, int fromY, int toX, int toY);
		void castle(int fromX, int fromY, int toX, int toY);
		vector<vector<shared_ptr<Piece>>> getBoard();

		void setKing(shared_ptr<Piece> k, char turn);
		shared_ptr<Piece> getKing(char turn);

		bool isCheck(char turn);
		bool isCheckmate(char turn);
		bool isStalemate(char turn);
		bool isMoveCheck(int oX, int oY, int nX, int nY, char c);

};

#endif
