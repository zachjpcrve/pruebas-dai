#include "FrameAgenda.h"

FrameAgenda::FrameAgenda(const wxString& titulo, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, titulo, wxDefaultPosition, size)
{
	panel = new wxPanel(this,wxID_ANY,wxDefaultPosition,wxDefaultSize);
	
	stTam = new wxStaticText(panel, wxID_ANY, wxT("Tamaño:"),wxPoint(50,105));
	eRedimensionar = new wxTextCtrl(panel,wxID_ANY,wxEmptyString, wxPoint(110, 100)); 
	bRedimensionar = new wxButton(panel, wxID_ANY, wxT("&Aceptar"), wxPoint(190, 100));
	
	stNombre = new wxStaticText(panel, wxID_ANY, wxT("&Nombre:"), wxPoint(50,170));
	tcNombre = new wxTextCtrl(panel,wxID_ANY,wxEmptyString, wxPoint(110, 165));
	
	
	Centre();
}

/*void Button::OnQuit(wxCommandEvent & WXUNUSED(event))
{
	Close(true);
}
*/
