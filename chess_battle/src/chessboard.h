/**
*** Author: R-CO
*** Mail: daniel1820kobe@gmail.com
*** Date: 2016-01-13
**/
#ifndef CHESS_BATTLE_CHESSBOARD_H
#define CHESS_BATTLE_CHESSBOARD_H

#include <cstdlib> 

#include "chess.h"

class ChessboardGrid
{
public:
  ChessboardGrid() {
    chess_ = NULL;
    is_chess_on_ = false;
  }

  ChessboardGrid(Chess *chess)
    : chess_(chess)
  {
    is_chess_on_ = true;
  }

  ~ChessboardGrid() {
    chess_ = NULL;
  }

  inline const bool is_chess_on(void) {
    return is_chess_on_;
  }

private:
  Chess *chess_;
  bool is_chess_on_;
};

const int kChessBoardRow = 8;
const int kChessBoardColumn = 4;

class Chessboard
{
public:

private:
  ChessboardGrid chessboard_grids_[kChessBoardRow][kChessBoardColumn];
};

#endif
