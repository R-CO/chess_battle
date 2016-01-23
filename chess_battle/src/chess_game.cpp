/**
*** Author: R-CO
*** Mail: daniel1820kobe@gmail.com
*** Date: 2016-01-20
**/
#include "chess_game.h"

#include <ctime>

#include <wx/gdicmn.h>

#include <boost/random.hpp>

#include "chess.h"

namespace rco {

ChessGame::ChessGame(const wxPoint &left_top_grid_center_pos, const int &grid_width)
  : chess_board_(left_top_grid_center_pos, grid_width)
{
  chesses_ =
  {
    Chess(kBlackChessNames[kChessSoldier]), Chess(kBlackChessNames[kChessSoldier]),   // 卒, 卒
    Chess(kBlackChessNames[kChessSoldier]), Chess(kBlackChessNames[kChessSoldier]),   // 卒, 卒
    Chess(kBlackChessNames[kChessSoldier]),                                           // 卒
    Chess(kBlackChessNames[kChessCannon]), Chess(kBlackChessNames[kChessCannon]),     // 包, 包
    Chess(kBlackChessNames[kChessHorse]), Chess(kBlackChessNames[kChessHorse]),       // 馬, 馬
    Chess(kBlackChessNames[kChessCar]), Chess(kBlackChessNames[kChessCar]),           // 車, 車
    Chess(kBlackChessNames[kChessElephant]), Chess(kBlackChessNames[kChessElephant]), // 象, 象
    Chess(kBlackChessNames[kChessWarrior]), Chess(kBlackChessNames[kChessWarrior]),   // 士, 士
    Chess(kBlackChessNames[kChessGeneral]),                                           // 將
    Chess(kRedChessNames[kChessSoldier]), Chess(kRedChessNames[kChessSoldier]),       // 兵, 兵
    Chess(kRedChessNames[kChessSoldier]), Chess(kRedChessNames[kChessSoldier]),       // 兵, 兵
    Chess(kRedChessNames[kChessSoldier]),                                             // 兵
    Chess(kRedChessNames[kChessCannon]), Chess(kRedChessNames[kChessCannon]),         // 炮, 炮
    Chess(kRedChessNames[kChessHorse]), Chess(kRedChessNames[kChessHorse]),           // 傌, 傌
    Chess(kRedChessNames[kChessCar]), Chess(kRedChessNames[kChessCar]),               // 俥, 俥
    Chess(kRedChessNames[kChessElephant]), Chess(kRedChessNames[kChessElephant]),     // 相, 相
    Chess(kRedChessNames[kChessWarrior]), Chess(kRedChessNames[kChessWarrior]),       // 仕, 仕
    Chess(kRedChessNames[kChessGeneral])                                              // 帥
  };

  left_top_grid_center_pos_ = left_top_grid_center_pos;
  grid_width_ = grid_width;

  game_status_ = kChessGameNotStart;
  game_style_ = kChessGameStyleTraditional;
  game_mode_ = kChessGameModeOnePc;
}

void ChessGame::PlaceChesses()
{
  time_t seed = time(nullptr);

  for (size_t chess_index = 0; chess_index < chesses_.size(); ++chess_index) {
    Chess *chess_ptr = &(chesses_[chess_index]);
    int row = 0;
    int column = 0;
    GetRandomPosition(row, column, seed);
    chess_board_.SetChessOnGrid(chess_ptr, row, column);
    wxPoint chess_center = *(chess_board_.GetGridCenterPosition(row, column));
    chess_ptr->set_position(chess_center);
  }
}

void ChessGame::Reset()
{
  ResetChesses();
  ResetChessboardGrids();
}

void ChessGame::ResetChesses(void)
{
  for (size_t chess_index = 0; chess_index < chesses_.size(); ++chess_index) {
    chesses_[chess_index].ResetChess();
  }
}

void ChessGame::ResetChessboardGrids(void)
{
  chess_board_.ResetChessboardGrids();
}

Chess * ChessGame::get_chess(const int &chess_number)
{
  return get_chess(static_cast<const size_t>(chess_number));
}

Chess * ChessGame::get_chess(const size_t & chess_number)
{
  if (chess_number < 0 || chess_number >= chesses_.size()) {
    return nullptr;
  } else {
    return &(chesses_[chess_number]);
  }
}

void ChessGame::GetRandomPosition(int &row, int &column, const time_t &seed) const
{
  boost::mt19937 random_engine(seed);
  boost::random_number_generator<boost::mt19937, int> random_generator(random_engine);

  do {
    row = random_generator(kChessboardRow);
    column = random_generator(kChessboardColumn);
  } while (chess_board_.is_chess_on_grid(row, column) == true);
}

}
