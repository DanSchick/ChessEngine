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
     * @param from: vector indicating coordinates of the peice to move
     * @param to: vector indicating the coordinates to check
     * @param verifyOnly: won't make the move if true. Will just see if valid
     * @return: code indicating success. A 0 is a success, anything else is fail
     */
    int move(vector<int> from, vector<int> to, bool verifyOnly);

    /**
     * take input from user for a move
     * @param input: the move to make in form e2-e4 or d1-d5, etc
     * @return: code indicating success. 0 means success
     */
    int inputMove(string input);

    /**
     * returns the chess board value from the chess notation
     * ie, a2 becomes 0,2
     * @param c: the letter indicating x coordinate
     * @reutrn: the int value of that coordinate
     */
    int getIntValFromChar(char c);


    /**
     * Destructor
     */
    virtual ~Board();


    /**
     *----------------- VARIABLES ----------------------
     */

    // number of white pieces
    int whiteCount = 16;
    // number of black pieces
    int blackCount = 16;

    // holds white king and black king. makes checking for checkmate easier
    Piece* whiteKing;
    Piece* blackKing;
    // if black is checkmated
    bool blackCheckmated = false;
    // if white is checkmated
    bool whiteCheckmated = false;
    // if black is in check
    bool blackInCheck = false;
    // if white is in check
    bool whiteInCheck = false;
    // true if whites turn
    bool whitesTurn = true;
    // 2D vector of the 8x8 chess board
    vector<vector<Piece*>> board = vector<vector<Piece*>>(8);
    // list of all captured pieces
    vector<Piece*> whiteCaptured;
    vector<Piece*> blackCaptured;
};


#endif //CHESSENGINE_BOARD_H
