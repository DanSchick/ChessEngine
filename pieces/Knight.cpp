//
// Created by Danny on 4/19/2016.
//

#include "Knight.h"

int Knight::legalMove(vector<int> newCoords, vector<vector<Piece *>> board) {
    // there's two types of moves
    // either x changes by 2 and y changes by 1,
    // or y changes by 2 and x changes by 1

    if(newCoords[1] > 7 || newCoords[0] > 7){
        // can't move beyond board limit
        return 1;
    }
    if(newCoords == coords){
        // can't move to same place
        return 1;
    }

    int xDiff = abs(newCoords[0] - coords[0]);
    int yDiff = abs(newCoords[1] - coords[1]);

    if(xDiff == 2 && yDiff == 1 || yDiff == 2 && xDiff == 1){
        // VALID. check for pieces
        if(board[newCoords[0]][newCoords[1]] == NULL){
            // empty square, VALID
            return 0;
        } else if(board[newCoords[0]][newCoords[1]] != NULL && this->isWhite != board[newCoords[0]][newCoords[1]]->isWhite){
            // there's a capture!
            return 0;
        } else {
            // piece of same color in the way
            return 2;
        }
    } else {
        // catch-all else
        return 1;
    }

}
