#include <iostream>
#include <stdio.h>
#include "Piece.h"
#include "Board.h"
#include "GameController.h"

using namespace std;

int main() {
    cout << "Welcome to chess! Two options: Two player game, or Vs AI" << endl;
    cout << "(1): Versus AI" << endl;
    cout << "(2): Two player" << endl;

    string input;
    bool twoPlayer;
    while(true){
        cin >> input;
        if(input == "1"){
            twoPlayer = false;
            break;
        } else if(input == "2"){
            twoPlayer = true;
            break;
        }

    }
    Board* gameBoard = new Board();
    GameController game = GameController(gameBoard, twoPlayer);



    return 0;
}