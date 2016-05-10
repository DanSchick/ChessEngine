//
// Created by schic on 5/2/2016.
//

#include <iostream>
#include <algorithm>
#include <limits>
#include "AIController.h"
#include "AnalysisBoard.h"

AIController::AIController() {
}

AIController::AIController(Board *givenGame) {
    game = givenGame;
}

int AIController::evaluateBlackMaterial(Board* b){
    int materialValue = 0;

    for(vector<Piece*> vec : b->board){
        for(Piece* p : vec){
            if(p != NULL && !p->isWhite){
                materialValue += p->getVal();
            }
        }
    }
    return materialValue;
}


int AIController::evaluateWhiteMaterial(Board* b) {
    int materialValue = 0;

    for(vector<Piece*> vec : b->board){
        for(Piece* p : vec){
            if(p != NULL && p->isWhite){
                materialValue += p->getVal();
            }
        }
    }
    return materialValue;
}

int AIController::evaluate(Board* b) {
    // gives a general board evaluation
    // higher the better

    // total material on the board
    int materialWeight = evaluateBlackMaterial(b) + evaluateWhiteMaterial(b);

    int numWhite = 0;
    int numBlack = 0;
    // count the number of black and white pieces
    for(vector<Piece*> vec : b->board){
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
    // this is to make the function relative to which side's turn it is
    if(b->whitesTurn){
        whoToMove = 1;
    } else {
        whoToMove = -1;
    }

    // a very simple evaluation function, but it gets the work done
    int result = materialWeight * numPieceDifference * whoToMove;
    return result;
}

Board* AIController::getBestMove(Board *b) {

    vector<Board*> possibleMoves = moveGenerator(b);
    Board* bestBoard;

    // set max initially to negative infinity so any move is better
    int maxScore = -std::numeric_limits<int>::max();

    for(int i = 0; i < possibleMoves.size(); ++i){
        Board* move = possibleMoves[i];
        int score = -negaMax(move, DEPTH);
        move->print();
        cout << "White Material Value: " << evaluateWhiteMaterial(move) << endl;
        cout << "Black Material Value: " << evaluateBlackMaterial(move) << endl;
        cout << "Board Eval: " << evaluate(move) << endl;
        cout << "Score: " << score << endl;
        if(score > maxScore){
            bestBoard = move;
            maxScore = score;
        }
        // if at the end of list, delete every board that isn't the one we're returning
        // to free up mem
        if(i == possibleMoves.size() -1) {
            for (Board *delBoard : possibleMoves) {
                if (delBoard != bestBoard) {
                    delete delBoard;
                }
            }
            possibleMoves.clear();
        }
    }
    return bestBoard;
}


int AIController::negaMax(Board* b, int depth) {
    // if depth is 0, we're at leaf node. Return the evaluation of position
    if(depth == 0){
        return evaluate(b);
    }
    // set the initial max to negative infinity
    int max = -std::numeric_limits<int>::max();
    vector<Board*> possibleMoves = moveGenerator(b);
    // for each possible move in the board
    for(int i = 0; i < possibleMoves.size(); ++i){
        Board* move = possibleMoves[i];
        // use recursion to search through move tree
        int score = -negaMax(move, depth -1);
        // if the move is than current max, it's the new champion
        if(score > max){
            max = score;
        }
        // if we're at the end of the possiblemove list, delete every member to free mem
        if(i == possibleMoves.size() -1) {
            for (Board *delBoard : possibleMoves) {
                delete delBoard;
            }
            possibleMoves.clear();
        }
    }
    return max;


}

vector<Board*> AIController::moveGenerator(Board* givenGame) {
    vector<Piece*> pieceList;

    // find each piece in board
    for(vector<Piece*> vec : givenGame->board){
        for(Piece* p : vec){
            if(p != NULL){
                pieceList.insert(pieceList.begin(), p);
            }
        }
    }
    // vector of boards that have made valid moves
    vector<Board*> moveList = vector<Board*>();
    Board* curBoard;

    for(Piece* p : pieceList) {
        // check to make sure p is not captured
        if (!p->isCaptured()) {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {

                    curBoard = new AnalysisBoard(givenGame);
                    vector<int> checkCoords = vector<int>(2);

                    checkCoords[0] = i;
                    checkCoords[1] = j;

                    // try to make the move to (i, j)
                    int moveStatus = curBoard->move(p->getPos(), checkCoords, true);
                    if (moveStatus == 0) {
                        // successful move. Add to list of moves
                        moveList.push_back(curBoard);
                    } else {
                        // failure. free memory
                        delete curBoard;
                    }

                }
            }
        }
    }
    return moveList;
}
