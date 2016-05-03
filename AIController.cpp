//
// Created by schic on 5/2/2016.
//

#include <iostream>
#include <limits>
#include "AIController.h"

AIController::AIController() {
    controlWhite = false;
}

AIController::AIController(bool isWhite, Board *givenGame) {
    controlWhite = isWhite;
    game = givenGame;
}

double AIController::evaluateBlackMaterial(){
    double materialValue = 0;
    for(Piece* p : game->blackPieces){
        materialValue += p->getVal();
    }
    return materialValue;
}


double AIController::evaluateWhiteMaterial() {
    double materialValue = 0;
    for(Piece* p : game->whitePieces){
        materialValue += p->getVal();
    }
    return materialValue;
}

double AIController::evaluate() {
    // gives a general board evaluation
    // higher the better
    double materialWeight = evaluateBlackMaterial() + evaluateWhiteMaterial();
    double numPieceDifference = game->whitePieces.size() - game->blackPieces.size();
    double whoToMove;
    if(game->whitesTurn){
        whoToMove = 1;
    } else {
        whoToMove = -1;
    }

    double result = materialWeight * numPieceDifference * whoToMove;
    return result;
}

double AIController::negaMax(int depth) {
    if(depth == 0) return evaluate();
    int max = std::numeric_limits<int>::max();


}
