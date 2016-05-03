//
// Created by schic on 5/2/2016.
//

#include <iostream>
#include <limits>
#include "AIController.h"
#include "AnalysisBoard.h"

AIController::AIController() {
    controlWhite = false;
}

AIController::AIController(bool isWhite, Board *givenGame) {
    controlWhite = isWhite;
    game = givenGame;
}

int AIController::evaluateBlackMaterial(){
    int materialValue = 0;
    for(Piece* p : game->blackPieces){
        materialValue += p->getVal();
    }
    return materialValue;
}


int AIController::evaluateWhiteMaterial() {
    int materialValue = 0;
    for(Piece* p : game->whitePieces){
        materialValue += p->getVal();
    }
    return materialValue;
}

int AIController::evaluate(Board* b) {
    // gives a general board evaluation
    // higher the better
    int materialWeight = evaluateBlackMaterial() + evaluateWhiteMaterial();
    int numPieceDifference = b->whitePieces.size() - b->blackPieces.size();
    int whoToMove;
    if(b->whitesTurn){
        whoToMove = 1;
    } else {
        whoToMove = -1;
    }

    int result =materialWeight * numPieceDifference * whoToMove;
    return result;
}

int AIController::negaMax(Board* b, int depth) {
    if(depth == 0) return evaluate(b);
    int max = -std::numeric_limits<int>::max();
    for(vector<vector<Piece*>> move : moveGenerator(b)){
        int score = -negaMax(b, depth -1);
        if(score > max){
            max = score;
        }
    }
    return max;


}

vector<vector<vector<Piece*>>> AIController::moveGenerator(Board* givenGame) {
    vector<Piece*> pieceList;
    if(givenGame->whitesTurn){
        pieceList = givenGame->whitePieces;
    } else {
        pieceList = givenGame->blackPieces;
    }
    // vector of boards that have made valid moves
    vector<vector<vector<Piece*>>> moveList;
    Board* curBoard;
    // so the problem is that curBoard does a shallow copy of it's parameter's board

    for(Piece* p : pieceList){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){

                curBoard = new AnalysisBoard(givenGame);
                vector<int> checkCoords = vector<int>(2);

                checkCoords[0] = i;
                checkCoords[1] = j;

                int moveStatus = curBoard->move(p->getPos(), checkCoords, true);
                if(moveStatus == 0){
                    moveList.insert(moveList.end(),curBoard->board);
                }

            }
        }
    }
    return moveList;
}
