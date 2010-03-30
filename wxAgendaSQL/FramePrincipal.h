#include <wx/wx.h>

class FramePrincipal : public wxFrame
{
private:
	wxMenuBar* barra_menu;
	wxMenu* menu_archivo;
	wxMenu* menu_contacto;
	
	//iremos asignando un Id para todos los evento que queramos
	enum {ID_NEW=wxID_HIGHEST + 1};
	
	void OnNewContact(wxCommandEvent& event);
	void OnQuit(wxCommandEvent& event);
public:
    FramePrincipal(const wxString& title, const wxSize& size);
};