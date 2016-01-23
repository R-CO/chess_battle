/**
*** Author: R-CO
*** Mail: daniel1820kobe@gmail.com
*** Date: 2016-01-08
**/
#include "main.h"

#include "gui/chess_battle_main_frame.h"

namespace rco {

IMPLEMENT_APP(ChessBattleApp)

bool ChessBattleApp::OnInit()
{
  ChessBattleMainFrame *chess_battle_main_frame = new ChessBattleMainFrame(nullptr);

  return chess_battle_main_frame->Show();
}

}
