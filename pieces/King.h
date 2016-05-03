//
// Created by Danny on 4/19/2016.
//

#ifndef CHESSENGINE_KING_H
#define CHESSENGINE_KING_H


#include "../Piece.h"

class King: public Piece {
public:
    King(bool white, int x, int y): Piece(white, x, y){
        if(white) {
            name = "K";
        } else {
            name = "k";
        }
        value = 32767;
    }

    int legalMove(vector<int> newCoords, vector<vector<Piece*>> board);

};


#endif //CHESSENGINE_KING_H
