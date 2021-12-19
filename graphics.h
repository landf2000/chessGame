#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "window.h"
#include "board.h"
//#include "piece.h"



class graphicsDisplay {

	Xwindow w{512, 712};
	void drawKing(int r, int c, int pieceColour);
	void drawQueen(int r, int c, int pieceColour);
	void drawBishop(int r, int c, int pieceColour);
	void drawKnight(int r, int c, int pieceColour);
	void drawPawn(int r, int c, int pieceColour);
	void drawRook(int r, int c, int pieceColour);


	public:
	graphicsDisplay();

	void drawBoard(shared_ptr<Board> b);
	void drawStalemate();
	void drawCheck(std::string turn);
	void drawCheckmate(std::string turn);
	void drawResign(std::string turn);
};

#endif
