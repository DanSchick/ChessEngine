//
// Created by Danny on 4/19/2016.
//

#include <iostream>
#include "Pawn.h"

int Pawn::legalMove(vector<int> newCoords, vector<vector<Piece *>> board) {
    // return of 1 means not a viable move
    // return of 2 means a piece is in the way or other obstruction

    //TODO: pawns need logic for taking pieces.
    // this means a check for the pawn moving into the threatened square
    // and that they're a piece of opposite color there

    if(isWhite){
        if(newCoords[1] > 7 || newCoords[1] < 0){
            // can't move beyond board limit
            return 1;
        }
        if(newCoords[1] < coords[1] || newCoords == coords || newCoords[1] == coords[1]){
            // can't move a pawn behind itself or to the same place
            return 1;
        }
        if(newCoords[0] != coords[0]){
            // can't move to a different column
            return 1;
        }

        if((newCoords[1] - coords[1] > 2)){
            // a pawn can't move 3 spaces
            return 1;
        }
        if((newCoords[1] - coords[1]) == 2 && leap){
            // the pawn can do it's special leap move off the starting block
            // check if there's any pieces in the way
            if(board[coords[0]][coords[1]+1] != NULL){
                // there is a piece in the way
                return 2;
            } else {
                leap = false;
                coords = newCoords;
                return 0;
            }

        } else if((newCoords[1] - coords[1]) == 2 && !leap){
            // can't move 2 squares if the piece has moved already
            return 1;
        }
        if(newCoords[1] - coords[1] == 1){
            // viable move
            // check if there's an obstruction
            leap = false;
            coords = newCoords;
            return 0;
        }

    } else {
        // ------------- BLACK PIECE ----------------
        if(newCoords[1] > 7 || newCoords[1] < 0){
            // can't move beyond board limit
            return 1;
        }
        if(newCoords[1] > coords[1] || newCoords == coords || newCoords[1] == coords[1]){
            // can't move a pawn behind itself or to the same place
            return 1;
        }
        if(newCoords[0] != coords[0]){
            // can't move to a different column
            return 1;
        }

        if((coords[1] - newCoords[1] > 2)){
            // a pawn can't move 3 spaces
            return 1;
        }
        if(coords[1] - newCoords[1] == 2 && leap){
            // the pawn can do it's special leap move off the starting block
            // check if there's any pieces in the way
            if(board[coords[0]][coords[1]-1] != NULL){
                // there is a piece in the way
                return 2;
            } else {
                leap = false;
                coords = newCoords;
                return 0;
            }

        } else if((coords[1] - newCoords[1]) == 2 && !leap){
            // can't move 2 squares if the piece has moved already
            return 1;
        }
        if(coords[1] - newCoords[1] == 1){
            // viable move
            // check if there's an obstruction
            leap = false;
            coords = newCoords;
            return 0;
        }

    }
    return 3;
}
