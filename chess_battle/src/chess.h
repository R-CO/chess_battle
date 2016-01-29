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
#ifndef CHESS_BATTLE_CHESS_H
#define CHESS_BATTLE_CHESS_H

#include <map>
#include <vector>

#include <wx/gdicmn.h>
#include <wx/string.h>

namespace rco {

enum ChessType
{
  kChessSoldier = 0,
  kChessCannon = 1,
  kChessHorse = 2,
  kChessCar = 3,
  kChessElephant = 4,
  kChessWarrior = 5,
  kChessGeneral = 6
};

enum ChessColor
{
  kBlackChess = 0,
  kRedChess = 1
};

enum ChessStatus
{
  kChessIsNegative = 0,
  kChessIsPositive = 1,
  kChessIsDead = 2
};

// wxT("卒") /* 0 */, wxT("包") /* 1 */, wxT("馬") /* 2 */, wxT("車") /* 3 */,	wxT("象") /* 4 */, wxT("士") /* 5 */, wxT("將") /* 6 */
extern const std::vector<wxString> kBlackChessNames; // Definition is in "chess.cpp"

// wxT("兵") /* 0 */, wxT("炮") /* 1 */, wxT("傌") /* 2 */, wxT("俥") /* 3 */, wxT("相") /* 4 */, wxT("仕") /* 5 */, wxT("帥") /* 6 */
extern const std::vector<wxString> kRedChessNames; // Definition is in "chess.cpp"

//class ChessboardGrid; // Forward declartion. Go to "chessboard.h" and "chessboard.cpp" for more detail.

class Chess
{
public:
  Chess(const wxString &chess_name)
    : chess_name_(chess_name)
  {
    InitChess();
  }

  void ResetChess(void);

  // Get functions

  inline const wxPoint get_position(void) const {
    return chess_position_;
  }

  inline const int get_x_coordinate(void) const {
    return chess_position_.x;
  }

  inline const int get_y_coordinate(void) const {
    return chess_position_.y;
  }

  inline const ChessColor get_chess_color(void) const {
    return chess_color_;
  }

  inline static const ChessColor get_chess_color(const wxString &chess_name) {
    return kChessNameColorMap[chess_name];
  }

  inline const ChessStatus get_chess_status(void) const {
    return chess_status_;
  }

  inline const ChessType get_chess_type(void) const {
    return chess_type_;
  }

  inline const bool get_taking(void) const {
    return taking_;
  }

  inline static const ChessType get_chess_type(const wxString &chess_name) {
    return kChessNameTypeMap[chess_name];
  }

  inline const wxString get_chess_name(void) const {
    return chess_name_;
  }

  // Set functions

  inline void set_position(const wxPoint &position) {
    chess_position_ = position;
  }

  inline void set_x_coordinate(const int &x_coordinate) {
    chess_position_.x = x_coordinate;
  }

  inline void set_y_coordinate(const int &y_coordinate) {
    chess_position_.y = y_coordinate;
  }

  inline void set_chess_color(const ChessColor &chess_color) {
    chess_color_ = chess_color;
  }

  inline void set_chess_status(const ChessStatus &chess_status) {
    chess_status_ = chess_status;
  }

  inline void set_taking(const bool &taking) {
    taking_ = taking;
  }

protected:
  virtual void InitChess(void);

  //ChessboardGrid *chessboard_grid_;
  ChessColor chess_color_;
  ChessStatus chess_status_;
  wxString chess_name_;
  wxPoint chess_position_;
  ChessType chess_type_;
  int chess_exp_;

  bool taking_;

  static std::map<wxString, ChessColor> kChessNameColorMap;
  static std::map<wxString, ChessType> kChessNameTypeMap;
};

}

#endif
