#include "FrameAgenda.h"

FrameAgenda::FrameAgenda(const wxString& titulo, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, titulo, wxDefaultPosition, size)
{
	// Lista de colores a usar: http://html-color-codes.info/codigos-de-colores-hexadecimales/
	wxColour color1;
	color1.Set(_("#4f5049"));
	
	wxFlexGridSizer *fgs = new wxFlexGridSizer(2 ,2, 10, 30); //Layout flexible
	wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

	// Le he cambiado el color al panel para diferenciarlo de la venta haciendo pruebas.
	panel = new wxPanel(this, -1);
	panel->SetBackgroundColour(color1);
	
	//Seccion de Insercion de nombre
	tcNombre = new wxTextCtrl(panel, -1, _("Nombre..."));
	fgs->Add(new wxStaticText(panel, -1, _("Nombre:")));
	fgs->Add(tcNombre, 1, wxEXPAND);
	
	//Seccion de Apellido
	tcApellido = new wxTextCtrl(panel, -1, _("Apellidos..."));
	fgs->Add(new wxStaticText(panel, -1, _("Apellidos:")));
	fgs->Add(tcApellido, 1, wxEXPAND);
	
	//Seccion DNI
	tcDni = new wxTextCtrl(panel, -1, wxT("DNI"));
	fgs->Add(new wxStaticText(panel, -1, _("DNI:")));
	fgs->Add(tcDni, 1, wxEXPAND);
	
	fgs->AddGrowableCol(1,1); //Hacemos que se redimensione solo la columna 1
	
	//Este boxSizer horizontal lo usamos para poner 15px, de espacio entre la ventana y los widget
	hbox->Add(fgs, 1, wxALL | wxEXPAND, 15); 
	
	hbox->SetSizeHints(this);
	panel->SetSizer(hbox);

	Centre();

}

/*void Button::OnQuit(wxCommandEvent & WXUNUSED(event))
{
	Close(true);
}
*/
