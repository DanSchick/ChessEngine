//
// Created by schic on 5/2/2016.
//

#include <iostream>
#include <algorithm>
#include <limits>
#include "AIController.h"
#include "AnalysisBoard.h"



AIController::AIController() {
    controlWhite = false;
}

AIController::AIController(bool isWhite, Board givenGame) {
    controlWhite = isWhite;
}

int AIController::evaluateBlackMaterial(Board b){
    int materialValue = 0;

    for(vector<Piece*> vec : b.board){
        for(Piece* p : vec){
            if(p != NULL && !p->isWhite){
                materialValue += p->getVal();
            }
        }
    }
    return materialValue;
}


int AIController::evaluateWhiteMaterial(Board b) {
    int materialValue = 0;

    for(vector<Piece*> vec : b.board){
        for(Piece* p : vec){
            if(p != NULL && p->isWhite){
                materialValue += p->getVal();
            }
        }
    }
    return materialValue;
}

int AIController::evaluate(Board b) {
    // gives a general board evaluation
    // higher the better
    int materialWeight = evaluateBlackMaterial(b) + evaluateWhiteMaterial(b);

    int numWhite = 0;
    int numBlack = 0;
    for(vector<Piece*> vec : b.board){
        for(Piece* p : vec){
            if(p != NULL && p->isWhite){
                numWhite++;
            } else if( p!= NULL && !p->isWhite){
                numBlack++;
            }
        }
    }
    int numPieceDifference = (numWhite - numBlack);
    int whoToMove;
    if(b.whitesTurn){
        whoToMove = 1;
    } else {
        whoToMove = -1;
    }

    int result = materialWeight * numPieceDifference * whoToMove;
    return result;
}

Board AIController::getBestMove(Board b) {

    vector<Board> possibleMoves = moveGenerator(b);
    vector<vector<Piece*>> bestMove = vector<vector<Piece*>>();
    Board bestBoard;

    int maxScore = -std::numeric_limits<int>::max();
//    int alpha = -std::numeric_limits<int>::max();
//    int beta = std::numeric_limits<int>::max();

    for(Board move : possibleMoves){
        int score = -negaMax(move, DEPTH);
        move.print();
        cout << "White Material Value: " << evaluateWhiteMaterial(move) << endl;
        cout << "Black Material Value: " << evaluateBlackMaterial(move) << endl;
        //TODO: problem is right here. Score does not match up with board evaluation
        cout << "Board Eval: " << evaluate(move) << endl;
        cout << "Score: " << score << endl;
        if(score > maxScore){
            bestBoard = move;
            maxScore = score;
        }
    }
    return bestBoard;
}

// ALPHA BETA ---------------------------------------------------------
//int AIController::negaMax(Board* b, int depth, int alpha, int beta) {
//    if(depth > maxDepth) return evaluate(b);
//    int max = -std::numeric_limits<int>::max();
//    for(vector<vector<Piece*>> move : moveGenerator(b)){
//        Board* c = new AnalysisBoard(b);
//        c->board = move;
//        int score = -negaMax(c, depth+1, -beta, -alpha);
//        if(score > max){
//            max = score;
//        } if(score > alpha){
//            alpha = score;
//        } if(alpha >= beta){
//            return alpha;
//        }
//    }
//    return max;
//
//
//}


// ----------- OLD VERSION THAT WORKS ---------------
int AIController::negaMax(Board b, int depth) {
    if(depth == 0) return evaluate(b);
    int max = -std::numeric_limits<int>::max();
    for(Board move : moveGenerator(b)){
        Board c = AnalysisBoard(move);
        int score = -negaMax(c, depth -1);
        if(score > max){
            max = score;
        }
    }
    return max;


}

vector<Board> AIController::moveGenerator(Board givenGame) {
    vector<Piece*> pieceList;
//    if(givenGame->whitesTurn){
//        pieceList = givenGame->whitePieces;
//    } else {
//        pieceList = givenGame->blackPieces;
//    }

    for(vector<Piece*> vec : givenGame.board){
        for(Piece* p : vec){
            if(p != NULL){
                pieceList.insert(pieceList.begin(), p);
            }
        }
    }
    // vector of boards that have made valid moves
    vector<Board> moveList = vector<Board>();
    Board curBoard;
    // so the problem is that curBoard does a shallow copy of it's parameter's board

    for(Piece* p : pieceList) {
        // check to make sure p is not captured
        if (!p->isCaptured()) {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {

                    curBoard = AnalysisBoard(givenGame);
                    vector<int> checkCoords = vector<int>(2);

                    checkCoords[0] = i;
                    checkCoords[1] = j;

                    int moveStatus = curBoard.move(p->getPos(), checkCoords, true);
                    if (moveStatus == 0) {
//                        curBoard->print();
                        moveList.insert(moveList.end(), curBoard);
                    }

                }
            }
        }
    }
    return moveList;
}
