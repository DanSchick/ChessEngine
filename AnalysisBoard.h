//
// Created by schic on 5/3/2016.
//

#ifndef CHESSENGINEPROJ_ANALYSISBOARD_H
#define CHESSENGINEPROJ_ANALYSISBOARD_H


#include "Board.h"

/**
 * A board that the AI uses to determine the best move to make
 */
class AnalysisBoard: public Board{
public:
    /**
     * Constructs a deep copy of the given board
     */
    AnalysisBoard(Board* given);

    /**
     * Destructor. Deletes the pieces and all other members
     */
    ~AnalysisBoard();

};


#endif //CHESSENGINEPROJ_ANALYSISBOARD_H
