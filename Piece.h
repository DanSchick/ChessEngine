//
// Created by Danny on 4/19/2016.
//

#include <vector>
#include <iosfwd>
#include <stdlib.h>
#include <string>
#ifndef CHESSENGINE_PIECE_H
#define CHESSENGINE_PIECE_H

using namespace std;

class Piece {
public:
    Piece();
    /**
     * default contructor
     */
    Piece(bool white, int x, int y);

    /**
     * gives the name of the piece back
     */
    string getName();

    /**
     * Gives the piece ID
     */
    int getID();

    /**
     * returns current x val
     */
    int getX();

    /**
     * returns the coords array
     */
    vector<int> getPos();

    /**
     * return current y val
     */
    int getY();

    /**
     * Move piece to given square
     */
    virtual int legalMove(vector<int> newCoords, vector<vector<Piece*>> board) = 0;



protected:
    bool isWhite;
    // represents x y coords
    vector<int> coords = vector<int>(2);
    // is name of piece. eg 'rook' 'king'
    string name;
    // is two digit piece id
    int ID;
    // relative value of piece
    int value;





};


#endif //CHESSENGINE_PIECE_H
