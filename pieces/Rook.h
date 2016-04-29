//
// Created by Danny on 4/19/2016.
//

#ifndef CHESSENGINE_ROOK_H
#define CHESSENGINE_ROOK_H


#include "../Piece.h"

class Rook: public Piece {
public:
    Rook(bool white, int x, int y): Piece(white, x, y){
        if(white) {
            name = "R";
        } else {
            name = "r";
        }
        value = 5;
    }

    int legalMove(vector<int> newCoords, vector<vector<Piece*>> board);

};


#endif //CHESSENGINE_ROOK_H
