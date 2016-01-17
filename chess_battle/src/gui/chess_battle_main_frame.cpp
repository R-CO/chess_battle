/**
*** Author: R-CO
*** Mail: daniel1820kobe@gmail.com
*** Date: 2016-01-08
**/
#include "chess_battle_main_frame.h"

#include <wx/msgdlg.h>
#include <wx/dcbuffer.h>
#include <wx/socket.h>

// static const class members define
const wxBrush   ChessBattleMainFrame::kChessBoardBackgroundBrush_ = wxBrush(wxColour(255, 200, 40));

const wxColour  ChessBattleMainFrame::kChessBoardTextForegroundColour_ = wxColour(0, 0, 200);

const wxString  ChessBattleMainFrame::kLeftChessBoardString_ = wxT("起手無回大丈夫");
const wxString  ChessBattleMainFrame::kRightChessBoardString_ = wxT("觀棋不語真君子");

const wxFont    ChessBattleMainFrame::kLeftRightChessBoardTextFont_ = wxFont(32, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("標楷體"));

ChessBattleMainFrame::ChessBattleMainFrame(wxWindow* parent)
  :
  main_frame_base(parent)
{
  InitGui();
}

void ChessBattleMainFrame::PaintNow(void)
{
  wxClientDC dc(chess_board_panel_);
  wxBufferedDC buffered_dc(&dc);
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
}

void ChessBattleMainFrame::OnLeftDownChessBoardPanel(wxMouseEvent& event)
{
  // TODO: Implement OnLeftDownChessBoardPanel
}

void ChessBattleMainFrame::OnLeftUpChessBoardPanel(wxMouseEvent& event)
{
  // TODO: Implement OnLeftUpChessBoardPanel
}

void ChessBattleMainFrame::OnMotionChessBoardPanel(wxMouseEvent& event)
{
  // TODO: Implement OnMotionChessBoardPanel
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

  wxPoint p1(50, 10), p2(50, 610);
  const int gap(75);
  int i(0);

  for (i = 0; i < 5; ++i) {
    p1 = wxPoint(50 + gap*i, 10);
    p2 = wxPoint(50 + gap*i, 610);
    dc.DrawLine(p1, p2);
  }
  for (i = 0; i < 10; ++i) {
    p1 = wxPoint(50, 10 + gap*i);
    p2 = wxPoint(350, 10 + gap*i);
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

void ChessBattleMainFrame::InitGui(void)
{
  chess_board_panel_->SetBackgroundStyle(wxBG_STYLE_PAINT);

  wxIPV4address remote;
  remote.Hostname(wxT("www.google.com.tw"));
  remote.Service(80);

  wxIPV4address local;

  wxSocketClient client;
  if (client.Connect(remote) == true) {
    client.GetLocal(local);
  }

  wxString ipAddr = local.IPAddress();

  local_ip_static_text_->SetLabel(_T("local IP: ") + ipAddr);
}
