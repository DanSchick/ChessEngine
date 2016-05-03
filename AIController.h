//
// Created by schic on 5/2/2016.
//

#ifndef CHESSENGINEPROJ_AICONTROLLER_H
#define CHESSENGINEPROJ_AICONTROLLER_H


#include "Board.h"

class AIController {
public:
    // defaults to controlling black
    // but will have no board stored
    AIController();

    AIController(bool isWhite, Board *givenBoard);

    double evaluateBlackMaterial();

    double evaluateWhiteMaterial();

    double evaluate();

    double negaMax(int depth);

    //TODO: create a method that returns all available moves relative to side


private:
    bool controlWhite;

    Board* game;
};


#endif //CHESSENGINEPROJ_AICONTROLLER_H
