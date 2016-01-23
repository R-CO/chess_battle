#include "chessboard.h"

namespace rco {

Chessboard::Chessboard(const wxPoint &left_top_grid_center_pos, const int &grid_width)
{
  set_grid_basic_attributes(left_top_grid_center_pos, grid_width);
  for (int row = 0; row < kChessboardRow; ++row) {
    for (int column = 0; column < kChessboardColumn; ++column) {
      wxPoint grid_center_pos = left_top_grid_center_pos + wxPoint((column * grid_width), (row * grid_width));
      chessboard_grids_[row][column].set_grid_center_position(grid_center_pos);
    }
  }
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

const wxPoint * Chessboard::GetGridCenterPosition(const int & row, const int & column) const
{
  if (row < 0 || row >= kChessboardRow ||
      column < 0 || column >= kChessboardColumn) {
    return nullptr;
  } else {
    return chessboard_grids_[row][column].GetGridCenterPosition();
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

wxPoint ChessboardGrid::left_top_grid_center_pos_ = wxPoint();
int ChessboardGrid::grid_width_ = 1;

const wxPoint * ChessboardGrid::GetGridCenterPosition(void) const
{
  return &grid_center_position_;
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
