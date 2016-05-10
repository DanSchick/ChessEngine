//
// Created by schic on 5/3/2016.
//

#ifndef CHESSENGINEPROJ_GAMECONTROLLER_H
#define CHESSENGINEPROJ_GAMECONTROLLER_H


#include "Board.h"

/**
 *Controls the game.
 */
class GameController {
public:
    /**
     * Runs the game in a while loop
     * @param game: starting board
     * @param twoPlayer: how many players in the game
     */
    GameController(Board* game, bool twoPlayer);


private:
    // represents the current game board. If playing vs AI, this board will change
    Board* game;
    // represents who's turn it is
    bool whitesTurn = true;

};


#endif //CHESSENGINEPROJ_GAMECONTROLLER_H
