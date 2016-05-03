//
// Created by Danny on 4/19/2016.
//

#ifndef CHESSENGINE_ROOK_H
#define CHESSENGINE_ROOK_H


#include "../Piece.h"

class Rook: public Piece {
public:
    Rook(bool white, int x, int y): Piece(white, x, y){
        ID = 5;
        if(white) {
            name = "R";
        } else {
            name = "r";
        }
        value = 500;
    }

    int legalMove(vector<int> newCoords, vector<vector<Piece*>> board);

};


#endif //CHESSENGINE_ROOK_H
