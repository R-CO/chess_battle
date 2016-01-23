#include "chessboard.h"

namespace rco {

Chessboard::Chessboard()
{
  // Current version is empty.
}

Chessboard::~Chessboard()
{
  // Current version is empty.
}

void Chessboard::ResetChessboardGrids(void)
{
  for (int row = 0; row < kChessboardRow; ++row) {
    for (int column = 0; column < kChessboardColumn; ++column) {
      chessboard_grids_[row][column].SetChess(nullptr);
    }
  }
}

const bool Chessboard::SetChessOnGrid(Chess *chess, const int &row, const int &column)
{
  if (row < 0 || row >= kChessboardRow ||
      column < 0 || column >= kChessboardColumn) {
    return false;
  } else {
    chessboard_grids_[row][column].SetChess(chess);
    return true;
  }
}

void ChessboardGrid::SetChess(Chess * chess)
{
  chess_ = chess;
  if (chess_ == nullptr) {
    is_chess_on_ = false;
  } else {
    is_chess_on_ = true;
  }
}

}
