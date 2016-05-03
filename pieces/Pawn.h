//
// Created by Danny on 4/19/2016.
//

#ifndef CHESSENGINE_PAWN_H
#define CHESSENGINE_PAWN_H


#include "../Piece.h"

class Pawn: public Piece {
public:
    Pawn(bool white, int x, int y): Piece(white, x, y){
        if(white) {
            name = "P";
        } else {
            name = "p";
        }
        value = 100;
    }

    int legalMove(vector<int> newCoords, vector<vector<Piece*>> board);

    // true if pawn can do the first move leap special
    bool leap = true;

};


#endif //CHESSENGINE_PAWN_H
