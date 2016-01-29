﻿//The MIT License(MIT)
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
*** Date: 2016-01-17
**/
#include "chess.h"

#include <map>
#include <vector>

namespace rco {

const std::vector<wxString> kBlackChessNames =
{
  wxT("卒") /* 0 */, wxT("包") /* 1 */, wxT("馬") /* 2 */, wxT("車") /* 3 */,	wxT("象") /* 4 */, wxT("士") /* 5 */, wxT("將") /* 6 */
};
const std::vector<wxString> kRedChessNames =
{
  wxT("兵") /* 0 */, wxT("炮") /* 1 */, wxT("傌") /* 2 */, wxT("俥") /* 3 */, wxT("相") /* 4 */, wxT("仕") /* 5 */, wxT("帥") /* 6 */
};

std::map<wxString, ChessColor> Chess::kChessNameColorMap =
{
  std::pair<wxString, ChessColor>(kBlackChessNames[0], kBlackChess), // wxT("卒")
  std::pair<wxString, ChessColor>(kBlackChessNames[1], kBlackChess), // wxT("包")
  std::pair<wxString, ChessColor>(kBlackChessNames[2], kBlackChess), // wxT("馬")
  std::pair<wxString, ChessColor>(kBlackChessNames[3], kBlackChess), // wxT("車")
  std::pair<wxString, ChessColor>(kBlackChessNames[4], kBlackChess), // wxT("象")
  std::pair<wxString, ChessColor>(kBlackChessNames[5], kBlackChess), // wxT("士")
  std::pair<wxString, ChessColor>(kBlackChessNames[6], kBlackChess), // wxT("將")
  std::pair<wxString, ChessColor>(kRedChessNames[0], kRedChess),     // wxT("兵")
  std::pair<wxString, ChessColor>(kRedChessNames[1], kRedChess),     // wxT("炮")
  std::pair<wxString, ChessColor>(kRedChessNames[2], kRedChess),     // wxT("傌")
  std::pair<wxString, ChessColor>(kRedChessNames[3], kRedChess),     // wxT("俥")
  std::pair<wxString, ChessColor>(kRedChessNames[4], kRedChess),     // wxT("相")
  std::pair<wxString, ChessColor>(kRedChessNames[5], kRedChess),     // wxT("仕")
  std::pair<wxString, ChessColor>(kRedChessNames[6], kRedChess)      // wxT("帥")
};

std::map<wxString, ChessType> Chess::kChessNameTypeMap =
{
  std::pair<wxString, ChessType>(kBlackChessNames[0], kChessSoldier),  // wxT("卒")
  std::pair<wxString, ChessType>(kBlackChessNames[1], kChessCannon),   // wxT("包")
  std::pair<wxString, ChessType>(kBlackChessNames[2], kChessHorse),    // wxT("馬")
  std::pair<wxString, ChessType>(kBlackChessNames[3], kChessCar),      // wxT("車")
  std::pair<wxString, ChessType>(kBlackChessNames[4], kChessElephant), // wxT("象")
  std::pair<wxString, ChessType>(kBlackChessNames[5], kChessWarrior),  // wxT("士")
  std::pair<wxString, ChessType>(kBlackChessNames[6], kChessGeneral),  // wxT("將")
  std::pair<wxString, ChessType>(kRedChessNames[0], kChessSoldier),    // wxT("兵")
  std::pair<wxString, ChessType>(kRedChessNames[1], kChessCannon),     // wxT("炮")
  std::pair<wxString, ChessType>(kRedChessNames[2], kChessHorse),      // wxT("傌")
  std::pair<wxString, ChessType>(kRedChessNames[3], kChessCar),        // wxT("俥")
  std::pair<wxString, ChessType>(kRedChessNames[4], kChessElephant),   // wxT("相")
  std::pair<wxString, ChessType>(kRedChessNames[5], kChessWarrior),    // wxT("仕")
  std::pair<wxString, ChessType>(kRedChessNames[6], kChessGeneral)     // wxT("帥")
};

void Chess::ResetChess(void)
{
  InitChess();
}

void Chess::InitChess(void)
{
  //chessboard_grid_ = nullptr;
  chess_color_ = get_chess_color(chess_name_);
  chess_status_ = kChessIsNegative;
  //chess_status_ = kChessIsPositive;
  chess_position_ = wxPoint(0, 0);
  chess_type_ = get_chess_type(chess_name_);
  chess_exp_ = 0;
}

}
