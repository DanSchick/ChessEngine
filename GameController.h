//
// Created by schic on 5/3/2016.
//

#ifndef CHESSENGINEPROJ_GAMECONTROLLER_H
#define CHESSENGINEPROJ_GAMECONTROLLER_H


#include "Board.h"

class GameController {
public:
    GameController(Board* game, bool twoPlayer);

    Board* game;

private:
    bool whitesTurn = true;

};


#endif //CHESSENGINEPROJ_GAMECONTROLLER_H
