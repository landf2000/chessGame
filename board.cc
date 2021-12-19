#include "board.h"
#include "empty.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
using namespace std;

Board::Board() {
	//initialize board with empty pieces
	for(int i = 0; i < 8; i++) {
		vector<shared_ptr<Piece>> row(8);
		for(int j = 0; j < 8; j++){
			auto add = make_shared<Empty>(j, i, 'E', nullptr);
			row[j] = add;
		}
		board.emplace_back(row);
	}

	whiteKing = nullptr;
	blackKing = nullptr;
}

void Board::setDefault() {

	//Black Pieces row1 and row2
	vector<shared_ptr<Piece>> row1(8);
	vector<shared_ptr<Piece>> row2(8);
	//White Pieces row7 and row8
	vector<shared_ptr<Piece>> row7(8);
	vector<shared_ptr<Piece>> row8(8);
	//Empty Piece rest of the rows
	vector<shared_ptr<Piece>> row3(8);
	vector<shared_ptr<Piece>> row4(8);
	vector<shared_ptr<Piece>> row5(8);
	vector<shared_ptr<Piece>> row6(8);

	for(int i = 0; i < 8; i++){ //add Black Pawns
		auto add = make_shared<Pawn>(i, 1, 'B', shared_from_this());
		row2[i] = add;
	}

	for(int i = 0; i < 8; i++){ //add White Pawns
		auto add = make_shared<Pawn>(i, 6, 'W', shared_from_this());
		row7[i] = add;
	}

	//ADD BLACK PIECE TO ROW1
	row1[0] = make_shared<Rook>(0, 0, 'B', shared_from_this());
	row1[1] = make_shared<Knight>(1, 0, 'B', shared_from_this());
	row1[2] = make_shared<Bishop>(2, 0, 'B', shared_from_this());
	row1[3] = make_shared<Queen>(3, 0, 'B', shared_from_this());
	row1[4] = make_shared<King>(4, 0, 'B', shared_from_this());
	setKing(row1[4], 'B');
	row1[5] = make_shared<Bishop>(5, 0, 'B', shared_from_this());
	row1[6] = make_shared<Knight>(6, 0, 'B', shared_from_this());
	row1[7] = make_shared<Rook>(7, 0, 'B', shared_from_this());

	//ADD WHITE PIECES TO ROW8
	row8[0] = make_shared<Rook>(0, 7, 'W', shared_from_this());
	row8[1] = make_shared<Knight>(1, 7, 'W', shared_from_this());
	row8[2] = make_shared<Bishop>(2, 7, 'W', shared_from_this());
	row8[3] = make_shared<Queen>(3, 7, 'W', shared_from_this());
	row8[4] = make_shared<King>(4, 7, 'W', shared_from_this());
	setKing(row8[4], 'W');
	row8[5] = make_shared<Bishop>(5, 7, 'W', shared_from_this());
	row8[6] = make_shared<Knight>(6, 7, 'W', shared_from_this());
	row8[7] = make_shared<Rook>(7, 7, 'W', shared_from_this());

	//ADD THE ROWS TO THE BOARD
	board[0] = row1;
	board[1] = row2;
	board[6] = row7;
	board[7] = row8;
}

void Board::addPiece(char type, int x, int y) {
	shared_ptr<Piece> add;

	//checks type for white pieces
	if (type == ' ' || type == '_') {
		add = make_shared<Empty>(x, y, 'E', nullptr);
	} else if (type == 'K'){
		add = make_shared<King>(x, y, 'W', shared_from_this());
		setKing(add, 'W');
	} else if (type == 'Q'){
		add = make_shared<Queen>(x, y, 'W', shared_from_this());
	} else if(type == 'R'){
		add = make_shared<Rook>(x, y, 'W', shared_from_this());
	} else if(type == 'N'){
		add = make_shared<Knight>(x, y, 'W', shared_from_this());
	} else if(type == 'B'){
		add = make_shared<Bishop>(x, y, 'W', shared_from_this());
	} else if(type == 'P'){
		add = make_shared<Pawn>(x, y, 'W', shared_from_this());
	} else if(type == 'k'){ 	//checks type for black pieces
		add = make_shared<King>(x, y, 'B', shared_from_this());
		setKing(add, 'B');
	} else if(type == 'q'){
		add = make_shared<Queen>(x, y, 'B', shared_from_this());
	} else if(type == 'r'){
		add = make_shared<Rook>(x, y, 'B', shared_from_this());
	} else if(type == 'n'){
		add = make_shared<Knight>(x, y, 'B', shared_from_this());
	} else if(type == 'b'){
		add = make_shared<Bishop>(x, y, 'B', shared_from_this());
	} else if(type == 'p'){
		add = make_shared<Pawn>(x, y, 'B', shared_from_this());
	}

	//add the piece to the board

	board[y][x] = add;
}

void Board::removePiece(int x, int y){
	board[y][x] = make_shared<Empty>(x, y, 'E', shared_from_this());
}

void Board::movePiece(int fromX, int fromY, int toX, int toY){
	board[fromY][fromX]->move(toX, toY);
	board[toY][toX] = board[fromY][fromX];
	removePiece(fromX, fromY);
}

bool Board::isCheck(char turn) {
	// check if a king of colour c is checked by any pieces
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if ((board[j][i]->isLegal(getKing('W')->getX(), getKing('W')->getY())) && turn == 'W') {
				return true;
			} else if ((board[j][i]->isLegal(getKing('B')->getX(), getKing('B')->getY())) && turn == 'B') {
				return true;
			}
		}
	}
	return false;
}


string Board::printBoard() {
	string retval = "";
	int y = 8;
	for(int i = 0; i < 8; i++){

		//add y coordinates to retval
		string yCor = to_string(y);
		retval = retval + yCor + " ";
		y--;
		//add board pieces to retval
		for(int j = 0; j < 8; j++){
			retval += board[i][j]->print();
		}
		retval += "\n";
	}
	//add x coordinates to retval
	retval +=  "\n  abcdefgh";
	return retval;
}


string Board::printPiece(int x, int y) {
	return board[y][x]->print();
}


vector<vector<shared_ptr<Piece>>> Board::getBoard() {
	return board;
}


void Board::setKing(shared_ptr<Piece> k, char turn) {
	if (turn == 'W') {
		whiteKing = k;
	} else {
		blackKing = k;
	}
}


shared_ptr<Piece> Board::getKing(char turn) {
	if (turn == 'W') {
		return whiteKing;
	} else {
		return blackKing;
	}
}


bool Board::isCheckmate(char turn){

	if(getKing(turn)->noMoves()) return true;

	return false;
}

bool Board::isStalemate(char turn){

	if(!isCheck(turn)){
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				if((board[i][j]->getColour() == turn) && !(board[i][j]->noMoves())) {
					return false;
				}
		}	}
		return true;
	}else{
		return false;
	}
}


bool Board::isMoveCheck(int oX, int oY, int nX, int nY, char c) {
	shared_ptr<Board> temp = make_shared<Board>();

	for(int i = 0; i < 8; i++) {
		vector<shared_ptr<Piece>> row(8);
		for(int j = 0; j < 8; j++){
			auto add = make_shared<Empty>(j, i, 'E', temp);
			row[j] = add;
		}
		temp->board.emplace_back(row);
	}
	
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			temp->addPiece(board[j][i]->print()[0], board[j][i]->getX(), board[j][i]->getY());
		}
	}
	temp->movePiece(oX, oY, nX, nY);
	if (temp->isCheck(c)) {
		return true;
	}
	return false;
}

void Board::castle(int fromX, int fromY, int toX, int toY){
	movePiece(fromX, fromY, toX, toY);

	if(toX == 6 && toY == 0){
		movePiece(7, 0, fromX, fromY);
	}else if(toX == 2 && toY == 0){
		movePiece(0, 0, fromX, fromY);
	}else if(toX == 6 && toY == 7){
		movePiece(7, 7, fromX, fromY);
	}else if(toX == 2 && toY == 0){
		movePiece(0, 7, fromX, fromY);
	}
	setKing(board[toX][toY], board[toX][toY]->getColour());

}
