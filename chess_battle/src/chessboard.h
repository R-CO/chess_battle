/**
*** Author: R-CO
*** Mail: daniel1820kobe@gmail.com
*** Date: 2016-01-13
**/
#ifndef CHESS_BATTLE_CHESSBOARD_H
#define CHESS_BATTLE_CHESSBOARD_H

#include <wx/msgdlg.h>

#include "chess.h"

class ChessboardGrid
{
public:
  ChessboardGrid() 
    : chess_(nullptr), is_chess_on_(false)
  {
    kBlackChessNameVector.size();
  }

  ChessboardGrid(Chess *chess)
    : chess_(chess), is_chess_on_(true)
  {
  }

  ~ChessboardGrid() {
    chess_ = nullptr;
  }

  inline const bool is_chess_on(void) {
    return is_chess_on_;
  }

  inline void set_chess(Chess *chess) {
    chess_ = chess;
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
