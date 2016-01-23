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

  class ChessGame
  {
  public:
    ChessGame();

    void PlaceChesses(const wxPoint &left_top_grid_center_pos, const int &grid_width); // need to set parameter left_top_grid_pos & grid_width

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

  protected:
    virtual void GetRandomPosition(int &row, int &column, const time_t &seed = time(nullptr)) const;
    
    void ResetChesses(void);
    void ResetChessboardGrids(void);

  private:
    Chessboard chess_board_;
    std::vector<Chess> chesses_;
    ChessGameStatus game_status_;
    ChessGameStyle game_style_;
    ChessGameMode game_mode_;
  };

}

#endif
