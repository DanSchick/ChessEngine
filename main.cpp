#include <iostream>
#include <stdio.h>
#include "Piece.h"
#include "Board.h"
#include "GameController.h"

using namespace std;

int main() {

    Board gameBoard = Board();
    GameController game = GameController(gameBoard);



    return 0;
}