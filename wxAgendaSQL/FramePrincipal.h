#include <wx/wx.h>
#include <wx/grid.h>
#include "FrameNuevo.h"

class FramePrincipal : public wxFrame
{
private:
	wxPanel *panel;
	FrameNuevo* addContact;
	wxMenuBar* barra_menu;
	wxMenu* menu_archivo;
	wxMenu* menu_contacto;
	wxToolBar* barra_herramientas;
	wxGrid* gContactos;
	

	//iremos asignando un Id para todos los evento que queramos
	enum {ID_NEW=wxID_HIGHEST + 1};
	
	void OnNewContact(wxCommandEvent& event);
	void OnQuit(wxCommandEvent& event);
public:
    FramePrincipal(const wxString& title, const wxSize& size);
};