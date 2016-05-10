//
// Created by schic on 5/3/2016.
//

#ifndef CHESSENGINEPROJ_ANALYSISBOARD_H
#define CHESSENGINEPROJ_ANALYSISBOARD_H


#include "Board.h"

class AnalysisBoard: public Board{
public:
    AnalysisBoard(Board* given);

    ~AnalysisBoard();

};


#endif //CHESSENGINEPROJ_ANALYSISBOARD_H
