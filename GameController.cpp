//
// Created by schic on 5/3/2016.
//

#include <iostream>
#include "GameController.h"
#include "AIController.h"

GameController::GameController(Board *mainGame, bool twoPlayer) {
    // get black and white king
    game = mainGame;
    game->whiteKing = game->board[4][0];
    game->blackKing = game->board[4][7];

    if(!twoPlayer) {
        string moveInput;
        AIController AI = AIController(false, game);
        int status;
        game->print();
        while (true) {
            if (game->blackCheckmated || game->whiteCheckmated) {
                break;
            }

            if (whitesTurn) {
                cout << "\n-----------\nWhite's Turn" << endl;
            } else {
                cout << "\n-----------\nBlack's Turn" << endl;
            }
            cout << "White Material Value: " << AI.evaluateWhiteMaterial(game) << endl;
            cout << "Black Material Value: " << AI.evaluateBlackMaterial(game) << endl;
            cout << "Board Eval: " << AI.evaluate(game) << endl;
            cout << "Enter your move: " << endl;

            cin >> moveInput;
            status = game->inputMove(moveInput);
            if (status == 0) {
                // flip it to the others player turn
                whitesTurn = !whitesTurn;
                game->print();
            } else {
                cout << "ERROR" << endl;
            }
            if (!whitesTurn) {
                cout << "finding next move-------------------------" << endl;
                Board *nextMove = AI.getBestMove(game);
                game = nextMove;
                game->print();
                whitesTurn = !whitesTurn;
            }


        }
    } else {
        // ------------------------ TWO PLAYER GAME -----------------------
        string moveInput;
        int status;
        game->print();
        while(true){
            if(whitesTurn){
                cout << "\n-----------------------\nWhite's turn" << endl;
            } else {
                cout << "\n-----------------------\nBlack's turn" << endl;
            }
            cout << "Enter your move (in form e2-e4): " << endl;

            cin >> moveInput;
            if(moveInput == "q"){
                break;
            }
            status = game->inputMove(moveInput);
            if(status == 0){
                game->print();
                // move was made, flip to other player's turn
                whitesTurn = !whitesTurn;
            } else {
                cout << "ERROR" << endl;
            }
        }
    }
}