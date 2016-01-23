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

const bool Chessboard::SetChessOnGrid(Chess *chess, const int &row, const int &column)
{
  if (row < 0 || row >= kChessboardRow ||
      column < 0 || column >= kChessboardColumn) {
    return false;
  } else {
    chessboard_grids_[row][column].set_chess(chess);
    return true;
  }
}

void ChessboardGrid::set_chess(Chess * chess)
{
  chess_ = chess;
  if (chess_ == nullptr) {
    is_chess_on_ = false;
  } else {
    is_chess_on_ = true;
  }
}

}
