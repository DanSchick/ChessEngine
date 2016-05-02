//
// Created by Danny on 4/19/2016.
//

#include "King.h"

int King::legalMove(vector<int> newCoords, vector<vector<Piece *>> board) {
    // A king can only move one square in any direction
    // we can check for this by just making sure that the king only moves one square in
    // both x and y
    int xDiff = abs(newCoords[0] - coords[0]);
    int yDiff = abs(newCoords[1] - coords[1]);

    if(xDiff <= 1 && yDiff <= 1){
        // VALID. check if piece in the way
        if(board[newCoords[0]][newCoords[1]] == NULL){
            return 0;
        } else {
            return 2;
        }

    }

    return 1;

}
