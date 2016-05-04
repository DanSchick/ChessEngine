//
// Created by Danny on 4/21/2016.
//

#include <iostream>
#include <algorithm>
#include "Board.h"
#include "pieces/Rook.h"
#include "pieces/Knight.h"
#include "pieces/Bishop.h"
#include "pieces/Queen.h"
#include "pieces/King.h"
#include "pieces/Pawn.h"
#include "AIController.h"

Board::Board() {
    // populate with the 2nd dimension vector
    for(int i=0;i<8;i++) {
        board[i] = vector<Piece*>(8);
    }
    /** ------------ FIRST ROW -------------- */
    board[0][0] = new Rook(true, 0, 0);
    whitePieces.insert(whitePieces.end(),board[0][0]);
    board[1][0] = new Knight(true, 1, 0);
    whitePieces.insert(whitePieces.end(),board[1][0]);
    board[2][0] = new Bishop(true, 2, 0);
    whitePieces.insert(whitePieces.end(),board[2][0]);
    board[3][0] = new Queen(true, 3, 0);
    whitePieces.insert(whitePieces.end(),board[3][0]);
    board[4][0] = new King(true, 4, 0);
    whitePieces.insert(whitePieces.end(),board[4][0]);
    board[5][0] = new Bishop(true, 5, 0);
    whitePieces.insert(whitePieces.end(),board[5][0]);
    board[6][0] = new Knight(true, 6, 0);
    whitePieces.insert(whitePieces.end(),board[6][0]);
    board[7][0] = new Rook(true, 7, 0);
    whitePieces.insert(whitePieces.end(),board[7][0]);

    /** ------------ SECOND ROW -------------- */
    for(int i=0;i<8;i++){
        board[i][1] = new Pawn(true, i, 1);
        whitePieces.insert(whitePieces.end(),board[i][1]);
    }


    /** ------------ SIXTH ROW -------------- */
    for(int i=0;i<8;i++){
        board[i][6] = new Pawn(false, i, 6);
        blackPieces.insert(blackPieces.end(),board[i][6]);
    }

    /** ------------ SEVENTH ROW -------------- */
    board[0][7] = new Rook(false, 0, 7);
    blackPieces.insert(blackPieces.end(),board[0][7]);
    board[1][7] = new Knight(false, 1, 7);
    blackPieces.insert(blackPieces.end(),board[1][7]);
    board[2][7] = new Bishop(false, 2, 7);
    blackPieces.insert(blackPieces.end(),board[2][7]);
    board[3][7] = new Queen(false, 3, 7);
    blackPieces.insert(blackPieces.end(), board[3][7]);
    board[4][7] = new King(false, 4, 7);
    blackPieces.insert(blackPieces.end(),board[4][7]);
    board[5][7] = new Bishop(false, 5, 7);
    blackPieces.insert(blackPieces.end(),board[5][7]);
    board[6][7] = new Knight(false, 6, 7);
    blackPieces.insert(blackPieces.end(),board[6][7]);
    board[7][7] = new Rook(false, 7, 7);
    blackPieces.insert(blackPieces.end(),board[7][7]);
}


void Board::print() {
    cout << "   A B C D E F G H " << endl;
    cout << "   --------------- " << endl;
    for(int i=7;i>=0;i--){
        cout << i+1 << "| ";
        for(int j=0;j<8;j++){
            if(board[j][i] == NULL){
                    cout << '-' << ' ';
            } else {
                cout << board[j][i]->getName() << ' ';
            }
        }
        cout << "|" << i+1 << endl;
    }
    cout << "   --------------- " << endl;
    cout << "   A B C D E F G H " << endl;

    if(!whiteCaptured.empty()){
        cout << "W: ";
        for(Piece* p : whitePieces){
            cout << p->getName() << " ";
        }
        cout << endl;
        cout << "Captured White Pieces: ";
        for(Piece* p : whiteCaptured){
            cout << p->getName();
        }
        cout << endl;
    }
    if(!blackCaptured.empty()){
        cout << "Captured Black Pieces: ";
        for(Piece* p : blackCaptured){
            cout << p->getName();
        }
        cout << endl;
    }
}

int Board::move(vector<int> from, vector<int> to, bool verifyOnly) {
    //TODO: make sure move can't be made in a check
    Piece* movePiece = board[from[0]][from[1]];
    if(movePiece == NULL){
//        cout << "Invalid Piece specified" << endl;
        return 1;
    }
    if(movePiece->isWhite != this->whitesTurn){
//        cout << "It's not that piece's turn!" << endl;
        return 4;
    }
    int moveStatus = movePiece->legalMove(to, board);
    if(moveStatus == 1){
//        cout << "Invalid destination" << endl;
        return 1;
    } else if(moveStatus == 2){
//        cout << "a piece is blocking the way";
        return 1;
    }

    if(moveStatus == 0){
        // we move the piece
        // check if there's a capture
        movePiece->setPos(to);
        if(board[to[0]][to[1]] != NULL && movePiece->isWhite != board[to[0]][to[1]]->isWhite){
            Piece* captured = board[to[0]][to[1]];
            // there's a capture
            vector<Piece*> pieceList;
            if(captured->isWhite){
                pieceList = whitePieces;
                whiteCaptured.insert(whiteCaptured.end(), captured);
                captured->capture();
                whiteCount -= 1;
            } else {
                pieceList = blackPieces;
                blackCaptured.insert(blackCaptured.end(), captured);
                captured->capture();
                blackCount -= 1;
            }


//            for(int i=0;i<pieceList.size();i++){
//                if(pieceList[i] == captured){
//                    pieceList.erase(pieceList.begin() + i);
//                }
//
//            }

            board[to[0]][to[1]] = movePiece;
            board[from[0]][from[1]] = NULL;
            return 0;

        } else {
            board[to[0]][to[1]] = movePiece;
            board[from[0]][from[1]] = NULL;
            return 0;
        }
    }

    else{
        return 1;
    }

}





int Board::inputMove(string input) {
    vector<int> firstCoords = vector<int>(2);
    vector<int> secondCoords = vector<int>(2);

    vector<int> curStr = vector<int>();

    // will change to false after we take the first square from user
    bool firstPos = true;


    for(char c : input){
        if (curStr.size() < 2) {
            if(c != '-') {
                if(isdigit(c)){
                    // we need to convert from the ASCII value of the int to the actual int
                    int g;
                    g = c-48; // this gives us the actual number
                    g = g - 1; // then we subtract one, because our board starts at 0 not 1
                    curStr.insert(curStr.end(), g);
                } else {
                    int i;
                    i = getIntValFromChar(c);
                    curStr.insert(curStr.end(), i);
                }
            }
        } else {
            if (firstPos) {
                firstCoords[0] = curStr[0];
                firstCoords[1] = curStr[1];
                firstPos = false;
            }
            curStr.clear();
        }

    }

    secondCoords[0] = curStr[0];
    secondCoords[1] = curStr[1];

    // make a move and return the validity of move to the game loop
    int status;
    status = move(firstCoords, secondCoords, false);
    if(status == 0){
        return 0;
    } else {
        return 1;
    }
}





int Board::getIntValFromChar(char c) {
    // simple switch to get the right board value from the char
    switch(c){
        case 'a': return 0;
        case 'b': return 1;
        case 'c': return 2;
        case 'd': return 3;
        case 'e': return 4;
        case 'f': return 5;
        case 'g': return 6;
        case 'h': return 7;
        default: return -1;
    }
}

Piece* Board::getPieceCopy(Piece *curPiece) {
    switch(curPiece->getID()){
        case 0:
            return new Bishop(curPiece->isWhite, curPiece->getX(), curPiece->getY());
        case 1:
            return  new King(curPiece->isWhite, curPiece->getX(), curPiece->getY());
        case 2:
            return  new Knight(curPiece->isWhite, curPiece->getX(), curPiece->getY());
        case 3:
            return  new Pawn(curPiece->isWhite, curPiece->getX(), curPiece->getY());
        case 4:
            return  new Queen(curPiece->isWhite, curPiece->getX(), curPiece->getY());
        case 5:
            return  new Rook(curPiece->isWhite, curPiece->getX(), curPiece->getY());
    }
}

vector<Piece*> Board::copyPieceVector(vector<Piece *> vec) {
    vector<Piece*> returnVec = vector<Piece*>();
    for(Piece* p : vec){
        returnVec.insert(returnVec.end(), getPieceCopy(p));
    }
    delete &vec;
    return returnVec;
}

Board::~Board() {
//    delete &board;
//    delete &whiteCaptured;
//    delete &blackCaptured;
//    delete &whitePieces;
//    delete &blackPieces;
}