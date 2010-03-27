#include <wx/wx.h>

class FrameAgenda : public wxFrame
{
private:
	//Usaremos un layout para que se redimensionen bien los objetos
	wxBoxSizer *bsLayout;
	
	wxPanel *panel;
	wxButton *bRedimensionar;
	wxStaticText *stTam;
	wxTextCtrl *eRedimensionar;
	wxStaticText *stNombre;
	wxTextCtrl *tcNombre;
	wxStaticText *stApellido;
	wxTextCtrl *tcApellido;
	wxStaticText *stDni;
	wxTextCtrl *tcDni;
public:
    FrameAgenda(const wxString& title, const wxSize& size);

    //void OnQuit(wxCommandEvent & event);
};