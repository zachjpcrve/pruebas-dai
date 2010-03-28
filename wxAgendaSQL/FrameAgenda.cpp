#include "FrameAgenda.h"

FrameAgenda::FrameAgenda(const wxString& titulo, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, titulo, wxDefaultPosition, size)
{
	// Lista de colores a usar: http://html-color-codes.info/codigos-de-colores-hexadecimales/
	wxColour color1;
	color1.Set(_("#4f5049"));

	// Le he cambiado el color al panel para diferenciarlo de la venta haciendo pruebas.
	panel = new wxPanel(this,wxID_ANY, wxDefaultPosition, wxSize(200,200));
	panel->SetBackgroundColour(color1);
	bRedimensionar = new wxButton(panel, -1/*wxID_ANY*/, _("&Aceptar"));
	//tcTam = new wxTextCtrl(panel,wxID_ANY,wxEmptyString, wxPoint(110, 100)); 
	//tcNombre = new wxTextCtrl(panel,wxID_ANY,wxEmptyString, wxPoint(110, 165));

	// Tutorial de Sizers: http://neume.sourceforge.net/sizerdemo/
	wxBoxSizer *bsLayout1 = new wxBoxSizer(wxHORIZONTAL);
	bsLayout1->Add(new wxStaticText(panel, -1, _("Tamaño:")), 0, wxEXPAND | wxLeft | wxTOP, 20);
	bsLayout1->Add(bRedimensionar, 1, wxEXPAND | wxRIGHT | wxLeft | wxTOP, 100);
	bsLayout1->SetSizeHints(this);

	panel->SetSizer(bsLayout1);

	Centre();
}

/*void Button::OnQuit(wxCommandEvent & WXUNUSED(event))
{
	Close(true);
}
*/
