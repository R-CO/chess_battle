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
*** Date: 2016-01-19
**/
#ifndef CHESS_BATTLE_CHESS_GAME_H
#define CHESS_BATTLE_CHESS_GAME_H

#include <ctime>

#include <vector>

#include <wx/gdicmn.h>

#include "chess.h"
#include "chessboard.h"

namespace rco {

  enum ChessGameStatus
  {
    kChessGameNotStart = 0,
    kChessGameStart = 1,
  };

  enum ChessGameStyle
  {
    kChessGameStyleTraditional = 0,
    kChessGameStyleNew = 1,
  };

  enum ChessGameMode
  {
    kChessGameModeOnePc = 0,
    kChessGameModeConnection = 1,
  };

  enum ChessNowPlayer
  {
    kPlayerOne = 1,
    kPlayerTwo = 2,
  };

  struct Player
  {
    Player() {
      color_ = kRedChess;
      moved_ = false;
    }

    ChessColor color_;
    bool moved_;
  };

  class ChessGame
  {
  public:
    ChessGame(const wxPoint &left_top_grid_center_pos, const int &grid_width); // need to set parameter left_top_grid_pos & grid_width

    void PlaceChesses(); 
    // TODO: MoveChess isn't ready.
    bool MoveChess(const wxPoint &mouse_position, const int &chess_outer_radius);
    bool OpenChess(const wxPoint &mouse_click_point, const int &chess_outer_radius);
    bool TakeChess(const wxPoint &mouse_click_point, const int &chess_outer_radius);

    void Reset();

    // get function

    inline const size_t get_number_of_chesses(void) const {
      return chesses_.size();
    }

    // To return a pointer of the private member is not a good idea but it is convenient. May need a better way to do this.
    Chess *get_chess(const int &chess_number);
    Chess *get_chess(const size_t &chess_number);

    inline const ChessGameStatus get_game_status(void) const {
      return game_status_;
    }

    // set function

    inline void set_game_status(const ChessGameStatus &game_status) {
      game_status_ = game_status;
    }

    inline void set_game_sytle(const ChessGameStyle &game_style) {
      game_style_ = game_style;
    }

    inline void set_game_mode(const ChessGameMode &game_mode) {
      game_mode_ = game_mode;
    }

    bool SetChessPosition(const wxPoint &mouse_position);

  protected:
    virtual void GetRandomPosition(int &row, int &column, const time_t &seed = time(nullptr)) const;
    
    Chess *GetHitChess(const wxPoint &hit_point, const int &chess_outer_radius);
    ChessboardGrid *GetHitChessBoardGrid(const wxPoint &hit_point, const int &chess_outer_radius);

    void ResetChesses(void);
    void ResetChessboardGrids(void);

    Chessboard chess_board_;
    std::vector<Chess> chesses_;
    Player player_[2];
    int current_player_;

    Chess *chess_be_taken_;

    wxPoint chess_old_position;

    wxPoint left_top_grid_center_pos_;
    int grid_width_;

    ChessGameStatus game_status_;
    ChessGameStyle game_style_;
    ChessGameMode game_mode_;
  };

}

#endif
