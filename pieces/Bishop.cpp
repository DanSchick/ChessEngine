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
    int xRange = newCoords[0] - coords[0];
    int yRange = newCoords[1] - coords[1];
    if(abs(xRange) == abs(yRange)){
        // VALID. check that pieces aren't in the way
        // just check each square leading to target for null
        int xCor = coords[0];
        int yCor = coords[1];
        while(true){
            // check if we're done
            if(xRange == 0 && yRange == 0){
                break;
            }
            // find next X coordinate of square to check
            if(xRange < 0){
                xRange++;
                xCor = coords[0] + xRange;
            } else if(xRange > 0){
                xRange--;
                xCor = coords[0] + xRange;
            }
            // find next Y coordinate of square to check
            if(yRange < 0){
                yRange++;
                yCor = coords[1] + yRange;
            } else if(yRange > 0){
                yRange--;
                yCor = coords[1] + yRange;
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
        return 0;
    }



    else{
        // catch-all else
        return 1;
    }


}
