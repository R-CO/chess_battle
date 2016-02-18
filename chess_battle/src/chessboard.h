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
#ifndef CHESS_BATTLE_chess_board_H
#define CHESS_BATTLE_chess_board_H

#include <wx/msgdlg.h>
#include <wx/gdicmn.h>

#include "chess.h"

namespace rco {

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

  inline const bool is_chess_on(void) const {
    return is_chess_on_;
  }

  // Get functions

  inline static const int get_grid_width(void) {
    return grid_width_;
  }

  inline static const wxPoint get_left_top_grid_center_pos(void) {
    return left_top_grid_center_pos_;
  }

  inline Chess *get_chess(void) const {
    return chess_;
  }

  inline const int get_column(void) const {
    return column_;
  }

  inline const int get_row(void) const {
    return row_;
  }

  const wxPoint *GetGridCenterPosition(void) const;

  // Set functions

  void SetChess(Chess *chess);

  inline void set_column(const int &column) {
    column_ = column;
  }

  inline void set_row(const int &row) {
    row_ = row;
  }

  inline void set_grid_center_position(const wxPoint &grid_center_position) {
    grid_center_position_ = grid_center_position;
  }

  // grid_width must > 0
  inline static void set_grid_basic_attributes(const wxPoint &left_top_grid_center_pos, const int &grid_width) { 
    left_top_grid_center_pos_ = left_top_grid_center_pos;
    grid_width_ = grid_width;
  }

private:
  Chess *chess_;
  bool is_chess_on_;
  wxPoint grid_center_position_;
  int row_;
  int column_;
  
  static wxPoint left_top_grid_center_pos_;
  static int grid_width_;
};

const int kChessboardRow = 8;
const int kChessboardColumn = 4;

class Chessboard
{
public:
  Chessboard(const wxPoint &left_top_grid_center_pos, const int &grid_width);

  ~Chessboard();

  void ResetChessboardGrids(void);

  inline const bool is_chess_on_grid(const int &row, const int &column) const {
    return chessboard_grids_[row][column].is_chess_on();
  }

  // get functions
  const wxPoint *GetGridCenterPosition(const int &row, const int &column) const;

  static const int get_grid_width(void) {
    return ChessboardGrid::get_grid_width();
  }

  inline ChessboardGrid *get_chessboard_grid(const int &row, const int &column) {
    return &(chessboard_grids_[row][column]);
  }

  ChessboardGrid *GetChessBoardGrid(const wxPoint &hit_point, const int &chess_outer_radius);

  // set functions
  const bool SetChessOnGrid(Chess *chess, const int &chess_board_row, const int &chess_board_column);

  void set_grid_basic_attributes(const wxPoint &left_top_grid_center_pos, const int &grid_width) { // grid_width must > 0
    ChessboardGrid::set_grid_basic_attributes(left_top_grid_center_pos, grid_width);
  }

private:
  ChessboardGrid chessboard_grids_[kChessboardRow][kChessboardColumn];
};

}

#endif
