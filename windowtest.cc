#include <iostream>
//#include "window.h"
#include "graphics.h"

using namespace std;


int main() {
	graphicsDisplay d;

	d.drawKing(3, 4, Xwindow::Blue);
	d.drawKing(3, 3, Xwindow::Blue);
	d.drawQueen(5, 5, Xwindow::Blue);
	d.drawQueen(5, 6, Xwindow::Blue);
	d.drawBishop(7, 5, Xwindow::Blue);
	d.drawBishop(7, 6, Xwindow::Blue);
	d.drawRook(1, 5, Xwindow::Blue);
	d.drawRook(1, 6, Xwindow::Blue);
	d.drawPawn(2, 5, Xwindow::Blue);
	d.drawPawn(2, 6, Xwindow::Blue);
	d.drawKnight(3, 5, Xwindow::Blue);
	d.drawKnight(3, 6, Xwindow::Blue);


	//Xwindow w2(199, 199);
 	//w2.drawBigString(50, 100, "ABCD", Xwindow::Black);


 	//w.fillPolygon(200, 200, 5, 50, 1, Xwindow::Red);
 	//w.showAvailableFonts();
 	char c;
 	cin >> c;

}
