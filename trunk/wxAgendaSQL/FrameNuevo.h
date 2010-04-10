#include <wx/wx.h>

class FrameNuevo : public wxFrame
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
	
	enum {ID_bACEPTAR=wxID_HIGHEST + 1, 
			ID_tcNOMBRE};
	
	
	void OnQuit(wxCommandEvent&);
	void onNombreClick(wxCommandEvent&);
	void onKeyEvent(wxKeyEvent& eventKey);
public:
    FrameNuevo(const wxString& title, const wxSize& size);
};
