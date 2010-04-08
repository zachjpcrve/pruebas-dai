#include <wx/wx.h>
#include <wx/grid.h>
#include "FrameNuevo.h"
#include "ClassAgenda.h"

class FramePrincipal : public wxFrame
{
private:
	// Atributos graficos
	wxPanel *panel;
	FrameNuevo* addContact;
	wxMenuBar* barra_menu;
	wxMenu* menu_archivo;
	wxMenu* menu_contacto;
	wxToolBar* barra_herramientas;
	wxGrid* gContactos;
	
	// Otros Atributos
	Agenda* miAgenda;
	
	// Atributos de IDs (usamos un Enum)
	enum {ID_NEW=wxID_HIGHEST + 1};
	
	// Atributos de Eventos
	void OnNewContact(wxCommandEvent& event);
	void OnQuit(wxCommandEvent& event);
public:
    FramePrincipal(const wxString& title, const wxSize& size);
};