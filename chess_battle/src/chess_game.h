/**
*** Author: R-CO
*** Mail: daniel1820kobe@gmail.com
*** Date: 2016-01-19
**/
#ifndef CHESS_BATTLE_CHESS_GAME_H
#define CHESS_BATTLE_CHESS_GAME_H

#include <vector>

#include "chess.h"
#include "chessboard.h"

enum ChessGameStatus
{
  kChessGameNotStart = 0,
  kChessGameStart = 1,
};

class ChessGame
{
public:
  ChessGame();

  // get function

  inline const size_t get_number_of_chesses(void) {
    return chesses_.size();
  }

  Chess *get_chess(int chess_number);

  // set function

protected:

private:
  Chessboard chess_board_;
  std::vector<Chess> chesses_;
};

#endif
