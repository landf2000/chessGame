#include "board.h"
#include "game.h"
#include "piece.h"
#include <sstream>
using namespace std;

Game::Game(): b{make_shared<Board>()}, whiteWins{0}, blackWins{0},whiteInCheck{false}, blackInCheck{false}, turn{'W'}, noGame{true}{}

void Game::setup(){
	int whiteKing = 0;
	int blackKing = 0;
	int invPawn = 0;
	string command;
	string validTypes = "K k Q q N n P p R r B b";
	string temp1 = "a1 a2 a3 a4 a5 a6 a7 a8 b1 b2 b3 b4 b5 b6 b7 b8 c1 c2 c3 c4 c5 c6 c7 c8 d1 d2 d3 d4 d5 d6 d7 d8";
	string temp2 = "e1 e2 e3 e4 e5 e6 e7 e8 f1 f2 f3 f4 f5 f6 f7 f8 g1 g2 g3 g4 g5 g6 g7 g8 h1 h2 h3 h4 h5 h6 h7 h8";
	string validCoordinates = temp1 + temp2;
	while(!cin.eof()){

		cin >> command;

		if(command == "+"){
			string parameters;
			getline(cin , parameters);
			istringstream input(parameters);
			string type = "";
			string coordinate = "";
			input >> type;
			input >> coordinate;
			if(type == "" || coordinate == "" || parameters.size() > 5 ){
				cout << "Invalid parameters to add piece" << endl;
				type = "";
				coordinate ="";

			//if coordinates and piece type is valid

			}else if((validCoordinates.find(coordinate) != std::string::npos) && (validTypes.find(type) != std::string::npos) && (coordinate.size() == 2)){

				if(type == "K") whiteKing++;
				if(type == "k") blackKing++;

				if(((type != "k") && (type != "K")) || (type == "k" && !(blackKing > 1)) || (type == "K" && !(whiteKing > 1))){
					//Translate the coordinates (e1 to 40)
					int y = coordinate[1] - '0';
					coordinate = translate(coordinate[0], y);
					y = coordinate[1] - '0';
					int x = coordinate[0] - '0';

					//check if pawn is placed in valid location
					if(((type == "P") || (type == "p")) && ((y == 0) || (y == 7))) invPawn++;

					//check if king is being replaced and decrement
					if(b->printPiece(x, y) == "K") whiteKing--;
					if(b->printPiece(x, y) == "k") blackKing--;
					//check if Pawn is being replaced and the location is invalid and decrement
					if(((b->printPiece(x, y) == "P") || (b->printPiece(x, y) == "p")) && ((y == 7) || (y == 0))) invPawn--;

					//check if type is valid and then call addPiece
					b->addPiece(type[0], x, y);
					type = "";
					coordinate = "";
					cout << printGame() << endl;
				}else{
					cout << "trying to add more than one king" << endl;
					type = "";
					coordinate = "";
				}
			}else{
				cout << "Wrong type of Piece or invalid location" << endl;
				type = "";
				coordinate = "";
			}

		}else if(command == "-"){
			string parameters;
			getline(cin , parameters);
			istringstream input(parameters);
			string coordinate = "";	
			input >> coordinate;

			if(coordinate == "" || parameters.size() > 3){
				cout << "invalid parameters to remove piece" << endl;
				coordinate = "";
			

			//check if the coordinate we want to remove is valid
			}else if((validCoordinates.find(coordinate) != std::string::npos) && (coordinate.size() == 2)){

				int y = coordinate[1] - '0';
				coordinate = translate(coordinate[0], y);
				y = coordinate[1] - '0';
				int x = coordinate[0] - '0';

				//if invalid pawn is removed decrement invPawn
				if(((b->printPiece(x, y) == "P") || (b->printPiece(x, y) == "p")) && ((y == 7) || (y == 0))) invPawn--;
				//if King is removed decrement king
				if(b->printPiece(x, y) == "K") whiteKing--;
				if(b->printPiece(x, y) == "k") blackKing--;

				b->removePiece(x, y);
				cout << printGame() << endl;
				coordinate = "";
			}else{
				cout << "Invalid location" << endl;
				coordinate = "";
			}
		}else if(command == "="){
			string parameters;
			getline(cin , parameters);
			istringstream input(parameters);
			string colour = "";	
			input >> colour;
			
			if(colour == "" || parameters.size() > 6){
				cout << "invalid parameter to change turn" << endl;
				colour = "";
			}else if(colour == "black"){
				turn = 'B';
				colour = "";
				cout << "turn is set to Black" << endl;
			}else if(colour == "white"){
				turn = 'W';
				colour = "";
				cout << "turn is set to White" << endl;
			}else{
				cout << "Invalid colour" << endl;
				colour = "";
			}

		}else if((command == "done") && (whiteKing > 0) && (blackKing > 0) && (invPawn == 0) && !(b->isCheck('B')) && !(b->isCheck('W'))){
			noGame = false;
			break;
		}else if(command == "done"){
			if(whiteKing == 0){
				cout << "White king missing" << endl;
			}
			if(blackKing == 0){
				cout << "Black king missing" << endl;
			}
			if(invPawn > 0){
				cout << "Invalid Pawn location" << endl;
			}
			if(b->isCheck('B')){
				cout << "Black king in check" << endl;
			}
			if(b->isCheck('W')){
				cout << "White king in check" << endl;
			}
			cout << "Setup incomplete" << endl;
		}else{
			cout << "Invalid command, try again" << endl;
			cout << "valid commands: +, -, =, done" << endl;
		}
	}
}

void Game::startGame(){
	//starts game
	b->setDefault();
	noGame = false;
}

void Game::resign(){
	//ends game and increments the other players win counter
	if(turn == 'B'){
		 whiteWins++;
		 cout << "White wins!" << endl;
		 d.drawResign("White");
	}else{
		cout << "Black wins!" << endl;
		d.drawResign("Black");
		blackWins++;
	}
	b = make_shared<Board>();
	turn = 'W';
	noGame = true;
}


string Game::translate(char xCoor, int yCoor){
	int x , y;
	string coordinates;

	//converts 8,7,6... to 0,1,2...
	y = 8 - yCoor;

	//converts a,b,c... to 0,1,2...
	x = xCoor - 'a';

	coordinates = to_string(x) + to_string(y);

	return coordinates;
}

void Game::doTurn(){
	string temp1 = "a1 a2 a3 a4 a5 a6 a7 a8 b1 b2 b3 b4 b5 b6 b7 b8 c1 c2 c3 c4 c5 c6 c7 c8 d1 d2 d3 d4 d5 d6 d7 d8";
	string temp2 = "e1 e2 e3 e4 e5 e6 e7 e8 f1 f2 f3 f4 f5 f6 f7 f8 g1 g2 g3 g4 g5 g6 g7 g8 h1 h2 h3 h4 h5 h6 h7 h8";
	string validCoordinates = temp1 + temp2;
	string pieceCoor;
	string newCoor;
	string promote = "";
	string command;

	if(turn == 'B') cout <<  "Black player's turn" << endl;
	else cout << "White player's turn" << endl;

	string move;
	cin.ignore();
	while(getline(cin, move)){
		if(move == "resign"){
			resign();
			break;
		}

		//check for stalemate on each turn
		if(b->isStalemate(turn)){
			whiteWins += 0.5;
			blackWins += 0.5;
			cout << "Stalemate! Game is a draw" << endl;
			d.drawStalemate();
			break;
		}

		istringstream input(move);
		input >> command;
		if(move.size() > 12){
			cout << "invalid parameters for move" << endl;
			promote = "";
		}else if(command == "move"){
			input >> pieceCoor;
			input >> newCoor;
			input >> promote;

			//check if newCoor and pieceCoor are valid
			if((validCoordinates.find(pieceCoor) != std::string::npos) && (pieceCoor.size() == 2) &&
					(validCoordinates.find(newCoor) != std::string::npos) && (newCoor.size() == 2)){

				//Translate pieceCoor (e1 to 40)
				int pY = pieceCoor[1] - '0';
				pieceCoor = translate(pieceCoor[0], pY);
				pY = pieceCoor[1] - '0';
				int pX = pieceCoor[0] - '0';

				//Translate newCoor (e1 to 40)
				int nY = newCoor[1] - '0';
				newCoor = translate(newCoor[0], nY);
				nY = newCoor[1] - '0';
				int nX = newCoor[0] - '0';

				string type = b->getBoard()[pY][pX]->print();
				char colour = b->getBoard()[pY][pX]->getColour();


				//if we are not promoting
				if(promote == ""){
					//check if the Piece is empty
					//
					if((type != " ") && (type != "_") && (colour == turn)){

						//check if king wants to castle
						if((type == "K" || type == "k") && (b->getKing(turn)->canCastle(nX, nY))){
							b->castle(pX, pY, nX, nY);
							cout << printGame() << endl;

						//check if the move on piece at pieceCoor is legal and does not put king into check
						}else if(b->getBoard()[pY][pX]->isLegal(nX, nY) && !b->isMoveCheck(pX, pY, nX, nY, turn)){

							//then movePiece
							b->movePiece(pX, pY, nX, nY);
							cout << printGame() << endl;


							//change turn
							if (turn == 'B') turn = 'W';
							else turn = 'B';

							if (b->isCheck('W') && turn == 'W') {
								whiteInCheck = true;
								cout << "White is in check." << endl;
								d.drawCheck("White");
							} else {
								if (turn == 'W') whiteInCheck = false;
							}

							if (b->isCheck('B') && turn == 'B') {
								blackInCheck = true;
								cout << "Black is in check." << endl;
								d.drawCheck("Black");
							} else {
								if (turn == 'B') blackInCheck = false;
							}

							if(turn == 'W' && whiteInCheck && b->isCheckmate(turn)){
								cout << "Checkmate! Black Wins!" << endl;	
								blackWins++;
								d.drawCheckmate("Black");
								break;
							} 
							if(turn == 'B' && blackInCheck && b->isCheckmate(turn)) {
								cout << "Checkmate! White Wins!" << endl;
								whiteWins++;
								d.drawCheckmate("White");
								break;
							}


						//if move is not legal try again
						} else {
							cout << "invalid move" << endl;
						}

					}else{
						//trying to move empty piece
						cout << "Trying to move opponents piece or invalid piece, try again" << endl;
					}
				}else{
					//check if promote is valid
					if(promote.size() == 1){

						//check if promoting to the right piece (white to white)
						if (((promote == "Q") || (promote == "R") || (promote == "N") || (promote == "B")) && (turn == 'W') && (type == "P")) {
							//check if pawn is moving to the last row and the move isLegal
							if((nY == 0) && (b->getBoard()[pY][pX]->isLegal(nX, nY) && !b->isMoveCheck(pX, pY, nX, nY, turn))){
								//move the piece
								b->movePiece(pX, pY, nX, nY);
								//add the new piece that the pawn will be converted to
								b->addPiece(promote[0], nX, nY);
								promote = "";
								cout << printGame() << endl;
								turn = 'B';
								if (b->isCheck('B')) {
									blackInCheck = true;
									cout << "Black is in check." << endl;
									d.drawCheck("Black");
								} else {
									blackInCheck = false;
								}

								if(blackInCheck && b->isCheckmate(turn)) {
									cout << "Checkmate! White Wins!" << endl;
									whiteWins++;
									d.drawCheckmate("White");
									break;
								}
							}else{
								cout << "invalid move" << endl;
							}
						}

						//check if promoting to the right piece (black to black)
						else if (((promote == "q") || (promote == "r") || (promote == "n") || (promote == "b")) && (turn == 'B') && (type == "p")) {

							//check if pawn is moving to the last row and the move isLegal
							if((nY == 7) && (b->getBoard()[pY][pX]->isLegal(nX, nY) && !b->isMoveCheck(pX, pY, nX, nY, turn))){
								//move the piece
								b->movePiece(pX, pY, nX, nY);
								//add the new piece that the pawn will be converted to
								b->addPiece(promote[0], nX, nY);
								promote = "";
								cout << printGame() << endl;
								turn = 'W';
								if (b->isCheck('W')) {
									whiteInCheck = true;
									cout << "White is in check." << endl;
									d.drawCheck("White");
								} else {
									whiteInCheck = false;
								}


								if(whiteInCheck && b->isCheckmate(turn)){
									cout << "Checkmate! Black Wins!" << endl;	
									blackWins++;
									d.drawCheckmate("Black");
									break;
								} 
							}else{
								cout << "invalid promote move" << endl;
								promote = "";
							}
						}else{
							cout << "failed to promote, try again" << endl;
							promote = "";
						}
					}else{
						cout << "invalid promote parameter, try again" << endl;
						promote = "";
					}
				}
			}else{
				//invalid coordinates
				cout << "invalid coordinates, try again" << endl;
				promote = "";
			}
		
			if(turn == 'B') cout <<  "Black player's turn" << endl;
			else cout << "White player's turn" << endl;

		}else{
			cout << "Invalid command, try using -move" << endl;
			promote = "";
		}

	}
}

string Game::printGame(){
	d.drawBoard(b);
	return b->printBoard();

}

Game::~Game(){
	cout << "Final Score:" << endl;
	cout << "White: " << whiteWins << endl;
	cout << "Black: " << blackWins << endl;
}
