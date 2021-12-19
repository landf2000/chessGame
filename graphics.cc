#include "graphics.h"
#include "piece.h"

using namespace std;


graphicsDisplay::graphicsDisplay() {
	for (int x = 0;x < 8;x++) {
		for (int y = 0;y < 8;y++) {
			if (((x + y) % 2) == 0) {
				w.fillRectangle(x * 64, y * 64, 64, 64, Xwindow::White);
			} else {
				w.fillRectangle(x * 64, y * 64, 64, 64, Xwindow::Black);
			}
		}
	}
}

void graphicsDisplay::drawKing(int r, int c, int pieceColour) {
	int colour;
	if ((r + c) % 2 == 0) {
		colour = Xwindow::Black;
	} else {
		colour = Xwindow::White;
	}

	XPoint points[17];
	XPoint p1;
	p1.x = (c * 64) + 23;
	p1.y = (r * 64) + 30;

	XPoint p2;
	p2.x = (c * 64) + 30;
	p2.y = (r * 64) + 30;

	XPoint p3;
	p3.x = (c * 64) + 30;
	p3.y = (r * 64) + 20;

	XPoint p4;
	p4.x = (c * 64) + 25;
	p4.y = (r * 64) + 20;

	XPoint p5;
	p5.x = (c * 64) + 25;
	p5.y = (r * 64) + 15;

	XPoint p6;
	p6.x = (c * 64) + 30;
	p6.y = (r * 64) + 15;

	XPoint p7;
	p7.x = (c * 64) + 30;
	p7.y = (r * 64) + 10;

	XPoint p8;
	p8.x = (c * 64) + 35;
	p8.y = (r * 64) + 10;

	XPoint p9;
	p9.x = (c * 64) + 35;
	p9.y = (r * 64) + 15;

	XPoint p10;
	p10.x = (c * 64) + 40;
	p10.y = (r * 64) + 15;

	XPoint p11;
	p11.x = (c * 64) + 40;
	p11.y = (r * 64) + 20;

	XPoint p12;
	p12.x = (c * 64) + 35;
	p12.y = (r * 64) + 20;

	XPoint p13;
	p13.x = (c * 64) + 35;
	p13.y = (r * 64) + 30;

	XPoint p14;
	p14.x = (c * 64) + 42;
	p14.y = (r * 64) + 30;

	XPoint p15;
	p15.x = (c * 64) + 42;
	p15.y = (r * 64) + 50;

	XPoint p16;
	p16.x = (c * 64) + 23;
	p16.y = (r * 64) + 50;


	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
	points[3] = p4;
	points[4] = p5;
	points[5] = p6;
	points[6] = p7;
	points[7] = p8;
	points[8] = p9;
	points[9] = p10;
	points[10] = p11;
	points[11] = p12;
	points[12] = p13;
	points[13] = p14;
	points[14] = p15;
	points[15] = p16;
	points[16] = p1;

	w.fillPolygon(points, 17, Convex, pieceColour);
	w.drawLines(points, 17, colour);


}

void graphicsDisplay::drawQueen(int r, int c, int pieceColour) {
	int colour;
	if ((r + c) % 2 == 0) {
		colour = Xwindow::Black;
	} else {
		colour = Xwindow::White;
	}

	XPoint points[12];
	XPoint p1;
	p1.x = (c * 64) + 20;
	p1.y = (r * 64) + 54;

	XPoint p2;
	p2.x = (c * 64) + 25;
	p2.y = (r * 64) + 44;

	XPoint p3;
	p3.x = (c * 64) + 20;
	p3.y = (r * 64) + 24;

	XPoint p4;
	p4.x = (c * 64) + 25;
	p4.y = (r * 64) + 34;

	XPoint p5;
	p5.x = (c * 64) + 28;
	p5.y = (r * 64) + 20;

	XPoint p6;
	p6.x = (c * 64) + 32;
	p6.y = (r * 64) + 34;

	XPoint p7;
	p7.x = (c * 64) + 37;
	p7.y = (r * 64) + 20;

	XPoint p8;
	p8.x = (c * 64) + 40;
	p8.y = (r * 64) + 34;

	XPoint p9;
	p9.x = (c * 64) + 45;
	p9.y = (r * 64) + 24;

	XPoint p10;
	p10.x = (c * 64) + 40;
	p10.y = (r * 64) + 44;

	XPoint p11;
	p11.x = (c * 64) + 45;
	p11.y = (r * 64) + 54;

	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
	points[3] = p4;
	points[4] = p5;
	points[5] = p6;
	points[6] = p7;
	points[7] = p8;
	points[8] = p9;
	points[9] = p10;
	points[10] = p11;
	points[11] = p1;

	w.fillPolygon(points, 12, Complex, pieceColour);
	w.drawLines(points, 12, colour);
}

void graphicsDisplay::drawBishop(int r, int c, int pieceColour) {
	int colour;
	if ((r + c) % 2 == 0) {
		colour = Xwindow::Black;
	} else {
		colour = Xwindow::White;
	}

	XPoint points[14];
	XPoint p1;
	p1.x = (c * 64) + 25;
	p1.y = (r * 64) + 54;

	XPoint p2;
	p2.x = (c * 64) + 30;
	p2.y = (r * 64) + 44;

	XPoint p3;
	p3.x = (c * 64) + 25;
	p3.y = (r * 64) + 34;

	XPoint p4;
	p4.x = (c * 64) + 30;
	p4.y = (r * 64) + 24;

	XPoint p5;
	p5.x = (c * 64) + 33;
	p5.y = (r * 64) + 19;

	XPoint p6;
	p6.x = (c * 64) + 35;
	p6.y = (r * 64) + 24;

	XPoint p7;
	p7.x = (c * 64) + 33;
	p7.y = (r * 64) + 31;

	XPoint p8;
	p8.x = (c * 64) + 34;
	p8.y = (r * 64) + 33;

	XPoint p9;
	p9.x = (c * 64) + 37;
	p9.y = (r * 64) + 28;

	XPoint p10;
	p10.x = (c * 64) + 40;
	p10.y = (r * 64) + 34;

	XPoint p11;
	p11.x = (c * 64) + 35;
	p11.y = (r * 64) + 44;

	XPoint p12;
	p12.x = (c * 64) + 40;
	p12.y = (r * 64) + 54;


	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
	points[3] = p4;
	points[4] = p5;
	points[5] = p6;
	points[6] = p7;
	points[7] = p8;
	points[8] = p9;
	points[9] = p10;
	points[10] = p11;
	points[11] = p12;
	points[12] = p1;

	w.fillPolygon(points, 13, Complex, pieceColour);
	w.drawLines(points, 13, colour);
}

void graphicsDisplay::drawRook(int r, int c, int pieceColour) {
	int colour;
	if ((r + c) % 2 == 0) {
		colour = Xwindow::Black;
	} else {
		colour = Xwindow::White;
	}

	XPoint points[21];
	XPoint p1;
	p1.x = (c * 64) + 20;
	p1.y = (r * 64) + 54;

	XPoint p2;
	p2.x = (c * 64) + 20;
	p2.y = (r * 64) + 49;

	XPoint p3;
	p3.x = (c * 64) + 25;
	p3.y = (r * 64) + 44;

	XPoint p4;
	p4.x = (c * 64) + 25;
	p4.y = (r * 64) + 34;

	XPoint p5;
	p5.x = (c * 64) + 20;
	p5.y = (r * 64) + 29;

	XPoint p6;
	p6.x = (c * 64) + 20;
	p6.y = (r * 64) + 24;

	XPoint p7;
	p7.x = (c * 64) + 25;
	p7.y = (r * 64) + 24;

	XPoint p8;
	p8.x = (c * 64) + 25;
	p8.y = (r * 64) + 29;

	XPoint p9;
	p9.x = (c * 64) + 30;
	p9.y = (r * 64) + 29;

	XPoint p10;
	p10.x = (c * 64) + 30;
	p10.y = (r * 64) + 24;

	XPoint p11;
	p11.x = (c * 64) + 35;
	p11.y = (r * 64) + 24;

	XPoint p12;
	p12.x = (c * 64) + 35;
	p12.y = (r * 64) + 29;

	XPoint p13;
	p13.x = (c * 64) + 40;
	p13.y = (r * 64) + 29;

	XPoint p14;
	p14.x = (c * 64) + 40;
	p14.y = (r * 64) + 24;

	XPoint p15;
	p15.x = (c * 64) + 45;
	p15.y = (r * 64) + 24;

	XPoint p16;
	p16.x = (c * 64) + 45;
	p16.y = (r * 64) + 29;

	XPoint p17;
	p17.x = (c * 64) + 40;
	p17.y = (r * 64) + 34;

	XPoint p18;
	p18.x = (c * 64) + 40;
	p18.y = (r * 64) + 44;

	XPoint p19;
	p19.x = (c * 64) + 45;
	p19.y = (r * 64) + 49;

	XPoint p20;
	p20.x = (c * 64) + 45;
	p20.y = (r * 64) + 54;



	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
	points[3] = p4;
	points[4] = p5;
	points[5] = p6;
	points[6] = p7;
	points[7] = p8;
	points[8] = p9;
	points[9] = p10;
	points[10] = p11;
	points[11] = p12;
	points[12] = p13;
	points[13] = p14;
	points[14] = p15;
	points[15] = p16;
	points[16] = p17;
	points[17] = p18;
	points[18] = p19;
	points[19] = p20;
	points[20] = p1;

	w.fillPolygon(points, 21, Complex, pieceColour);
	w.drawLines(points, 21, colour);
}

void graphicsDisplay::drawPawn(int r, int c, int pieceColour) {
	int colour;
	if ((r + c) % 2 == 0) {
		colour = Xwindow::Black;
	} else {
		colour = Xwindow::White;
	}

	XPoint points[11];
	XPoint p1;
	p1.x = (c * 64) + 25;
	p1.y = (r * 64) + 54;

	XPoint p2;
	p2.x = (c * 64) + 29;
	p2.y = (r * 64) + 39;

	XPoint p3;
	p3.x = (c * 64) + 30;
	p3.y = (r * 64) + 34;

	XPoint p4;
	p4.x = (c * 64) + 28;
	p4.y = (r * 64) + 32;

	XPoint p5;
	p5.x = (c * 64) + 30;
	p5.y = (r * 64) + 29;

	XPoint p6;
	p6.x = (c * 64) + 35;
	p6.y = (r * 64) + 29;

	XPoint p7;
	p7.x = (c * 64) + 37;
	p7.y = (r * 64) + 32;

	XPoint p8;
	p8.x = (c * 64) + 35;
	p8.y = (r * 64) + 34;

	XPoint p9;
	p9.x = (c * 64) + 36;
	p9.y = (r * 64) + 39;

	XPoint p10;
	p10.x = (c * 64) + 40;
	p10.y = (r * 64) + 54;




	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
	points[3] = p4;
	points[4] = p5;
	points[5] = p6;
	points[6] = p7;
	points[7] = p8;
	points[8] = p9;
	points[9] = p10;
	points[10] = p1;

	w.fillPolygon(points, 11, Convex, pieceColour);
	w.drawLines(points, 11, colour);
}

void graphicsDisplay::drawKnight(int r, int c, int pieceColour) {
	int colour;
	if ((r + c) % 2 == 0) {
		colour = Xwindow::Black;
	} else {
		colour = Xwindow::White;
	}

	XPoint points[19];
	XPoint p1;
	p1.x = (c * 64) + 20;
	p1.y = (r * 64) + 54;

	XPoint p2;
	p2.x = (c * 64) + 26;
	p2.y = (r * 64) + 48;

	XPoint p3;
	p3.x = (c * 64) + 26;
	p3.y = (r * 64) + 42;

	XPoint p4;
	p4.x = (c * 64) + 22;
	p4.y = (r * 64) + 36;

	XPoint p5;
	p5.x = (c * 64) + 20;
	p5.y = (r * 64) + 27;

	XPoint p6;
	p6.x = (c * 64) + 22;
	p6.y = (r * 64) + 19;

	XPoint p7;
	p7.x = (c * 64) + 27;
	p7.y = (r * 64) + 15;

	XPoint p8;
	p8.x = (c * 64) + 35;
	p8.y = (r * 64) + 9;

	XPoint p9;
	p9.x = (c * 64) + 35;
	p9.y = (r * 64) + 14;

	XPoint p10;
	p10.x = (c * 64) + 41;
	p10.y = (r * 64) + 18;

	XPoint p11;
	p11.x = (c * 64) + 46;
	p11.y = (r * 64) + 25;

	XPoint p12;
	p12.x = (c * 64) + 50;
	p12.y = (r * 64) + 29;

	XPoint p13;
	p13.x = (c * 64) + 48;
	p13.y = (r * 64) + 32;

	XPoint p14;
	p14.x = (c * 64) + 41;
	p14.y = (r * 64) + 31;

	XPoint p15;
	p15.x = (c * 64) + 43;
	p15.y = (r * 64) + 37;

	XPoint p16;
	p16.x = (c * 64) + 44;
	p16.y = (r * 64) + 42;

	XPoint p17;
	p17.x = (c * 64) + 44;
	p17.y = (r * 64) + 48;

	XPoint p18;
	p18.x = (c * 64) + 50;
	p18.y = (r * 64) + 54;




	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
	points[3] = p4;
	points[4] = p5;
	points[5] = p6;
	points[6] = p7;
	points[7] = p8;
	points[8] = p9;
	points[9] = p10;
	points[10] = p11;
	points[11] = p12;
	points[12] = p13;
	points[13] = p14;
	points[14] = p15;
	points[15] = p16;
	points[16] = p17;
	points[17] = p18;
	points[18] = p1;


	w.fillPolygon(points, 19, Complex, pieceColour);
	w.drawLines(points, 19, colour);
}


void graphicsDisplay::drawBoard(shared_ptr<Board> b) {
	w.fillRectangle(0, 512, 512, 200, Xwindow::White);
	for (int x = 0;x < 8;x++) {
		for (int y = 0;y < 8;y++) {
			if (((x + y) % 2) == 0) {
				w.fillRectangle(x * 64, y * 64, 64, 64, Xwindow::White);
			} else {
				w.fillRectangle(x * 64, y * 64, 64, 64, Xwindow::Black);
			}
		}
	}
	for (int x = 0;x < 8;++x) {
		for (int y = 0;y < 8;++y) {
			if (b->getBoard()[x][y]->print() == "k") {
				drawKing(b->getBoard()[x][y]->getY(), b->getBoard()[x][y]->getX(), Xwindow::Black);
			} else if (b->getBoard()[x][y]->print() == "K") {
				drawKing(b->getBoard()[x][y]->getY(), b->getBoard()[x][y]->getX(), Xwindow::White);
			} else if (b->getBoard()[x][y]->print() == "q") {
				drawQueen(b->getBoard()[x][y]->getY(), b->getBoard()[x][y]->getX(), Xwindow::Black);
			} else if (b->getBoard()[x][y]->print() == "Q") {
				drawQueen(b->getBoard()[x][y]->getY(), b->getBoard()[x][y]->getX(), Xwindow::White);
			} else if (b->getBoard()[x][y]->print() == "b") {
				drawBishop(b->getBoard()[x][y]->getY(), b->getBoard()[x][y]->getX(), Xwindow::Black);
			} else if (b->getBoard()[x][y]->print() == "B") {
				drawBishop(b->getBoard()[x][y]->getY(), b->getBoard()[x][y]->getX(), Xwindow::White);
			} else if (b->getBoard()[x][y]->print() == "n") {
				drawKnight(b->getBoard()[x][y]->getY(), b->getBoard()[x][y]->getX(), Xwindow::Black);
			} else if (b->getBoard()[x][y]->print() == "N") {
				drawKnight(b->getBoard()[x][y]->getY(), b->getBoard()[x][y]->getX(), Xwindow::White);
			} else if (b->getBoard()[x][y]->print() == "r") {
				drawRook(b->getBoard()[x][y]->getY(), b->getBoard()[x][y]->getX(), Xwindow::Black);
			} else if (b->getBoard()[x][y]->print() == "R") {
				drawRook(b->getBoard()[x][y]->getY(), b->getBoard()[x][y]->getX(), Xwindow::White);
			} else if (b->getBoard()[x][y]->print() == "p") {
				drawPawn(b->getBoard()[x][y]->getY(), b->getBoard()[x][y]->getX(), Xwindow::Black);
			} else if (b->getBoard()[x][y]->print() == "P") {
				drawPawn(b->getBoard()[x][y]->getY(), b->getBoard()[x][y]->getX(), Xwindow::White);
			}
		}
	}
}

void graphicsDisplay::drawStalemate() {
	w.fillRectangle(0, 512, 512, 200, Xwindow::White);
	w.drawString(256, 612, "Stalemate!");
}

void graphicsDisplay::drawCheck(string turn) {
	w.fillRectangle(0, 512, 512, 200, Xwindow::White);
	w.drawString(256, 612, turn + " is in check.");
}

void graphicsDisplay::drawCheckmate(string turn) {
	w.fillRectangle(0, 512, 512, 200, Xwindow::White);
	w.drawString(256, 612, "Checkmate! " + turn + " wins!");
}

void graphicsDisplay::drawResign(string turn) {
	w.fillRectangle(0, 512, 512, 200, Xwindow::White);
	w.drawString(256, 612, turn + " wins!");
}
