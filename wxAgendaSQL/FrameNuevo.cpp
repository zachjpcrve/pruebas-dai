#include "FrameNuevo.h"

FrameNuevo::FrameNuevo(const wxString& titulo, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, titulo, wxDefaultPosition, size)
{

	// Lista de colores a usar: http://html-color-codes.info/codigos-de-colores-hexadecimales/
	wxColour color1;
	color1.Set(_("#4f5049"));
	
	// Sizers
	wxFlexGridSizer *fgSizer = new wxFlexGridSizer(2 ,2, 30, 10); //Layout flexible
	wxBoxSizer *bSizer = new wxBoxSizer(wxVERTICAL);
	
	// Le he cambiado el color al panel para diferenciarlo de la venta haciendo pruebas.
	panel = new wxPanel(this, -1);
	panel->SetBackgroundColour(color1);
	
	//Seccion de Insercion de nombre
	tcNombre = new wxTextCtrl(panel, -1, _("Nombre..."), wxDefaultPosition, wxSize(150,25)); //Al primer TextCtrl le pongo tamaño para que todos se asapten a una longitud determinada
	fgSizer->Add(new wxStaticText(panel, -1, _("Nombre:")));
	fgSizer->Add(tcNombre, 1, wxEXPAND);
	
	//Seccion de Apellido
	tcApellido = new wxTextCtrl(panel, -1, _("Apellidos..."));
	fgSizer->Add(new wxStaticText(panel, -1, _("Apellidos:")));
	fgSizer->Add(tcApellido, 1, wxEXPAND);
	
	//Seccion DNI
	tcDni = new wxTextCtrl(panel, -1, wxT("DNI"));
	fgSizer->Add(new wxStaticText(panel, -1, _("DNI:")));
	fgSizer->Add(tcDni, 1, wxEXPAND);
	
	//Seccion Direccion
	tcDirec = new wxTextCtrl(panel, -1, _("Dirección"));
	fgSizer->Add(new wxStaticText(panel, -1, _("Dirección:")));
	fgSizer->Add(tcDirec, 1, wxEXPAND);
	
	//Seccion Localidad
	tcLocal = new wxTextCtrl(panel, -1, _("Localidad:"));
	fgSizer->Add(new wxStaticText(panel, -1, _("Localidad")));
	fgSizer->Add(tcLocal, 1, wxEXPAND);
	
	//Secion telefonos
	tcTlfn1 = new wxTextCtrl(panel, -1, _("Teléfono 1"));
	fgSizer->Add(new wxStaticText(panel, -1, _("Teléfono")));
	fgSizer->Add(tcTlfn1, 1, wxEXPAND);
	tcTlfn2 = new wxTextCtrl(panel, -1, _("Teléfono 2"));
	fgSizer->Add(new wxStaticText(panel, -1, _("Teléfono")));
	fgSizer->Add(tcTlfn2, 1, wxEXPAND);
	tcTlfn3 = new wxTextCtrl(panel, -1, _("Teléfono 3"));
	fgSizer->Add(new wxStaticText(panel, -1, _("Teléfono")));
	fgSizer->Add(tcTlfn3, 1, wxEXPAND);
	
	fgSizer->AddGrowableCol(1,1); //Hacemos que se redimensione solo la columna 1
	
	//Este boxSizer horizontal lo usamos para poner 15px, de espacio entre la ventana y los widget
	bSizer->Add(fgSizer, 1, wxALL | wxEXPAND, 15); 
	
	//Boton Aceptar
	bAceptar = new wxButton(panel, -1, _("&Aceptar"));
	bSizer->Add(bAceptar, 1, wxEXPAND); 
	
	panel->SetSizer(bSizer);

	Centre();

}

/*void Button::OnQuit(wxCommandEvent & WXUNUSED(event))
{
	Close(true);
}
*/
