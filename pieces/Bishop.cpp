//
// Created by Danny on 4/19/2016.
//

#include <iostream>
#include "Bishop.h"
int Bishop::legalMove(vector<int> newCoords, vector<vector<Piece *>> board) {
    // return of 1 means not a viable move
    // return of 2 means a piece is in the way or other obstruction
    if(newCoords[1] > 7 || newCoords[0] > 7){
        // can't move beyond board limit
        return 1;
    }
    if(newCoords == coords){
        // can't move to same place
        return 1;
    }
    /* ---- DIAGONAL MOVEMENT CHECK ---------- */
    int xDiff = newCoords[0] - coords[0];
    int yDiff = newCoords[1] - coords[1];
    if(abs(xDiff) == abs(yDiff)){
        // VALID. check that pieces aren't in the way
        // just check each square leading to target for null
        int xCor = coords[0];
        int yCor = coords[1];
        while(true){
            // check if we're done
            if(xDiff == 0 && yDiff == 0){
                break;
            }
            // find next X coordinate of square to check
            if(xDiff < 0){
                xDiff++;
                xCor = coords[0] + xDiff;
            } else if(xDiff > 0){
                xDiff--;
                xCor = coords[0] + xDiff;
            }
            // find next Y coordinate of square to check
            if(yDiff < 0){
                yDiff++;
                yCor = coords[1] + yDiff;
            } else if(yDiff > 0){
                yDiff--;
                yCor = coords[1] + yDiff;
            }

            // if we're checking for the current piece location, the path is clear
            if(xCor == coords[0] && yCor == coords[1]){
                break;
            }
            if(board[xCor][yCor] != NULL){
                return 2;
            }


        }

        // make the move
        // check first if destination will result in a capture
        if(board[newCoords[0]][newCoords[1]] != NULL && this->isWhite != board[newCoords[0]][newCoords[1]]->isWhite) {
            // there is a capture! we can move here
            return 0;
        } else if(board[newCoords[0]][newCoords[1]] != NULL){
            // theres a piece of the same color here, can't make this move
            return 2;
        } else if(board[newCoords[0]][newCoords[1]] == NULL){
            // empty square. Make the move
            return 0;
        }
    }



    else{
        // catch-all else
        return 1;
    }


}
