//
// Created by schic on 5/2/2016.
//

#include "AIController.h"

AIController::AIController() {
    controlWhite = false;
}

AIController::AIController(bool isWhite, Board givenGame) {
    controlWhite = isWhite;
    game = givenGame;
}

double AIController::evaluateBlack() {
    double materialValue = 0;
    for(Piece* p : game.blackPieces){
        materialValue += p->getVal();
    }
    return materialValue;
}


double AIController::evaluateWhite() {
    double materialValue = 0;
    for(Piece* p : game.whitePieces){
        materialValue += p->getVal();
    }
    return materialValue;
}
