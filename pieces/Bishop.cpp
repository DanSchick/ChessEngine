//
// Created by Danny on 4/19/2016.
//

#include "Bishop.h"
int Bishop::legalMove(vector<int> newCoords, vector<vector<Piece *>> board) {
    // return of 1 means not a viable move
    // return of 2 means a piece is in the way or other obstruction

    //TODO: add logic for black piece and capturing
    if(isWhite){
        if(newCoords[1] > 7 || newCoords[0] > 7){
            // can't move beyond board limit
            return 1;
        }
        if(newCoords[1] < coords[1] || newCoords == coords || newCoords[1] == coords[1]){
            // can't move a pawn behind itself or to the same place
            return 1;
        }
        if(newCoords[0] - coords[0] == newCoords[1] - coords[1]){
            coords = newCoords;
            return 0;
        }
    }


}
