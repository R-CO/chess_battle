/**
*** Author: R-CO
*** Mail: daniel1820kobe@gmail.com
*** Date: 2016-01-08
***/
#include "main.h"

#include <wx/wx.h>

// Include main_frame.h here

IMPLEMENT_APP(ChessBattleApp)

bool ChessBattleApp::OnInit()
{
  wxFrame *main_frame = new wxFrame(NULL, wxID_ANY, wxT("hello world!"));

  return main_frame->Show();
}
