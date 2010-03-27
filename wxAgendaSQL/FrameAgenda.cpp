#include "FrameAgenda.h"

FrameAgenda::FrameAgenda(const wxString& titulo, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, titulo, wxDefaultPosition, size)
{
	panel1 = new wxPanel(this,wxID_ANY,wxDefaultPosition,wxDefaultSize);
	bRedimencionar = new wxButton(panel1, wxID_ANY, wxT("Tamaño"), wxPoint(100, 130));
	eRedimencionar = new wxTextCtrl(panel1,wxID_ANY,wxEmptyString,wxPoint(100,100),wxDefaultSize); 
	
	bRedimencionar->SetFocus();

	Centre();
}

/*void Button::OnQuit(wxCommandEvent & WXUNUSED(event))
{
	Close(true);
}
*/

