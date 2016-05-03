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
     * The Game loop. Handles one method needed to call to start the game
     */
//    void start();

    /**
     * prints out the current game board to cout
     */
    void print();

    /**
     * checks a move and executes if possible
     */
    int move(vector<int> from, vector<int> to, bool verifyOnly);

    /**
     * take input from user for a move
     */
    int inputMove(string input);

    /**
     * returns the chess board value from the chess notation
     * ie, a2 becomes 0,2
     */
    int getIntValFromChar(char c);

    ~Board();


    /**
     *----------------- VARIABLES ----------------------
     */

    vector<Piece*> whitePieces = vector<Piece*>();
    vector<Piece*> blackPieces = vector<Piece*>();





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
