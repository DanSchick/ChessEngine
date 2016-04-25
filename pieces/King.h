//
// Created by Danny on 4/19/2016.
//

#ifndef CHESSENGINE_KING_H
#define CHESSENGINE_KING_H


#include "../Piece.h"

class King: public Piece {
public:
    King(bool white, int x, int y): Piece(white, x, y){
        name = "K";
        value = 1000;
    }

    int legalMove(vector<int> newCoords, vector<vector<Piece*>> board);

};


#endif //CHESSENGINE_KING_H
