/**
*** Author: R-CO
*** Mail: daniel1820kobe@gmail.com
*** Date: 2016-01-08
**/
#include "main.h"

#include "gui/chess_battle_main_frame.h"

IMPLEMENT_APP(ChessBattleApp)

bool ChessBattleApp::OnInit()
{
  ChessBattleMainFrame *chess_battle_main_frame = new ChessBattleMainFrame(NULL);

  return chess_battle_main_frame->Show();
}
