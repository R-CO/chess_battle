//The MIT License(MIT)
//
//Copyright(c) 2016 R-CO
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files(the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions :
//
//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.
/**
*** Author: R-CO
*** Mail: daniel1820kobe@gmail.com
*** Date: 2016-01-13
**/
#include "chessboard.h"

namespace rco {

Chessboard::Chessboard(const wxPoint &left_top_grid_center_pos, const int &grid_width)
{
  set_grid_basic_attributes(left_top_grid_center_pos, grid_width);
  for (int row = 0; row < kChessboardRow; ++row) {
    for (int column = 0; column < kChessboardColumn; ++column) {
      wxPoint grid_center_pos = left_top_grid_center_pos + wxPoint((column * grid_width), (row * grid_width));
      chessboard_grids_[row][column].set_grid_center_position(grid_center_pos);
      chessboard_grids_[row][column].set_column(column);
      chessboard_grids_[row][column].set_row(row);
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

ChessboardGrid * Chessboard::GetChessBoardGrid(const wxPoint & hit_point, const int & chess_outer_radius)
{
  wxPoint position_diff;
  const int chess_outer_radius_square = chess_outer_radius * chess_outer_radius;
  for (int row = 0; row < kChessboardRow; ++row) {
    for (int column = 0; column < kChessboardColumn; ++column) {
      position_diff = hit_point - *(chessboard_grids_[row][column].GetGridCenterPosition());
      if ((position_diff.x * position_diff.x + position_diff.y * position_diff.y) <= 
          chess_outer_radius_square) {
        return &(chessboard_grids_[row][column]);
      }
    }
  }

  return nullptr;
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

} // end of namespace "rco"
