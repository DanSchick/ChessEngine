#include <iostream>
#include <stdio.h>
#include "Piece.h"
#include "Board.h"

using namespace std;

int main() {

    Board game = Board();
    vector<int> movePiece = vector<int>(2);
    movePiece[0] = 1;
    movePiece[1] = 1;

    vector<int> move = vector<int>(2);
    move[0] = 1;
    move[1] = 2;

    game.inputMove("e2-e3");

    game.print();
    return 0;
}