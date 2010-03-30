#include <wx/wx.h>

class FramePrincipal : public wxFrame
{
private:
	wxMenuBar* barra_menu;
	wxMenu* menu_archivo;
	wxMenu* menu_contacto;
public:
    FramePrincipal(const wxString& title, const wxSize& size);
};