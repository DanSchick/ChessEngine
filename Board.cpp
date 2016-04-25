//
// Created by Danny on 4/21/2016.
//

#include <iostream>
#include "Board.h"
#include "pieces/Rook.h"
#include "pieces/Knight.h"
#include "pieces/Bishop.h"
#include "pieces/Queen.h"
#include "pieces/King.h"
#include "pieces/Pawn.h"

Board::Board() {
    // populate with the 2nd dimension vector
    for(int i=0;i<8;i++) {
        board[i] = vector<Piece*>(8);
    }
    /** ------------ FIRST ROW -------------- */
    board[0][0] = new Rook(true, 0, 0);
    board[1][0] = new Knight(true, 1, 0);
    board[2][0] = new Bishop(true, 2, 0);
    board[3][0] = new Queen(true, 3, 0);
    board[4][0] = new King(true, 4, 0);
    board[5][0] = new Bishop(true, 5, 0);
    board[6][0] = new Knight(true, 6, 0);
    board[7][0] = new Rook(true, 7, 0);

    /** ------------ SECOND ROW -------------- */
    for(int i=0;i<8;i++){
        board[i][1] = new Pawn(true, i, 1);
    }


    /** ------------ SIXTH ROW -------------- */
    for(int i=0;i<8;i++){
        board[i][6] = new Pawn(true, i, 6);
    }

    /** ------------ SEVENTH ROW -------------- */
    board[0][7] = new Rook(true, 0, 7);
    board[1][7] = new Knight(true, 1, 7);
    board[2][7] = new Bishop(true, 2, 7);
    board[3][7] = new Queen(true, 3, 7);
    board[4][7] = new King(true, 4, 7);
    board[5][7] = new Bishop(true, 5, 7);
    board[6][7] = new Knight(true, 6, 7);
    board[7][7] = new Rook(true, 7, 7);
}

void Board::print() {
    for(int i=7;i>=0;i--){
        for(int j=7;j>=0;j--){
            if(board[j][i] == NULL){
                cout << '_' << ' ';
            } else {
                cout << board[j][i]->getName() << ' ';
            }
        }
        cout << endl;
    }
}

int Board::move(vector<int> from, vector<int> to) {
    Piece* movePiece = board[from[0]][from[1]];
    if(movePiece == NULL){
        cout << "Invalid Piece specified" << endl;
        return 1;
    }
    int moveStatus = movePiece->legalMove(to, board);
    if(moveStatus == 1){
        cout << "Invalid destination" << endl;
        return 1;
    } else if(moveStatus == 2){
        cout << "a piece is blocking the way";
        return 1;
    }

    if(moveStatus == 0){
        // we move the piece
        // check if there's a capture
        if(board[to[0]][to[1]] != NULL){
            // there's a capture
            captured.insert(captured.end(), board[to[0]][to[1]]);
            board[to[0]][to[1]] = movePiece;
            board[from[0]][from[1]] = NULL;
            return 0;

        } else {
            board[to[0]][to[1]] = movePiece;
            board[from[0]][from[1]] = NULL;
            return 0;
        }
    }

}

int Board::inputMove(string input) {
    vector<char> firstCoords = vector<char>(2);
    vector<char> secondCoords = vector<char>(2);

    vector<char> curStr = vector<char>();

    // will change to false after we take the first square from user
    bool firstPos = true;

    cout << "flag" << endl;

    for(char c : input){
        cout << c << endl;
        if (curStr.size() < 2) {
            if(c != '-') {
                curStr.insert(curStr.end(), c);
            }
        } else {
            if (firstPos) {
                firstCoords[0] = curStr[0];
                firstCoords[1] = curStr[1];
                firstPos = false;
            } else {
                secondCoords[0] = curStr[0];
                secondCoords[1] = curStr[1];
            }
            curStr.clear();
        }


    }
    for(int i=0;i<2;i++){
        cout << "flag" << endl;
        cout << "first " << i << " " << firstCoords[i] << endl;
        cout << "second " << i << " " << secondCoords[i] << endl;


    }

    return 0;






}