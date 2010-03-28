#include "main.h"
#include "FrameAgenda.h"

IMPLEMENT_APP(AgendaApp)

bool AgendaApp::OnInit()
{
	FrameAgenda *frame = new FrameAgenda(_("Agenda"),wxSize(900, 650));
	frame->Show(true);
    SetTopWindow(frame);
	return true;
}



