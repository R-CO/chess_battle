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

  chess_be_taken_ = nullptr;
}

void ChessGame::PlaceChesses()
{
  time_t seed = time(nullptr);

  for (auto &chess : chesses_) {
    int row = 0;
    int column = 0;
    GetRandomPosition(row, column, seed);
    chess_board_.SetChessOnGrid(&chess, row, column);
    chess.set_position(*(chess_board_.GetGridCenterPosition(row, column)));
    chess.set_chessboard_grid(chess_board_.get_chessboard_grid(row, column));
  }
}

bool ChessGame::IsMoveChessSuccess(const wxPoint & mouse_position, const int & chess_outer_radius)
{
  if (chess_be_taken_ != nullptr) {
    chess_be_taken_->set_position(mouse_position);
    // TODO: Implement here

    ChessboardGrid *target_chessboard_grid = chess_board_.GetChessBoardGrid(mouse_position, chess_outer_radius);
    if (target_chessboard_grid == nullptr) {
      chess_be_taken_->set_position(*(chess_be_taken_->get_chessboard_grid()->GetGridCenterPosition()));

      chess_be_taken_->set_taking(false);
      chess_be_taken_ = nullptr;
      return false;
    }

    
    if (IsLegalChessMovement(chess_be_taken_, target_chessboard_grid) == true) {
      MoveChess(target_chessboard_grid);
      chess_be_taken_->set_taking(false);
      chess_be_taken_ = nullptr;
      return true;
    } else {
      chess_be_taken_->set_position(*(chess_be_taken_->get_chessboard_grid()->GetGridCenterPosition()));

      chess_be_taken_->set_taking(false);
      chess_be_taken_ = nullptr;
      return false;
    }
  }

  return false;
}

bool ChessGame::IsOpenChessSuccess(const wxPoint & mouse_click_point, const int & chess_outer_radius)
{
  Chess *chess = GetHitChess(mouse_click_point, chess_outer_radius);
  if (chess == nullptr) {
    return false;
  }

  if (chess->get_chess_status() == kChessIsNegative) {
    chess->set_chess_status(kChessIsPositive);
    if (game_status_ == kChessGameNotStart) {
      game_status_ = kChessGameStart;
      if (chess->get_chess_color() == kBlackChess) {
        player_[0].color_ = kBlackChess;
        player_[1].color_ = kRedChess;
      } else {
        player_[0].color_ = kRedChess;
        player_[1].color_ = kBlackChess;
      }
    }
    return true;
  }

  return false;
}

bool ChessGame::IsTakeChessSuccess(const wxPoint & mouse_click_point, const int & chess_outer_radius)
{
  chess_be_taken_ = GetHitChess(mouse_click_point, chess_outer_radius);
  
  if (chess_be_taken_ != nullptr ) {
    if (chess_be_taken_->get_chess_status() != kChessIsPositive) {
      chess_be_taken_ = nullptr;
    } else {
      chess_be_taken_->set_position(mouse_click_point);
      chess_be_taken_->set_taking(true);
      return true;
    }
  }

  return false;
}

void ChessGame::Reset()
{
  ResetChesses();
  ResetChessboardGrids();
}

void ChessGame::ResetChesses(void)
{
  for (auto &chess : chesses_) {
    chess.ResetChess();
  }
}

void ChessGame::ResetChessboardGrids(void)
{
  chess_board_.ResetChessboardGrids();
}

bool ChessGame::IsLegalChessMovement(Chess * chess_be_moved, ChessboardGrid * target_chessboard_grid)
{
  // TODO: IsLegalChessMovement refactor
  static const bool kLegalMovement = true;
  static const bool kIllegalMovement = false;

  Chess *chess_on_target_grid = target_chessboard_grid->get_chess();

  const int move_distance = GetMoveDistance(chess_be_moved, target_chessboard_grid);

  if ((target_chessboard_grid->is_chess_on() == false) && (move_distance == 1)) {
    return kLegalMovement;
  } else if ((target_chessboard_grid->is_chess_on() == true) &&
             (target_chessboard_grid->get_chess()->get_chess_status() == kChessIsPositive)) {
    if (chess_be_moved->get_chess_color() == chess_on_target_grid->get_chess_color()) {
      return kIllegalMovement;
    }

    if ((chess_be_moved->get_chess_type() >= chess_on_target_grid->get_chess_type()) &&
        (chess_be_moved->get_chess_type() != kChessCannon) &&
        (move_distance == 1) &&
        ((chess_be_moved->get_chess_type() - chess_on_target_grid->get_chess_type()) != 6)) {
      chess_on_target_grid->set_chess_status(kChessIsDead);
      chess_on_target_grid->set_chessboard_grid(nullptr);
      chess_on_target_grid->set_position(wxPoint(400, 200)); // TODO: dead chess position
      return kLegalMovement;
    } else if ((chess_be_moved->get_chess_type() == kChessSoldier) &&
               (chess_on_target_grid->get_chess_type() == kChessGeneral) &&
               (move_distance == 1)) {
      chess_on_target_grid->set_chess_status(kChessIsDead);
      chess_on_target_grid->set_chessboard_grid(nullptr);
      chess_on_target_grid->set_position(wxPoint(400, 200));
      return kLegalMovement;
    } else if (chess_be_moved->get_chess_type() == kChessCannon) {
      // check whether the two chesses are on the same row/column
      if (chess_be_moved->get_chessboard_grid()->get_row() == chess_on_target_grid->get_chessboard_grid()->get_row()) {
        // count how many chesses there are on the same row between the two chesses
        int row = chess_be_moved->get_chessboard_grid()->get_row();
        int count_chesses_on_same_row = 0;
        
        if (chess_be_moved->get_chessboard_grid()->get_column() < chess_on_target_grid->get_chessboard_grid()->get_column()) {
          for (int column_index = chess_be_moved->get_chessboard_grid()->get_column() + 1;
               (column_index < kChessboardColumn) && (column_index < chess_on_target_grid->get_chessboard_grid()->get_column());
               ++column_index) {
            if (chess_board_.is_chess_on_grid(row, column_index) == true) {
              ++count_chesses_on_same_row;
            }
          }
        } else {
          for (int column_index = chess_on_target_grid->get_chessboard_grid()->get_column() + 1;
            (column_index < kChessboardColumn) && (column_index < chess_be_moved->get_chessboard_grid()->get_column());
               ++column_index) {
            if (chess_board_.is_chess_on_grid(row, column_index) == true) {
              ++count_chesses_on_same_row;
            }
          }
        }

        if (count_chesses_on_same_row == 1) {
          chess_on_target_grid->set_chess_status(kChessIsDead);
          chess_on_target_grid->set_chessboard_grid(nullptr);
          chess_on_target_grid->set_position(wxPoint(400, 200));
          return kLegalMovement;
        } else {
          return kIllegalMovement;
        }
      } else if (chess_be_moved->get_chessboard_grid()->get_column() == chess_on_target_grid->get_chessboard_grid()->get_column()) {
        // count how many chesses there are on the same column between the two chesses
        int column = chess_be_moved->get_chessboard_grid()->get_column();
        int count_chesses_on_same_column = 0;

        if (chess_be_moved->get_chessboard_grid()->get_row() < chess_on_target_grid->get_chessboard_grid()->get_row()) {
          for (int row_index = chess_be_moved->get_chessboard_grid()->get_row() + 1;
            (row_index < kChessboardRow) && (row_index < chess_on_target_grid->get_chessboard_grid()->get_row());
               ++row_index) {
            if (chess_board_.is_chess_on_grid(row_index, column) == true) {
              ++count_chesses_on_same_column;
            }
          }
        } else {
          for (int row_index = chess_on_target_grid->get_chessboard_grid()->get_row() + 1;
            (row_index < kChessboardRow) && (row_index < chess_be_moved->get_chessboard_grid()->get_row());
               ++row_index) {
            if (chess_board_.is_chess_on_grid(row_index, column) == true) {
              ++count_chesses_on_same_column;
            }
          }
        }

        if (count_chesses_on_same_column == 1) {
          chess_on_target_grid->set_chess_status(kChessIsDead);
          chess_on_target_grid->set_chessboard_grid(nullptr);
          chess_on_target_grid->set_position(wxPoint(400, 200));
          return kLegalMovement;
        } else {
          return kIllegalMovement;
        }
      } else { // two chesses are not on the same row/colum
        return kIllegalMovement;
      }
    }
  }

  return kIllegalMovement;
}

void ChessGame::MoveChess(ChessboardGrid * target_chessboard_grid)
{
  if (target_chessboard_grid == nullptr) {
    return;
  }

  chess_be_taken_->get_chessboard_grid()->SetChess(nullptr);
  chess_be_taken_->set_position(*(target_chessboard_grid->GetGridCenterPosition()));
  chess_be_taken_->set_chessboard_grid(target_chessboard_grid);
  target_chessboard_grid->SetChess(chess_be_taken_);
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

bool ChessGame::SetChessPosition(const wxPoint & mouse_position)
{
  if (chess_be_taken_ != nullptr) {
    chess_be_taken_->set_position(mouse_position);
    return true;
  }

  return false;
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

Chess * ChessGame::GetHitChess(const wxPoint &hit_point, const int &chess_outer_radius)
{
  wxPoint position_diff;
  const int chess_outer_radius_square = chess_outer_radius * chess_outer_radius;
  for (auto &chess : chesses_) {
    position_diff = hit_point - chess.get_position();
    if ((position_diff.x * position_diff.x + position_diff.y * position_diff.y)
        <= chess_outer_radius_square) {
      return &chess;
    }
  }

  return nullptr;
}

inline ChessboardGrid * ChessGame::GetHitChessBoardGrid(const wxPoint & hit_point, const int & chess_outre_radius)
{
  return chess_board_.GetChessBoardGrid(hit_point, chess_outre_radius);
}

const int ChessGame::GetMoveDistance(Chess * chess_be_moved, ChessboardGrid * target_chessboard_grid)
{
  return abs(chess_be_taken_->get_chessboard_grid()->get_row() - target_chessboard_grid->get_row()) +
         abs(chess_be_taken_->get_chessboard_grid()->get_column() - target_chessboard_grid->get_column());
}

}
