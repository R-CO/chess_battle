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
*** Date: 2016-01-08
**/
#include "chess_battle_main_frame.h"

#include <wx/msgdlg.h>
#include <wx/dcbuffer.h>
#include <wx/socket.h>

#include "../chess.h"

// TODO: To change the implementation of painting.

namespace rco {

// static const class members define begin
const wxBrush   ChessBattleMainFrame::kChessBoardBackgroundBrush_ = wxBrush(wxColour(255, 200, 40));

const wxColour  ChessBattleMainFrame::kChessBoardTextForegroundColour_ = wxColour(0, 0, 200);

const wxString  ChessBattleMainFrame::kLeftChessBoardString_ = wxT("起手無回大丈夫");
const wxString  ChessBattleMainFrame::kRightChessBoardString_ = wxT("觀棋不語真君子");

const wxFont    ChessBattleMainFrame::kLeftRightChessBoardTextFont_ = wxFont(32, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("標楷體"));

// for drawing chess settings begin
const wxColour  ChessBattleMainFrame::kChessBackColour_ = wxColour(130, 0, 100);
const wxColour  ChessBattleMainFrame::kChessFrontColour_ = *wxWHITE;
const wxBrush   ChessBattleMainFrame::kChessBackBrush_ = wxBrush(ChessBattleMainFrame::kChessBackColour_);
const wxBrush   ChessBattleMainFrame::kChessFrontBrush_ = wxBrush(ChessBattleMainFrame::kChessFrontColour_);

const wxColour  ChessBattleMainFrame::kBlackChessColour_ = *wxBLACK;
const wxColour  ChessBattleMainFrame::kRedChessColour_ = *wxRED;

const int       ChessBattleMainFrame::kChessFontSize_ = 35;
const wxFont    ChessBattleMainFrame::kChessFont_ = wxFont(ChessBattleMainFrame::kChessFontSize_, wxSWISS, 
                                                           wxNORMAL, wxNORMAL, false, wxT("標楷體"));

const wxPen     ChessBattleMainFrame::kBlackPenForInnerCircle_ = wxPen(ChessBattleMainFrame::kBlackChessColour_, 2);
const wxPen     ChessBattleMainFrame::kRedPenForInnerCircle_ = wxPen(ChessBattleMainFrame::kRedChessColour_, 2);

const wxPoint   ChessBattleMainFrame::kLeftTopGridCenterPos_ = wxPoint(87, 47);

const int       ChessBattleMainFrame::kChessGridWidth_ = 75;
const int       ChessBattleMainFrame::kChessInnerRadius_ = ChessBattleMainFrame::kChessFontSize_ - 7;
const int       ChessBattleMainFrame::kChessOuterRadius_ = ChessBattleMainFrame::kChessInnerRadius_ + 3;
const int       ChessBattleMainFrame::kChessTextXCoordinateOffset_ = -23;
const int       ChessBattleMainFrame::kChessTextYCoordinateOffset_ = -23;
// for drawing chess settings begin end

// static const class members define end

ChessBattleMainFrame::ChessBattleMainFrame(wxWindow* parent)
  :
  main_frame_base(parent), chess_game_(ChessBattleMainFrame::kLeftTopGridCenterPos_, kChessGridWidth_),
  chess_board_panel_dc_(chess_board_panel_)
{
  InitGui();
}

void ChessBattleMainFrame::PaintNow(void)
{
  //wxClientDC dc(chess_board_panel_);
  wxBufferedDC buffered_dc(&chess_board_panel_dc_);
  Render(buffered_dc);
}

void ChessBattleMainFrame::OnCloseMainFrameBase(wxCloseEvent& event)
{
  // TODO: Implement OnCloseMainFrameBase
  Destroy();
}

void ChessBattleMainFrame::OnLeftDClickChessBoardPanel(wxMouseEvent& event)
{
  // TODO: Implement OnLeftDClickChessBoardPanel
  if (chess_game_.IsOpenChessSuccess(event.GetLogicalPosition(chess_board_panel_dc_), kChessOuterRadius_) == true) {
    PaintNow();
  }
}

void ChessBattleMainFrame::OnLeftDownChessBoardPanel(wxMouseEvent& event)
{
  // TODO: Implement OnLeftDownChessBoardPanel
  if (chess_game_.IsTakeChessSuccess(event.GetLogicalPosition(chess_board_panel_dc_), kChessOuterRadius_) == true) {
    PaintNow();
  }
}

void ChessBattleMainFrame::OnLeftUpChessBoardPanel(wxMouseEvent& event)
{
  // TODO: Implement OnLeftUpChessBoardPanel
  if (chess_game_.IsMoveChessSuccess(event.GetLogicalPosition(chess_board_panel_dc_), kChessOuterRadius_) == true) {
    
  }

  PaintNow();
}

void ChessBattleMainFrame::OnMotionChessBoardPanel(wxMouseEvent& event)
{
  // TODO: Implement OnMotionChessBoardPanel
  if (chess_game_.SetChessPosition(event.GetLogicalPosition(chess_board_panel_dc_)) == true) {
    PaintNow();
  }
}

void ChessBattleMainFrame::OnPaintChessBoardPanel(wxPaintEvent& event)
{
  // TODO: Implement OnPaintChessBoardPanel
  wxBufferedPaintDC dc(chess_board_panel_);
  Render(dc);
  //PaintNow();
}

void ChessBattleMainFrame::OnButtonClickNewGame(wxCommandEvent& event)
{
  // TODO: Implement OnButtonClickNewGame
  chess_game_.set_game_status(kChessGameStart);
  chess_game_.set_game_sytle(static_cast<ChessGameStyle>(main_frame_base::play_style_radio_box_->GetSelection()));
  chess_game_.set_game_mode(static_cast<ChessGameMode>(main_frame_base::play_mode_radio_box_->GetSelection()));

  chess_game_.Reset();
  chess_game_.PlaceChesses();

  PaintNow();
}

void ChessBattleMainFrame::OnRadioBoxPlayModeRadioBox(wxCommandEvent& event)
{
  // TODO: Implement OnRadioBoxPlayModeRadioBox
}

void ChessBattleMainFrame::OnTextIpTextCtrl(wxCommandEvent& event)
{
  // TODO: Implement OnTextIpTextCtrl
}

void ChessBattleMainFrame::OnTextMaxLenIpTextCtrl(wxCommandEvent& event)
{
  // TODO: Implement OnTextMaxLenIpTextCtrl
}

void ChessBattleMainFrame::OnButtonClickConnectButton(wxCommandEvent& event)
{
  // TODO: Implement OnButtonClickConnectButton
}

void ChessBattleMainFrame::OnButtonClickDisconnectButton(wxCommandEvent& event)
{
  // TODO: Implement OnButtonClickDisconnectButton
}

void ChessBattleMainFrame::OnTextChatInputTextCtrl(wxCommandEvent& event)
{
  // TODO: Implement OnTextChatInputTextCtrl
}

void ChessBattleMainFrame::OnTextEnterChatInputTextCtrl(wxCommandEvent& event)
{
  // TODO: Implement OnTextEnterChatInputTextCtrl
}

void ChessBattleMainFrame::Render(wxDC &dc)
{
  wxBrush old_brush = dc.GetBackground();

  DrawChessBoard(dc);
  if (chess_game_.get_game_status() != kChessGameNotStart) {
    DrawAllChesses(dc);
  }

  dc.SetBackground(old_brush);
}

void ChessBattleMainFrame::DrawChessBoard(wxDC &dc)
{
  dc.SetBackground(kChessBoardBackgroundBrush_);
  dc.Clear();

  DrawLines(dc);
  DrawText(dc);
  //DrawGameState(dc);
}

void ChessBattleMainFrame::DrawLines(wxDC & dc)
{
  wxPen old_pen = dc.GetPen();
  dc.SetPen(*wxBLACK_PEN);

  wxPoint p1(50, 10);
  wxPoint p2(50, 610);
  int i(0);

  for (i = 0; i < 5; ++i) {
    p1 = wxPoint(50 + kChessGridWidth_*i, 10);
    p2 = wxPoint(50 + kChessGridWidth_*i, 610);
    dc.DrawLine(p1, p2);
  }
  for (i = 0; i < 10; ++i) {
    p1 = wxPoint(50, 10 + kChessGridWidth_*i);
    p2 = wxPoint(350, 10 + kChessGridWidth_*i);
    dc.DrawLine(p1, p2);
  }

  dc.DrawLine(50, 235, 200, 385);
  dc.DrawLine(50, 385, 200, 235);
  dc.SetPen(old_pen);

  DrawDetail(dc, wxPoint(200, 85), false);
  DrawDetail(dc, wxPoint(200, 535), false);
  DrawDetail(dc, wxPoint(275, 160), false);
  DrawDetail(dc, wxPoint(275, 310), false);
  DrawDetail(dc, wxPoint(275, 460), false);
  DrawDetail(dc, wxPoint(200, 85), true);
  DrawDetail(dc, wxPoint(200, 535), true);
  DrawDetail(dc, wxPoint(275, 160), true);
  DrawDetail(dc, wxPoint(275, 310), true);
  DrawDetail(dc, wxPoint(275, 460), true);
  DrawDetail(dc, wxPoint(275, 10), false);
  DrawDetail(dc, wxPoint(275, 610), true);
}

void ChessBattleMainFrame::DrawText(wxDC & dc)
{
  wxFont old_font = dc.GetFont();
  wxColour old_text_foreground = dc.GetTextForeground();
  static const int gap = 80;
  size_t i(0);

  dc.SetFont(kLeftRightChessBoardTextFont_);
  dc.SetTextForeground(kChessBoardTextForegroundColour_);
  for (i = 0; i < kRightChessBoardString_.size(); ++i) {
    dc.DrawText(kRightChessBoardString_[i], 355, (50 + gap * i));
  }
  for (i = 0; i < kLeftChessBoardString_.size(); ++i) {
    dc.DrawText(kLeftChessBoardString_[i], 5, 50 + gap*i);
  }

  dc.SetFont(old_font);
  dc.SetTextForeground(old_text_foreground);
}

void ChessBattleMainFrame::DrawDetail(wxDC & dc, const wxPoint & center, const bool & fixed)
{
  wxPen old_pen = dc.GetPen();
  dc.SetPen(*wxBLACK_PEN);
  int adjust;

  if (fixed) {
    adjust = 1;
  } else {
    adjust = -1;
  }

  dc.DrawLine(center.x - 25, center.y - (5 * adjust), center.x - 5, center.y - (5 * adjust));
  dc.DrawLine(center.x + 5, center.y - (5 * adjust), center.x + 25, center.y - (5 * adjust));
  dc.DrawLine(center.x - 5, center.y - (5 * adjust), center.x - 5, center.y - (25 * adjust));
  dc.DrawLine(center.x + 5, center.y - (5 * adjust), center.x + 5, center.y - (25 * adjust));

  dc.SetPen(old_pen);
}

void ChessBattleMainFrame::DrawChess(wxDC & dc, const Chess &chess)
{
  switch (chess.get_chess_status()) {
  case kChessIsNegative:
    DrawNegativeChess(dc, chess);
    break;

  case kChessIsPositive:
    DrawPostiveChess(dc, chess);
    break;

  case kChessIsDead:
    DrawDeadChess(dc, chess);
    break;
  }
}

void ChessBattleMainFrame::DrawChess(wxDC & dc, const Chess * chess)
{
  DrawChess(dc, *chess);
}

void ChessBattleMainFrame::DrawNegativeChess(wxDC & dc, const Chess & chess)
{
  wxBrush old_brush = dc.GetBrush();
  wxColour old_text_foreground = dc.GetTextForeground();
  wxFont old_font = dc.GetFont();
  wxPen old_pen = dc.GetPen();

  dc.SetBrush(kChessBackBrush_);
  dc.DrawCircle(chess.get_position(), kChessOuterRadius_);

  dc.SetBrush(old_brush);
  dc.SetFont(old_font);
  dc.SetPen(old_pen);
  dc.SetTextForeground(old_text_foreground);
}

void ChessBattleMainFrame::DrawPostiveChess(wxDC & dc, const Chess & chess)
{
  wxBrush old_brush = dc.GetBrush();
  wxColour old_text_foreground = dc.GetTextForeground();
  wxFont old_font = dc.GetFont();
  wxPen old_pen = dc.GetPen();

  
  dc.SetBrush(kChessFrontBrush_);
  dc.DrawCircle(chess.get_position(), kChessOuterRadius_);

  switch (chess.get_chess_color()) {
  case kBlackChess:
    dc.SetPen(kBlackPenForInnerCircle_);
    dc.SetTextForeground(kBlackChessColour_);
    break;

  case kRedChess:
    dc.SetPen(kRedPenForInnerCircle_);
    dc.SetTextForeground(kRedChessColour_);
    break;
  }
  dc.DrawCircle(chess.get_position(), kChessInnerRadius_);

  dc.SetFont(kChessFont_);
  dc.DrawText(chess.get_chess_name(),
              (chess.get_position() + wxPoint(kChessTextXCoordinateOffset_, kChessTextYCoordinateOffset_)));

  dc.SetBrush(old_brush);
  dc.SetFont(old_font);
  dc.SetPen(old_pen);
  dc.SetTextForeground(old_text_foreground);
}

void ChessBattleMainFrame::DrawDeadChess(wxDC & dc, const Chess & chess)
{
  wxBrush old_brush = dc.GetBrush();
  wxColour old_text_foreground = dc.GetTextForeground();
  wxFont old_font = dc.GetFont();
  wxPen old_pen = dc.GetPen();

  // TODO: To draw dead chess

  dc.SetBrush(old_brush);
  dc.SetFont(old_font);
  dc.SetPen(old_pen);
  dc.SetTextForeground(old_text_foreground);
}

void ChessBattleMainFrame::DrawAllChesses(wxDC & dc)
{
  Chess *chess = nullptr;
  Chess *chess_be_taken = nullptr;
  for (size_t chess_index = 0; chess_index < chess_game_.get_number_of_chesses(); ++chess_index) {
    chess = chess_game_.get_chess(chess_index);
    if (chess->get_taking() == true) {
      chess_be_taken = chess;
      continue;
    }
    DrawChess(dc, (*chess));
  }

  if (chess_be_taken != nullptr) {
    DrawChess(dc, (*chess_be_taken));
  }
}

void ChessBattleMainFrame::InitGui(void)
{
  chess_board_panel_->SetBackgroundStyle(wxBG_STYLE_PAINT);

  wxIPV4address remote;
  remote.Hostname(wxT("www.google.com"));
  remote.Service(80);

  wxIPV4address local;

  wxSocketClient client;
  if (client.Connect(remote) == true) {
    client.GetLocal(local);
  }

  wxString ipAddr = local.IPAddress();

  local_ip_static_text_->SetLabel(_T("local IP: ") + ipAddr);
}

}
