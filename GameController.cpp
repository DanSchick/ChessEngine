//
// Created by schic on 5/3/2016.
//

#include <iostream>
#include "GameController.h"
#include "AIController.h"

GameController::GameController(Board mainGame) {
    // get black and white king
    game = mainGame;

    string moveInput;
    AIController AI = AIController(false, game);
    int status;
    game.print();
    while(true){
        if(game.blackCheckmated || game.whiteCheckmated){
            break;
        }

        if(game.whitesTurn){
            cout << "\n-----------\nWhite's Turn" << endl;
        } else {
            cout << "\n-----------\nBlack's Turn" << endl;
        }
        cout << "White Material Value: " << AI.evaluateWhiteMaterial(game) << endl;
        cout << "Black Material Value: " << AI.evaluateBlackMaterial(game) << endl;
        cout << "Board Eval: " << AI.evaluate(game) << endl;
        cout << "Enter your move: " << endl;

        cin >> moveInput;
        status = game.inputMove(moveInput);
        if(status == 0){
            // flip it to the others player turn
            game.whitesTurn = !game.whitesTurn;
            game.print();
        } else {
            cout << "ERROR" << endl;
        }
        if(!game.whitesTurn) {
            cout << "finding next move-------------------------" << endl;
            Board oldBoard = game;
            Board nextMove = AI.getBestMove(game);
            game = nextMove;
            game.print();
            game.whitesTurn = !game.whitesTurn;
        }



    }
}