//
// Created by schic on 5/3/2016->
//

#include "AnalysisBoard.h"
#include "pieces/Rook.h"
#include "pieces/Bishop.h"
#include "pieces/King.h"
#include "pieces/Knight.h"
#include "pieces/Pawn.h"
#include "pieces/Queen.h"
#include "Piece.h"


AnalysisBoard::AnalysisBoard(Board* given) {
    whiteKing = given->whiteKing;
    blackKing = given->blackKing;
    whiteCount = given->whiteCount;
    blackCount = given->blackCount;
    blackCheckmated = given->blackCheckmated;
    whiteCheckmated = given->whiteCheckmated;
    blackInCheck = given->blackInCheck;
    whiteInCheck = given->whiteInCheck;
    whitesTurn = given->whitesTurn;
    //TODO: not going to work-> We need to make sure that the pieces in *Pieces and *Captured are the same
    whiteCaptured = given->whiteCaptured;
    blackCaptured = given->blackCaptured;
//    for(int i=0;i<8;i++) {
//        board[i] = vector<Piece*>(8);
//    }


    // loop through each real game square for a deep copy
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            Piece* curPiece = given->board[i][j];
            if(curPiece == NULL){
                board[i][j] = NULL;
            } else {
                switch(curPiece->getID()){
                    case 0:
                        board[i][j] = new Bishop(curPiece->isWhite, curPiece->getX(), curPiece->getY());
                        break;
                    case 1:
                        board[i][j] = new King(curPiece->isWhite, curPiece->getX(), curPiece->getY());
                        break;
                    case 2:
                        board[i][j] = new Knight(curPiece->isWhite, curPiece->getX(), curPiece->getY());
                        break;
                    case 3:
                        board[i][j] = new Pawn(curPiece->isWhite, curPiece->getX(), curPiece->getY());
                        break;
                    case 4:
                        board[i][j] = new Queen(curPiece->isWhite, curPiece->getX(), curPiece->getY());
                        break;
                    case 5:
                        board[i][j] = new Rook(curPiece->isWhite, curPiece->getX(), curPiece->getY());
                        break;
                }
            }
        }
    }
//    delete given;
}