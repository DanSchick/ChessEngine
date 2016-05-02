//
// Created by schic on 5/2/2016.
//

#ifndef CHESSENGINEPROJ_AICONTROLLER_H
#define CHESSENGINEPROJ_AICONTROLLER_H


#include "Board.h"

class AIController {
    // allows access to private members. Important for evaluation
    friend class Board;
public:
    // defaults to controlling black
    // but will have no board stored
    AIController();

    AIController(bool isWhite, Board givenBoard);

    double evaluateBlack();

    double evaluateWhite();


private:
    bool controlWhite;

    Board game;
};


#endif //CHESSENGINEPROJ_AICONTROLLER_H
