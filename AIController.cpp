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

double AIController::evaluate() {
    for(vector<Piece*> vec : game.board){
        for(Piece* p : vec){
            if(p != NULL){

            }
        }

    }
}
