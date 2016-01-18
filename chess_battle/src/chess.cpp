/**
*** Author: R-CO
*** Mail: daniel1820kobe@gmail.com
*** Date: 2016-01-17
**/
#include "chess.h"

#include <map>
#include <vector>

const std::vector<wxString> kBlackChessNameVector = {wxT("卒"), wxT("包"), wxT("馬"), wxT("車"), wxT("象"), wxT("士"), wxT("將")};
const std::vector<wxString> kRedChessNameVector = {wxT("兵"), wxT("炮"), wxT("傌"), wxT("俥"), wxT("相"), wxT("仕"), wxT("帥")};

std::map<wxString, ChessColor> Chess::kChessNameColorMap = 
{ 
  std::pair<wxString, ChessColor>(wxT("卒"), kBlackChess),
  std::pair<wxString, ChessColor>(wxT("包"), kBlackChess),
  std::pair<wxString, ChessColor>(wxT("馬"), kBlackChess),
  std::pair<wxString, ChessColor>(wxT("車"), kBlackChess), 
  std::pair<wxString, ChessColor>(wxT("象"), kBlackChess), 
  std::pair<wxString, ChessColor>(wxT("士"), kBlackChess), 
  std::pair<wxString, ChessColor>(wxT("將"), kBlackChess),
  std::pair<wxString, ChessColor>(wxT("兵"), kRedChess),
  std::pair<wxString, ChessColor>(wxT("炮"), kRedChess),
  std::pair<wxString, ChessColor>(wxT("傌"), kRedChess),
  std::pair<wxString, ChessColor>(wxT("俥"), kRedChess),
  std::pair<wxString, ChessColor>(wxT("相"), kRedChess),
  std::pair<wxString, ChessColor>(wxT("仕"), kRedChess),
  std::pair<wxString, ChessColor>(wxT("帥"), kRedChess)
};

std::map<wxString, ChessType> Chess::kChessNameTypeMap = 
{
  std::pair<wxString, ChessType>(wxT("卒"), 0),
  std::pair<wxString, ChessType>(wxT("包"), 1),
  std::pair<wxString, ChessType>(wxT("馬"), 2),
  std::pair<wxString, ChessType>(wxT("車"), 3),
  std::pair<wxString, ChessType>(wxT("象"), 4),
  std::pair<wxString, ChessType>(wxT("士"), 5),
  std::pair<wxString, ChessType>(wxT("將"), 6),
  std::pair<wxString, ChessType>(wxT("兵"), 0),
  std::pair<wxString, ChessType>(wxT("炮"), 1),
  std::pair<wxString, ChessType>(wxT("傌"), 2),
  std::pair<wxString, ChessType>(wxT("俥"), 3),
  std::pair<wxString, ChessType>(wxT("相"), 4),
  std::pair<wxString, ChessType>(wxT("仕"), 5),
  std::pair<wxString, ChessType>(wxT("帥"), 6)
};

void Chess::ResetChess(void)
{
  InitChess();
}

void Chess::InitChess(void)
{
  chessboard_grid_ = nullptr;
  chess_color_ = get_chess_color(chess_name_);
  chess_status_ = kChessIsNegative;
  x_coordinate_ = 0;
  y_coordinate_ = 0;
  chess_type_ = get_chess_type(chess_name_);
  chess_exp_ = 0;
}
