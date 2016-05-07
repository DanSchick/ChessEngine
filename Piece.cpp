//
// Created by Danny on 4/19/2016.
//

#include "Piece.h"

Piece::Piece() {}


Piece::Piece(int pID, bool white, int x, int y) {
    isWhite = white;
    coords[0] = x;
    coords[1] = y;
    if(pID == 0){
        // ----------------- BISHOP -----------------
        ID = 0;
        if(white) {
            name = "B";
        } else {
            name = "b";
        }
        value = 325;

    } else if(pID == 1){
        // ----------------- KING ----------------------
        ID = 1;
        if(white) {
            name = "K";
        } else {
            name = "k";
        }
        value = 32767;
    } else if(pID == 2){
        // ---------------- KNIGHT ------------------------
        ID = 2;
        if(white) {
            name = "N";
        } else {
            name = "n";
        }
        value = 320;
    } else if(pID == 3){
        // ---------------- PAWN ---------------------------
        ID = 3;
        if(white) {
            name = "P";
        } else {
            name = "p";
        }
        value = 100;
    } else if(pID == 4){
        // ---------------- QUEEN ---------------------------
        ID = 4;
        if(white) {
            name = "Q";
        } else {
            name = "q";
        }
        value = 975;
    } else if(pID == 5){
        // ------------------ ROOK ------------------------------
        ID = 5;
        if(white) {
            name = "R";
        } else {
            name = "r";
        }
        value = 500;

    }
}

int Piece::legalMove(vector<int> newCoords, vector<vector<Piece>> board) {
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
    if(ID == 0){
        // ------------------- BISHOP -------------------------
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
                if(&board[xCor][yCor] != NULL){
                    return 2;
                }


            }

            // make the move
            // check first if destination will result in a capture
            if(&board[newCoords[0]][newCoords[1]] != NULL && isWhite != board[newCoords[0]][newCoords[1]].isWhite) {
                // there is a capture! we can move here
                return 0;
            } else if(&board[newCoords[0]][newCoords[1]] != NULL){
                // theres a piece of the same color here, can't make this move
                return 2;
            } else if(&board[newCoords[0]][newCoords[1]] == NULL){
                // empty square. Make the move
                return 0;
            }
        }



        else{
            // catch-all else
            return 1;
        }
    }


    else if(ID == 1){
        // --------------------------- KING ----------------------------------
        int xDiff = abs(newCoords[0] - coords[0]);
        int yDiff = abs(newCoords[1] - coords[1]);

        if(xDiff <= 1 && yDiff <= 1){
            // VALID. check if piece in the way
            if(&board[newCoords[0]][newCoords[1]] == NULL){
                return 0;
            } else if(&board[newCoords[0]][newCoords[1]] != NULL && isWhite != board[newCoords[0]][newCoords[1]].isWhite){
                // there's a capture!
                return 0;
            } else if(&board[newCoords[0]][newCoords[1]] != NULL){
                // piece of same color in the way
                return 2;
            }

            else {
                return 2;
            }

        }

        // any other move is invalid
        return 1;
    }



    else if(ID == 2){
        // ------------------- KNIGHT ----------------------------------
        int xDiff = abs(newCoords[0] - coords[0]);
        int yDiff = abs(newCoords[1] - coords[1]);

        if(xDiff == 2 && yDiff == 1 || yDiff == 2 && xDiff == 1){
            // VALID. check for pieces
            if(&board[newCoords[0]][newCoords[1]] == NULL){
                // empty square, VALID
                return 0;
            } else if(&board[newCoords[0]][newCoords[1]] != NULL && isWhite != board[newCoords[0]][newCoords[1]].isWhite){
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



    else if(ID == 3){
        // ------------------- PAWN -----------------------------
        if(isWhite){
            //-----------------------
            // check for attempt to capture a piece
            if(newCoords[1] - coords[1] == 1 && abs(newCoords[0] - coords[0]) == 1){
                // make sure there is a piece there
                if(&board[newCoords[0]][newCoords[1]] != NULL){
                    // check it's a piece of opposite color
                    if(board[newCoords[0]][newCoords[1]].isWhite != isWhite) {
                        leap = false;
                        return 0;
                    } else {
                        // can't capture a friendly piece!
                        return 2;
                    }
                } else {
                    return 1;
                }

            }

            // ----------------------------------
            // check basic movement errors
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
            //---------------------
            // check for 2 square leap if pawn hasn't moved
            if((newCoords[1] - coords[1]) == 2 && leap ){
                // the pawn can do it's special leap move off the starting block
                // check if there's any pieces in the way
                if(&board[coords[0]][coords[1]+1] != NULL || &board[newCoords[0]][newCoords[1]] != NULL){
                    // there is a piece in the way
                    return 2;
                } else {
                    leap = false;
                    return 0;
                }
            } else if((newCoords[1] - coords[1]) == 2 && !leap){
                // can't move 2 squares if the piece has moved already
                return 1;
            }

            // ---------------------
            // check for normal 1 square movement
            if(newCoords[1] - coords[1] == 1){
                // viable move
                // check if there's an obstruction
                leap = false;
                return 0;
            }

        } else {
            // ------------- BLACK PIECE ----------------
            if(coords[1] - newCoords[1] == 1 && abs(newCoords[0] - coords[0]) == 1){
                // make sure there is a piece there
                if(&board[newCoords[0]][newCoords[1]] != NULL){
                    // check it's a piece of opposite color
                    if(board[newCoords[0]][newCoords[1]].isWhite != isWhite) {
                        leap = false;
                        return 0;
                    } else {
                        // can't capture a friendly piece!
                        return 2;
                    }
                } else {
                    return 1;
                }

            }
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
                if(&board[coords[0]][coords[1]-1] != NULL || &board[newCoords[0]][newCoords[1]] != NULL){
                    // there is a piece in the way
                    return 2;
                } else {
                    leap = false;
                    return 0;
                }

            } else if((coords[1] - newCoords[1]) == 2 && !leap){
                // can't move 2 squares if the piece has moved already
                return 1;
            }
            if(coords[1] - newCoords[1] == 1){
                // viable move
                // check if there's an obstruction
                if(&board[newCoords[0]][newCoords[1]] == NULL) {
                    leap = false;
                    return 0;
                } else {
                    return 2;
                }
            }

        }
        return 3;
    }


    else if(ID == 4){
        // ---------------------------- QUEEN -------------------------

        int xDiff = newCoords[0] - coords[0];
        int yDiff = newCoords[1] - coords[1];

        int xCor = coords[0];
        int yCor = coords[1];

        /* -------------------------------------
         * ---------STRAIGHT MOVEMENT CHECK --------
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
                }if(&board[xCor][yCor] != NULL){
                    // there's a piece in the way
                    return 2;
                }


            }

            // valid move, check for piece at destination
            if(&board[newCoords[0]][newCoords[1]] != NULL && isWhite != board[newCoords[0]][newCoords[1]].isWhite) {
                // there is a capture! we can move here
                return 0;
            } else if(&board[newCoords[0]][newCoords[1]] != NULL){
                // theres a piece of the same color here, can't make this move
                return 2;
            } else if(&board[newCoords[0]][newCoords[1]] == NULL){
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
                }if(&board[xCor][yCor] != NULL){
                    // there's a piece in the way
                    return 2;
                }


            }
            // valid move, check for piece at destination
            if(&board[newCoords[0]][newCoords[1]] != NULL && isWhite != board[newCoords[0]][newCoords[1]].isWhite) {
                // there is a capture! we can move here
                return 0;
            } else if(&board[newCoords[0]][newCoords[1]] != NULL){
                // theres a piece of the same color here, can't make this move
                return 2;
            } else if(&board[newCoords[0]][newCoords[1]] == NULL){
                // empty square. Make the move
                return 0;
            }



        }

        /* -------------------------------------
         * ---------DIAG MOVEMENT CHECK ------
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
                if(&board[xCor][yCor] != NULL){
                    return 2;
                }


            }

            // make the move
            // check first if destination will result in a capture
            if(&board[newCoords[0]][newCoords[1]] != NULL && isWhite != board[newCoords[0]][newCoords[1]].isWhite) {
                // there is a capture! we can move here
                return 0;
            } else if(&board[newCoords[0]][newCoords[1]] != NULL){
                // theres a piece of the same color here, can't make this move
                return 2;
            } else if(&board[newCoords[0]][newCoords[1]] == NULL){
                // empty square. Make the move
                return 0;
            }
        }


        else {
            return 1;
        }

    }



    else if(ID == 5){
        // ------------------ ROOK -----------------------------------------------
        int xDiff = newCoords[0] - coords[0];
        int yDiff = newCoords[1] - coords[1];

        int xCor = coords[0];
        int yCor = coords[1];

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
                }if(&board[xCor][yCor] != NULL){
                    // there's a piece in the way
                    return 2;
                }


            }

            // valid move, check for piece at destination
            if(&board[newCoords[0]][newCoords[1]] != NULL && isWhite != board[newCoords[0]][newCoords[1]].isWhite) {
                // there is a capture! we can move here
                return 0;
            } else if(&board[newCoords[0]][newCoords[1]] != NULL){
                // theres a piece of the same color here, can't make this move
                return 2;
            } else if(&board[newCoords[0]][newCoords[1]] == NULL){
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
                }if(&board[xCor][yCor] != NULL){
                    // there's a piece in the way
                    return 2;
                }


            }
            // valid move, check for piece at destination
            if(&board[newCoords[0]][newCoords[1]] != NULL && isWhite != board[newCoords[0]][newCoords[1]].isWhite) {
                // there is a capture! we can move here
                return 0;
            } else if(&board[newCoords[0]][newCoords[1]] != NULL){
                // theres a piece of the same color here, can't make this move
                return 2;
            } else if(&board[newCoords[0]][newCoords[1]] == NULL){
                // empty square. Make the move
                return 0;
            }



        }

        else {
            // catch-all else
            return 1;
        }

    }

}


string Piece::getName() {
    return name;
}

int Piece::getID() {
    return ID;
}

int Piece::getVal() {
    return value;
}

int Piece::getX() {
    return coords[0];
}

int Piece::getY() {
    return coords[1];
}


vector<int> Piece::getPos() {
    return coords;
}

vector<int> Piece::setPos(vector<int> newPos) {
    coords = newPos;

}

void Piece::capture() {
    captured = true;
}

bool Piece::isCaptured() {
    return captured;
}




