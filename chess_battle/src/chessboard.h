﻿/**
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

const int kChessboardRow = 8;
const int kChessboardColumn = 4;

class Chessboard
{
public:
  Chessboard();

  ~Chessboard();

  // get functions

  // set functions
  const bool SetChessOnGrid(Chess *chess, const int &chessboard_row, const int &chessboard_column);

private:
  ChessboardGrid chessboard_grids_[kChessboardRow][kChessboardColumn];
};

#endif
