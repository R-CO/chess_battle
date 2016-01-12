///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MAIN_FRAME_BASE_H__
#define __MAIN_FRAME_BASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/radiobox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class main_frame_base
///////////////////////////////////////////////////////////////////////////////
class main_frame_base : public wxFrame
{
private:

protected:
  enum
  {
    wxID_MAIN_FRAME_BASE = 1000,
    wxID_CHESS_BOARD_PANEL,
    wxID_CONTROL_PANEL,
    wxID_NEW_GAME_BUTTON,
    wxID_PLAY_MODE_RADIO_BOX,
    wxID_LOCAL_IP_STATIC_TEXT,
    wxID_IP_STATIC_TEXT,
    wxID_IP_TEXT_CTRL
  };

  wxPanel* chess_board_panel_;
  wxPanel* control_panel_;
  wxButton* new_game_button_;
  wxRadioBox* play_style_radio_box_;
  wxRadioBox* play_mode_radio_box_;
  wxStaticText* local_ip_static_text_;
  wxStaticText* ip_static_text_;
  wxTextCtrl* ip_text_ctrl_;
  wxButton* connect_button_;
  wxButton* disconnect_button_;
  wxTextCtrl* chat_history_text_ctrl_;
  wxTextCtrl* chat_input_text_ctrl_;

  // Virtual event handlers, overide them in your derived class
  virtual void OnCloseMainFrameBase(wxCloseEvent& event) { event.Skip(); }
  virtual void OnLeftDClickChessBoardPanel(wxMouseEvent& event) { event.Skip(); }
  virtual void OnLeftDownChessBoardPanel(wxMouseEvent& event) { event.Skip(); }
  virtual void OnLeftUpChessBoardPanel(wxMouseEvent& event) { event.Skip(); }
  virtual void OnMotionChessBoardPanel(wxMouseEvent& event) { event.Skip(); }
  virtual void OnPaintChessBoardPanel(wxPaintEvent& event) { event.Skip(); }
  virtual void OnButtonClickNewGame(wxCommandEvent& event) { event.Skip(); }
  virtual void OnRadioBoxPlayModeRadioBox(wxCommandEvent& event) { event.Skip(); }
  virtual void OnTextIpTextCtrl(wxCommandEvent& event) { event.Skip(); }
  virtual void OnTextMaxLenIpTextCtrl(wxCommandEvent& event) { event.Skip(); }
  virtual void OnButtonClickConnectButton(wxCommandEvent& event) { event.Skip(); }
  virtual void OnButtonClickDisconnectButton(wxCommandEvent& event) { event.Skip(); }
  virtual void OnTextChatInputTextCtrl(wxCommandEvent& event) { event.Skip(); }
  virtual void OnTextEnterChatInputTextCtrl(wxCommandEvent& event) { event.Skip(); }


public:

  main_frame_base(wxWindow* parent, wxWindowID id = wxID_MAIN_FRAME_BASE, const wxString& title = _("Chess Battle 2.0 by R-CO"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(880, 670), long style = wxCAPTION | wxCLOSE_BOX | wxMINIMIZE_BOX | wxSYSTEM_MENU | wxTAB_TRAVERSAL);

  ~main_frame_base();

};

#endif //__MAIN_FRAME_BASE_H__
