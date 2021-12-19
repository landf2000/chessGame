#include "piece.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"
#include "empty.h"
#include "game.h"
#include <string>
#include <iostream>
#include <memory>
#include "board.h"
using namespace std;

int main(){

	string command;
	string playerWhite;
	string playerBlack;
	auto g = make_shared<Game>();


	while (!cin.eof()){
		cin >> command;
		
		//if command is game take in two more inputs for players
		if(command == "game"){
			cin >> playerWhite;
			cin >> playerBlack;
			//check if players are humans and start a human vs human game
			if(playerWhite == "human" && playerBlack == "human"){
				if(g->noGame){
					g->startGame();
				}
				cout << g->printGame() << endl;
				g->doTurn();
			}else{
				cout << "wrong player parameters, try again" << endl;
			}
		//if command is setup call setup
		}else if((command == "setup") && (g->noGame)){
			cout << "Entered setup mode" << endl;
			g->setup();
			cout << "Setup complete" << endl;
		//else invalid command
		} else{
			cout << "Invalid command, try again" << endl;
		}
	}

}
