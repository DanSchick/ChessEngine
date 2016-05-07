//
// Created by schic on 5/2/2016.
//

#ifndef CHESSENGINEPROJ_AICONTROLLER_H
#define CHESSENGINEPROJ_AICONTROLLER_H


#include "Board.h"

class AIController {
public:
    // defaults to controlling black
    // but will have no board stored
    AIController();

    AIController(bool isWhite);

    int evaluateBlackMaterial(Board* b) const;

    int evaluateWhiteMaterial(Board* b) const;

    int evaluate(Board* b) const;

    Board getBestMove(Board* b);

//    double negaMax(Board* b, double depth, double alpha, double beta);

    int negaMax(Board* b, int depth);


    vector<Board> moveGenerator(Board* givenGame);


private:
    bool controlWhite;

    double maxDepth = 1;
    int DEPTH = 0;

};


#endif //CHESSENGINEPROJ_AICONTROLLER_H
