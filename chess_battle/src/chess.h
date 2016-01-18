/**
*** Author: R-CO
*** Mail: daniel1820kobe@gmail.com
*** Date: 2016-01-13
**/
#ifndef CHESS_BATTLE_CHESS_H
#define CHESS_BATTLE_CHESS_H

#include <map>
#include <vector>

#include <wx/string.h>
#include <wx/arrstr.h>

typedef int ChessType;

enum ChessColor
{
  kBlackChess = 0,
  kRedChess = 1
};

enum ChessStatus
{
  kChessIsNegative = 0,
  kChessIspositive = 1,
  kChessIsDead = 2
};

extern const std::vector<wxString> kBlackChessNameVector; // Definition is in "chess.cpp"
extern const std::vector<wxString> kRedChessNameVector; // Definition is in "chess.cpp"

class ChessboardGrid; // Forward declartion. Go to "chessboard.h" and "chessboard.cpp" for more detail.

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

  inline const int get_x_coordinate(void) {
    return x_coordinate_;
  }

  inline const int get_y_coordinate(void) {
    return y_coordinate_;
  }

  inline const ChessColor get_chess_color(void) {
    return chess_color_;
  }

  inline static const ChessColor get_chess_color(const wxString &chess_name) {
    return kChessNameColorMap[chess_name];
  }

  inline const ChessStatus get_chess_status(void) {
    return chess_status_;
  }

  inline const ChessType get_chess_type(void) {
    return chess_type_;
  }

  inline static const ChessType get_chess_type(const wxString &chess_name) {
    return kChessNameTypeMap[chess_name];
  }

  // Set functions

  inline void set_x_coordinate(const int &x_coordinate) {
    x_coordinate_ = x_coordinate;
  }

  inline void set_y_coordinate(const int &y_coordinate) {
    y_coordinate_ = y_coordinate;
  }

  inline void set_chess_color(const ChessColor &chess_color) {
    chess_color_ = chess_color;
  }

  inline void set_chess_status(const ChessStatus &chess_status) {
    chess_status_ = chess_status;
  }

protected:
  virtual void InitChess(void);

private:
  ChessboardGrid *chessboard_grid_;
  ChessColor chess_color_;
  ChessStatus chess_status_;
  wxString chess_name_;
  int x_coordinate_;
  int y_coordinate_;
  int chess_type_;
  int chess_exp_;

  static std::map<wxString, ChessColor> kChessNameColorMap;
  static std::map<wxString, ChessType> kChessNameTypeMap;
};

#endif
