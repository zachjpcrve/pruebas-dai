#include <wx/wx.h>

class FrameAgenda : public wxFrame
{
private:
	
	wxPanel *panel;
	wxTextCtrl *tcNombre;
	wxTextCtrl *tcApellido;
	wxTextCtrl *tcDni;
	wxButton *bRedimensionar;	

public:
    FrameAgenda(const wxString& title, const wxSize& size);

    //void OnQuit(wxCommandEvent & event);
};