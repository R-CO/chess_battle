/**
*** Author: R-CO
*** Mail: daniel1820kobe@gmail.com
*** Date: 2016-01-08
**/
#ifndef CHESS_BATTLE_MAIN_H
#define CHESS_BATTLE_MAIN_H

#include <wx/app.h>

// everything is under namespace "rco"
namespace rco {

class ChessBattleApp : public wxApp
{
public:
  bool OnInit();
};

DECLARE_APP(ChessBattleApp)

}

#endif
