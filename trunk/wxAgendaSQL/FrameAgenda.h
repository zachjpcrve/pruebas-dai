#include <wx/wx.h>

class FrameAgenda : public wxFrame
{
private:
	
	wxPanel *panel;
	wxTextCtrl *tcNombre;
	wxTextCtrl *tcApellido;
	wxTextCtrl *tcDni;
	wxTextCtrl *tcDirec;
	wxTextCtrl *tcLocal;
	wxTextCtrl *tcTlfn1;
	wxTextCtrl *tcTlfn2;
	wxTextCtrl *tcTlfn3;
	wxButton *bAceptar;

public:
    FrameAgenda(const wxString& title, const wxSize& size);

    //void OnQuit(wxCommandEvent & event);
};