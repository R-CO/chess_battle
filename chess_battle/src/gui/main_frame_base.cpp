///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "main_frame_base.h"

///////////////////////////////////////////////////////////////////////////

main_frame_base::main_frame_base( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	chess_board_panel_ = new wxPanel( this, wxID_CHESS_BOARD_PANEL, wxDefaultPosition, wxSize( 600,-1 ), wxNO_BORDER|wxTAB_TRAVERSAL );
	bSizer1->Add( chess_board_panel_, 1, wxALL|wxEXPAND, 0 );
	
	control_panel_ = new wxPanel( this, wxID_CONTROL_PANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	new_game_button_ = new wxButton( control_panel_, wxID_NEW_GAME_BUTTON, _("New Game!"), wxDefaultPosition, wxDefaultSize, 0 );
	new_game_button_->SetFont( wxFont( 16, 70, 90, 90, false, wxT("Comic Sans MS") ) );
	
	bSizer2->Add( new_game_button_, 0, wxALL|wxEXPAND, 5 );
	
	wxString play_style_radio_box_Choices[] = { _("Tradional"), _("New") };
	int play_style_radio_box_NChoices = sizeof( play_style_radio_box_Choices ) / sizeof( wxString );
	play_style_radio_box_ = new wxRadioBox( control_panel_, wxID_ANY, _("Play Style"), wxDefaultPosition, wxDefaultSize, play_style_radio_box_NChoices, play_style_radio_box_Choices, 1, wxRA_SPECIFY_COLS );
	play_style_radio_box_->SetSelection( 0 );
	play_style_radio_box_->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxT("Comic Sans MS") ) );
	
	bSizer2->Add( play_style_radio_box_, 0, wxALL|wxEXPAND, 5 );
	
	wxString play_mode_radio_box_Choices[] = { _("Play on one PC"), _("Wait for connection"), _("Connect to") };
	int play_mode_radio_box_NChoices = sizeof( play_mode_radio_box_Choices ) / sizeof( wxString );
	play_mode_radio_box_ = new wxRadioBox( control_panel_, wxID_PLAY_MODE_RADIO_BOX, _("Play Mode"), wxDefaultPosition, wxDefaultSize, play_mode_radio_box_NChoices, play_mode_radio_box_Choices, 3, wxRA_SPECIFY_ROWS );
	play_mode_radio_box_->SetSelection( 0 );
	play_mode_radio_box_->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxT("Comic Sans MS") ) );
	
	bSizer2->Add( play_mode_radio_box_, 0, wxALL|wxEXPAND, 5 );
	
	local_ip_static_text_ = new wxStaticText( control_panel_, wxID_LOCAL_IP_STATIC_TEXT, _("local IP: 192.168.0.1"), wxDefaultPosition, wxDefaultSize, 0 );
	local_ip_static_text_->Wrap( -1 );
	local_ip_static_text_->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxT("Comic Sans MS") ) );
	
	bSizer2->Add( local_ip_static_text_, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	ip_static_text_ = new wxStaticText( control_panel_, wxID_IP_STATIC_TEXT, _("IP:"), wxDefaultPosition, wxDefaultSize, 0 );
	ip_static_text_->Wrap( -1 );
	ip_static_text_->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxT("Comic Sans MS") ) );
	
	bSizer3->Add( ip_static_text_, 0, wxALL|wxEXPAND, 5 );
	
	ip_text_ctrl_ = new wxTextCtrl( control_panel_, wxID_IP_TEXT_CTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ip_text_ctrl_->SetMaxLength( 16 ); 
	ip_text_ctrl_->Enable( false );
	
	bSizer3->Add( ip_text_ctrl_, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer2->Add( bSizer3, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	connect_button_ = new wxButton( control_panel_, wxID_ANY, _("Connect"), wxDefaultPosition, wxDefaultSize, 0 );
	connect_button_->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxT("Comic Sans MS") ) );
	connect_button_->Enable( false );
	
	bSizer4->Add( connect_button_, 1, wxALL|wxEXPAND, 5 );
	
	disconnect_button_ = new wxButton( control_panel_, wxID_ANY, _("Disconnect"), wxDefaultPosition, wxDefaultSize, 0 );
	disconnect_button_->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxT("Comic Sans MS") ) );
	disconnect_button_->Enable( false );
	
	bSizer4->Add( disconnect_button_, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer2->Add( bSizer4, 0, wxEXPAND, 5 );
	
	chat_history_text_ctrl_ = new wxTextCtrl( control_panel_, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH2 );
	chat_history_text_ctrl_->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxT("Comic Sans MS") ) );
	chat_history_text_ctrl_->Enable( false );
	
	bSizer2->Add( chat_history_text_ctrl_, 1, wxALL|wxEXPAND, 5 );
	
	chat_input_text_ctrl_ = new wxTextCtrl( control_panel_, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxTE_MULTILINE|wxTE_RICH2 );
	chat_input_text_ctrl_->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxT("Comic Sans MS") ) );
	chat_input_text_ctrl_->Enable( false );
	
	bSizer2->Add( chat_input_text_ctrl_, 0, wxALL|wxEXPAND, 5 );
	
	
	control_panel_->SetSizer( bSizer2 );
	control_panel_->Layout();
	bSizer2->Fit( control_panel_ );
	bSizer1->Add( control_panel_, 1, wxEXPAND | wxALL, 0 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( main_frame_base::OnCloseMainFrameBase ) );
	chess_board_panel_->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( main_frame_base::OnLeftDClickChessBoardPanel ), NULL, this );
	chess_board_panel_->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( main_frame_base::OnLeftDownChessBoardPanel ), NULL, this );
	chess_board_panel_->Connect( wxEVT_LEFT_UP, wxMouseEventHandler( main_frame_base::OnLeftUpChessBoardPanel ), NULL, this );
	chess_board_panel_->Connect( wxEVT_MOTION, wxMouseEventHandler( main_frame_base::OnMotionChessBoardPanel ), NULL, this );
	chess_board_panel_->Connect( wxEVT_PAINT, wxPaintEventHandler( main_frame_base::OnPaintChessBoardPanel ), NULL, this );
	new_game_button_->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( main_frame_base::OnButtonClickNewGame ), NULL, this );
	play_style_radio_box_->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( main_frame_base::OnRadioBoxPlayModeRadioBox ), NULL, this );
	play_mode_radio_box_->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( main_frame_base::OnRadioBoxPlayModeRadioBox ), NULL, this );
	ip_text_ctrl_->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( main_frame_base::OnTextIpTextCtrl ), NULL, this );
	ip_text_ctrl_->Connect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( main_frame_base::OnTextMaxLenIpTextCtrl ), NULL, this );
	connect_button_->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( main_frame_base::OnButtonClickConnectButton ), NULL, this );
	disconnect_button_->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( main_frame_base::OnButtonClickDisconnectButton ), NULL, this );
	chat_input_text_ctrl_->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( main_frame_base::OnTextChatInputTextCtrl ), NULL, this );
	chat_input_text_ctrl_->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( main_frame_base::OnTextEnterChatInputTextCtrl ), NULL, this );
}

main_frame_base::~main_frame_base()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( main_frame_base::OnCloseMainFrameBase ) );
	chess_board_panel_->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( main_frame_base::OnLeftDClickChessBoardPanel ), NULL, this );
	chess_board_panel_->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( main_frame_base::OnLeftDownChessBoardPanel ), NULL, this );
	chess_board_panel_->Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( main_frame_base::OnLeftUpChessBoardPanel ), NULL, this );
	chess_board_panel_->Disconnect( wxEVT_MOTION, wxMouseEventHandler( main_frame_base::OnMotionChessBoardPanel ), NULL, this );
	chess_board_panel_->Disconnect( wxEVT_PAINT, wxPaintEventHandler( main_frame_base::OnPaintChessBoardPanel ), NULL, this );
	new_game_button_->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( main_frame_base::OnButtonClickNewGame ), NULL, this );
	play_style_radio_box_->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( main_frame_base::OnRadioBoxPlayModeRadioBox ), NULL, this );
	play_mode_radio_box_->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( main_frame_base::OnRadioBoxPlayModeRadioBox ), NULL, this );
	ip_text_ctrl_->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( main_frame_base::OnTextIpTextCtrl ), NULL, this );
	ip_text_ctrl_->Disconnect( wxEVT_COMMAND_TEXT_MAXLEN, wxCommandEventHandler( main_frame_base::OnTextMaxLenIpTextCtrl ), NULL, this );
	connect_button_->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( main_frame_base::OnButtonClickConnectButton ), NULL, this );
	disconnect_button_->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( main_frame_base::OnButtonClickDisconnectButton ), NULL, this );
	chat_input_text_ctrl_->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( main_frame_base::OnTextChatInputTextCtrl ), NULL, this );
	chat_input_text_ctrl_->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( main_frame_base::OnTextEnterChatInputTextCtrl ), NULL, this );
	
}
