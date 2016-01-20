/**
*** Author: R-CO
*** Mail: daniel1820kobe@gmail.com
*** Date: 2016-01-17
**/
#include "chess.h"

#include <map>
#include <vector>

const std::vector<wxString> kBlackChessNameVector = 
{
  wxT("卒") /* 0 */, wxT("包") /* 1 */, wxT("馬") /* 2 */, wxT("車") /* 3 */,	wxT("象") /* 4 */, wxT("士") /* 5 */, wxT("將") /* 6 */
};
const std::vector<wxString> kRedChessNameVector = 
{
  wxT("兵") /* 0 */, wxT("炮") /* 1 */, wxT("傌") /* 2 */, wxT("俥") /* 3 */, wxT("相") /* 4 */, wxT("仕") /* 5 */, wxT("帥") /* 6 */
};

std::map<wxString, ChessColor> Chess::kChessNameColorMap = 
{ 
  std::pair<wxString, ChessColor>(kBlackChessNameVector[0], kBlackChess), // wxT("卒")
  std::pair<wxString, ChessColor>(kBlackChessNameVector[1], kBlackChess), // wxT("包")
  std::pair<wxString, ChessColor>(kBlackChessNameVector[2], kBlackChess), // wxT("馬")
  std::pair<wxString, ChessColor>(kBlackChessNameVector[3], kBlackChess), // wxT("車")
  std::pair<wxString, ChessColor>(kBlackChessNameVector[4], kBlackChess), // wxT("象")
  std::pair<wxString, ChessColor>(kBlackChessNameVector[5], kBlackChess), // wxT("士")
  std::pair<wxString, ChessColor>(kBlackChessNameVector[6], kBlackChess), // wxT("將")
  std::pair<wxString, ChessColor>(kRedChessNameVector[0], kRedChess),         // wxT("兵")
  std::pair<wxString, ChessColor>(kRedChessNameVector[1], kRedChess),         // wxT("炮")
  std::pair<wxString, ChessColor>(kRedChessNameVector[2], kRedChess),         // wxT("傌")
  std::pair<wxString, ChessColor>(kRedChessNameVector[3], kRedChess),         // wxT("俥")
  std::pair<wxString, ChessColor>(kRedChessNameVector[4], kRedChess),         // wxT("相")
  std::pair<wxString, ChessColor>(kRedChessNameVector[5], kRedChess),         // wxT("仕")
  std::pair<wxString, ChessColor>(kRedChessNameVector[6], kRedChess)          // wxT("帥")
};

std::map<wxString, ChessType> Chess::kChessNameTypeMap = 
{
  std::pair<wxString, ChessType>(kBlackChessNameVector[0], 0), // wxT("卒")
  std::pair<wxString, ChessType>(kBlackChessNameVector[1], 1), // wxT("包")
  std::pair<wxString, ChessType>(kBlackChessNameVector[2], 2), // wxT("馬")
  std::pair<wxString, ChessType>(kBlackChessNameVector[3], 3), // wxT("車")
  std::pair<wxString, ChessType>(kBlackChessNameVector[4], 4), // wxT("象")
  std::pair<wxString, ChessType>(kBlackChessNameVector[5], 5), // wxT("士")
  std::pair<wxString, ChessType>(kBlackChessNameVector[6], 6), // wxT("將")
  std::pair<wxString, ChessType>(kRedChessNameVector[0], 0),     // wxT("兵")
  std::pair<wxString, ChessType>(kRedChessNameVector[1], 1),     // wxT("炮")
  std::pair<wxString, ChessType>(kRedChessNameVector[2], 2),     // wxT("傌")
  std::pair<wxString, ChessType>(kRedChessNameVector[3], 3),     // wxT("俥")
  std::pair<wxString, ChessType>(kRedChessNameVector[4], 4),     // wxT("相")
  std::pair<wxString, ChessType>(kRedChessNameVector[5], 5),     // wxT("仕")
  std::pair<wxString, ChessType>(kRedChessNameVector[6], 6)      // wxT("帥")
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
