#include "main.h"
#include "FrameAgenda.h"

IMPLEMENT_APP(AgendaApp)

bool AgendaApp::OnInit()
{
	FrameAgenda *frame = new FrameAgenda(wxT("HOLA"),wxSize(768, 700));
	frame->Show(true);
    SetTopWindow(frame);
	return true;
}



