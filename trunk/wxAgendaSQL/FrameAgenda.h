#include <wx/wx.h>

class FrameAgenda : public wxFrame
{
private:
	//Usaremos un layout para que se redimensionen bien los objetos
	wxBoxSizer *bsLayout1;
	
	wxPanel *panel;
	wxTextCtrl *tcTam;
	wxTextCtrl *tcNombre;
	//wxTextCtrl *tcApellido;
	//wxTextCtrl *tcDni;
	wxButton *bRedimensionar;	

public:
    FrameAgenda(const wxString& title, const wxSize& size);

    //void OnQuit(wxCommandEvent & event);
};