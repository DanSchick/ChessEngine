//
// Created by Danny on 4/19/2016.
//

#ifndef CHESSENGINE_QUEEN_H
#define CHESSENGINE_QUEEN_H

#include "../Piece.h"

class Queen: public Piece {
public:
    Queen(bool white, int x, int y): Piece(white, x, y){
        name = "Q";
        value = 9;
    }

    int legalMove(vector<int> newCoords, vector<vector<Piece*>> board);

};


#endif //CHESSENGINE_QUEEN_H
