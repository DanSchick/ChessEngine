//
// Created by Danny on 4/19/2016.
//

#include "Queen.h"

int Queen::legalMove(vector<int> newCoords, vector<vector<Piece *>> board) {
    // Queen movement is just a combination of Rook and Bishop movement

    if(newCoords[1] > 7 || newCoords[0] > 7){
        // can't move beyond board limit
        return 1;
    }
    if(newCoords == coords){
        // can't move to same place
        return 1;
    }

    int xDiff = newCoords[0] - coords[0];
    int yDiff = newCoords[1] - coords[1];

    int xCor = coords[0];
    int yCor = coords[1];

    /* -------------------------------------
     * ---------ROOK MOVEMENT CHECK --------
     * -------------------------------------
     * */


    if(abs(xDiff) != 0 && abs(yDiff) == 0){
        // Rook is moving horizontally
        // Check no pieces in the way
        while(true){
            if(xDiff == 0 && yDiff == 0){
                // we're done
                break;
            }
            // find next xCoord to check
            if(xDiff < 0){
                xDiff++;
                xCor = coords[0] + xDiff;
            } else if(yDiff > 0){
                xDiff--;
                xCor = coords[0] + xDiff;
            }

            // make sure we aren't checking the current pois
            if(xCor == coords[0]){
                break;
            }if(board[xCor][yCor] != NULL){
                // there's a piece in the way
                return 2;
            }


        }

        // valid move, check for piece at destination
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

    } else if(abs(xDiff) == 0 && abs(yDiff) != 0){
        // Rook is moving vertically
        // check no pieces in the way

        while(true){
            if(xDiff == 0 && yDiff == 0){
                // we're done
                break;
            }
            // find next yCoord to check
            if(yDiff < 0){
                yDiff++;
                yCor = coords[1] + yDiff;
            } else if(yDiff > 0){
                yDiff--;
                yCor = coords[1] + yDiff;
            }

            // make sure we aren't checking the current pois
            if(yCor == coords[1]){
                break;
            }if(board[xCor][yCor] != NULL){
                // there's a piece in the way
                return 2;
            }


        }
        // valid move, check for piece at destination
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




    /* -------------------------------------
     * ---------BISHOP MOVEMENT CHECK ------
     * -------------------------------------
     * */


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


    else {
        return 1;
    }



}
