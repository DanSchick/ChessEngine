cmake_minimum_required(VERSION 3.5)
project(ChessEngineProj_)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
set(SOURCE_FILES main.cpp Piece.cpp Piece.h Board.h Board.cpp pieces/Bishop.cpp pieces/Bishop.h pieces/King.cpp pieces/King.h pieces/Knight.cpp pieces/Knight.h pieces/Pawn.cpp pieces/Pawn.h pieces/Queen.cpp pieces/Queen.h pieces/Rook.cpp pieces/Rook.h AIController.cpp AIController.h)
add_executable(ChessEngineProj_ ${SOURCE_FILES})