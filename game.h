#ifndef __GAME__H
#define __GAME__H
#include <memory>
#include <string>
#include "graphics.h"
using namespace std;

class Board;

class Game{

	protected:
	shared_ptr<Board> b;
	float whiteWins;
	float blackWins;
	bool whiteInCheck;
	bool blackInCheck;
	char turn;
	graphicsDisplay d;

	public:
		bool noGame;
		~Game();
		Game();
		void setup();
		void startGame();
		void resign();
		string translate(char, int);
		void doTurn();
		string printGame();


};
#endif
