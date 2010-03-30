#include "main.h"
#include "FramePrincipal.h"
#include "FrameNuevo.h"

IMPLEMENT_APP(AgendaApp)

bool AgendaApp::OnInit()
{
	FramePrincipal *frameMain = new FramePrincipal(_("Agenda"),wxSize(900, 650));
	//FrameNuevo *frameNew = new FrameNuevo(_("Agenda"),wxSize(900, 650));
	frameMain->Show(true);
    SetTopWindow(frameMain);
	return true;
}