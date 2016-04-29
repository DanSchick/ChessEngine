//
// Created by Danny on 4/19/2016.
//

#ifndef CHESSENGINE_BISHOP_H
#define CHESSENGINE_BISHOP_H


#include "../Piece.h"

class Bishop: public Piece {
public:
    Bishop(bool white, int x, int y): Piece(white, x, y){
        if(white) {
            name = "B";
        } else {
            name = "b";
        }
        value = 3;
    }

    int legalMove(vector<int> newCoords, vector<vector<Piece*>> board);


};


#endif //CHESSENGINE_BISHOP_H
