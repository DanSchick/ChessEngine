//
// Created by schic on 5/2/2016.
//

#ifndef CHESSENGINEPROJ_AICONTROLLER_H
#define CHESSENGINEPROJ_AICONTROLLER_H


#include "Board.h"

/**
 * Controls the AI portion of the game
 */
class AIController {
public:
    /**
     * Defaults to controlling black
     */
    AIController();

    /**
     * Is given the option of being white and the starting board
     */
    AIController(Board *givenBoard);
    /**
     * Evaluates the pieces that Black has on the board
     * @param b: the current board to evaluate
     * @return: and int representing the value of pieces on black's side
     */
    int evaluateBlackMaterial(Board* b);

    /**
     * Evaluates the pieces that White has on the board
     * @param b: the current board to evaluate
     * @return: and int representing the value of pieces on white's side
     */
    int evaluateWhiteMaterial(Board* b);

    /**
     * Evaluates the board relative to the current side
     * @param b: current board to evaluate
     * @return: an integer that represents the board "score". Higher the number, the better the current side's position is
     */
    int evaluate(Board* b);

    /**
     * Root function for finding the next move to make
     * @param b: the current board
     * @return: the best available move to make
     */
    Board* getBestMove(Board* b);


    /**
     * Negamax algorithm: implementation of common min-max algorithm for chess AI
     * Evaluates each move and using recursion goes down the move tree to figure out what the best move to make is
     * @param b: the current position of the game board
     * @param depth: How deep in the move tree this algorithm should go.
     * @return: the score of best leaf node
     */
    int negaMax(Board* b, int depth);


    /**
     * Goes through the current board and finds every available move
     * That the current side can make
     * @param givenGame: current board
     * @return: A vector of every possible move. GetBestMove and NegaMax uses this to evaluate which move to make
     */
    vector<Board*> moveGenerator(Board* givenGame);


private:
    // the depth that the move search algorithm should go
    // A depth of 1 will evaluate black's move and white's best response to it
    // A depth of 2 would also evaluate black's response to white's response effectively going 4 entire moves deep
    // We keep it at 1 for program speed
    int DEPTH = 1;

    // the starting game
    Board* game;
};


#endif //CHESSENGINEPROJ_AICONTROLLER_H
