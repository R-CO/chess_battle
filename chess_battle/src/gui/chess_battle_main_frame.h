﻿//The MIT License(MIT)
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
*** Date: 2016-01-08
**/
#ifndef __chess_battle_main_frame__
#define __chess_battle_main_frame__

/**
@file
Subclass of main_frame_base, which is generated by wxFormBuilder.
*/

#include "main_frame_base.h"

//// end generated include

#include <vector>

#include "../chess.h"
#include "../chess_game.h"

namespace rco {

/** Implementing main_frame_base */
class ChessBattleMainFrame : public main_frame_base
{
public:
  /** Constructor */
  ChessBattleMainFrame(wxWindow* parent);

  void PaintNow(void);

protected:
  // Handlers for main_frame_base events.
  void OnCloseMainFrameBase(wxCloseEvent& event);
  void OnLeftDClickChessBoardPanel(wxMouseEvent& event);
  void OnLeftDownChessBoardPanel(wxMouseEvent& event);
  void OnLeftUpChessBoardPanel(wxMouseEvent& event);
  void OnMotionChessBoardPanel(wxMouseEvent& event);
  void OnPaintChessBoardPanel(wxPaintEvent& event);
  void OnButtonClickNewGame(wxCommandEvent& event);
  void OnRadioBoxPlayModeRadioBox(wxCommandEvent& event);
  void OnTextIpTextCtrl(wxCommandEvent& event);
  void OnTextMaxLenIpTextCtrl(wxCommandEvent& event);
  void OnButtonClickConnectButton(wxCommandEvent& event);
  void OnButtonClickDisconnectButton(wxCommandEvent& event);
  void OnTextChatInputTextCtrl(wxCommandEvent& event);
  void OnTextEnterChatInputTextCtrl(wxCommandEvent& event);

  //
  virtual void Render(wxDC &dc);
  virtual void DrawChessBoard(wxDC &dc);
  virtual void DrawLines(wxDC &dc);
  virtual void DrawText(wxDC &dc);
  virtual void DrawDetail(wxDC &dc, const wxPoint &center, const bool &fixed);
  virtual void DrawChess(wxDC &dc, const Chess &chess);
  virtual void DrawChess(wxDC &dc, const Chess *chess);
  virtual void DrawNegativeChess(wxDC &dc, const Chess &chess);
  virtual void DrawPostiveChess(wxDC &dc, const Chess &chess);
  virtual void DrawDeadChess(wxDC &dc, const Chess &chess);
  virtual void DrawAllChesses(wxDC &dc);

  void InitGui(void);


  static const wxBrush        kChessBoardBackgroundBrush_;
  static const wxColour       kChessBoardTextForegroundColour_;
  static const wxString       kLeftChessBoardString_; // wxT("觀棋不語真君子");
  static const wxString       kRightChessBoardString_; //  wxT("觀棋不語真君子");
  static const wxFont         kLeftRightChessBoardTextFont_;

  // for drawing chess settings
  static const wxBrush        kChessBackBrush_;
  static const wxBrush        kChessFrontBrush_;
  static const wxColour       kChessBackColour_;
  static const wxColour       kChessFrontColour_;
  static const wxColour       kBlackChessColour_;
  static const wxColour       kRedChessColour_;
  static const wxFont         kChessFont_;
  static const wxPen          kRedPenForInnerCircle_;
  static const wxPen          kBlackPenForInnerCircle_;
  static const wxPoint        kLeftTopGridCenterPos_;
  static const int            kChessGridWidth_;
  static const int            kChessFontSize_;
  static const int            kChessInnerRadius_;
  static const int            kChessOuterRadius_;
  static const int            kChessTextXCoordinateOffset_;
  static const int            kChessTextYCoordinateOffset_;

  ChessGame chess_game_;
};

}

#endif // __chess_battle_main_frame__
