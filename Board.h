//
// Created by Danny on 4/21/2016.
//

#include <vector>
#include "Piece.h"

#ifndef CHESSENGINE_BOARD_H
#define CHESSENGINE_BOARD_H

using namespace std;

class Board {
public:
    /**
     * Default constructor, so we set up a new game
     */
    Board();

    /**
     * prints out the current game board to cout
     */
    void print();

    /**
     * checks a move and executes if possible
     */
    int move(vector<int> from, vector<int> to);

    /**
     * take input from user for a move
     */
    int inputMove(string input);



private:
    bool whitesTurn = true;
    // 2D vector of the 8x8 chess board
    vector<vector<Piece*>> board = vector<vector<Piece*>>(8);
    // list of all captured pieces
    vector<Piece*> captured;
};


#endif //CHESSENGINE_BOARD_H
