#include "chessboard.h"

Chessboard::Chessboard()
{
  // Current version is empty.
}

Chessboard::~Chessboard()
{
  // Current version is empty.
}

const bool Chessboard::SetChessOnGrid(Chess *chess, const int &chessboard_row, const int &chessboard_column)
{
  if (chessboard_row < 0 || chessboard_row >= kChessboardRow ||
      chessboard_column < 0 || chessboard_column >= kChessboardColumn) {
    return false;
  } else {
    chessboard_grids_[chessboard_row][chessboard_column].set_chess(chess);
    return true;
  }
}
