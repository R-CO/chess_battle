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

  class ChessGame
  {
  public:
    ChessGame();

    void PlaceChesses(const wxPoint &left_top_grid_center_pos, const int &grid_width); // need to set parameter left_top_grid_pos & grid_width

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

  protected:
    virtual void GetRandomPosition(int &row, int &column, const time_t &seed = time(nullptr)) const;

  private:
    Chessboard chess_board_;
    std::vector<Chess> chesses_;
    ChessGameStatus game_status_;
  };

}

#endif
