/**
*** Author: R-CO
*** Mail: daniel1820kobe@gmail.com
*** Date: 2016-01-17
**/
#include "chess.h"

#include <map>
#include <vector>

const std::vector<wxString> kBlackChessNameVector = {wxT("��"), wxT("�]"), wxT("��"), wxT("��"), wxT("�H"), wxT("�h"), wxT("�N")};
const std::vector<wxString> kRedChessNameVector = {wxT("�L"), wxT("��"), wxT("�X"), wxT("?"), wxT("��"), wxT("�K"), wxT("��")};

std::map<wxString, ChessColor> Chess::kChessNameColorMap = 
{ 
  std::pair<wxString, ChessColor>(wxT("��"), kBlackChess),
  std::pair<wxString, ChessColor>(wxT("�]"), kBlackChess),
  std::pair<wxString, ChessColor>(wxT("��"), kBlackChess),
  std::pair<wxString, ChessColor>(wxT("��"), kBlackChess), 
  std::pair<wxString, ChessColor>(wxT("�H"), kBlackChess), 
  std::pair<wxString, ChessColor>(wxT("�h"), kBlackChess), 
  std::pair<wxString, ChessColor>(wxT("�N"), kBlackChess),
  std::pair<wxString, ChessColor>(wxT("�L"), kRedChess),
  std::pair<wxString, ChessColor>(wxT("��"), kRedChess),
  std::pair<wxString, ChessColor>(wxT("�X"), kRedChess),
  std::pair<wxString, ChessColor>(wxT("?"), kRedChess),
  std::pair<wxString, ChessColor>(wxT("��"), kRedChess),
  std::pair<wxString, ChessColor>(wxT("�K"), kRedChess),
  std::pair<wxString, ChessColor>(wxT("��"), kRedChess)
};

std::map<wxString, ChessType> Chess::kChessNameTypeMap = 
{
  std::pair<wxString, ChessType>(wxT("��"), 0),
  std::pair<wxString, ChessType>(wxT("�]"), 1),
  std::pair<wxString, ChessType>(wxT("��"), 2),
  std::pair<wxString, ChessType>(wxT("��"), 3),
  std::pair<wxString, ChessType>(wxT("�H"), 4),
  std::pair<wxString, ChessType>(wxT("�h"), 5),
  std::pair<wxString, ChessType>(wxT("�N"), 6),
  std::pair<wxString, ChessType>(wxT("�L"), 0),
  std::pair<wxString, ChessType>(wxT("��"), 1),
  std::pair<wxString, ChessType>(wxT("�X"), 2),
  std::pair<wxString, ChessType>(wxT("?"), 3),
  std::pair<wxString, ChessType>(wxT("��"), 4),
  std::pair<wxString, ChessType>(wxT("�K"), 5),
  std::pair<wxString, ChessType>(wxT("��"), 6)
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
