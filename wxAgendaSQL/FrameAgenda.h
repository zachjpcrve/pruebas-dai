#include <wx/wx.h>

class FrameAgenda : public wxFrame
{
private:
	wxPanel *panel1;
	wxButton *bRedimencionar;
	wxTextCtrl *eRedimencionar;
public:
    FrameAgenda(const wxString& title, const wxSize& size);

    //void OnQuit(wxCommandEvent & event);
};