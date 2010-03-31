#include "FramePrincipal.h"

FramePrincipal::FramePrincipal(const wxString& titulo, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, titulo, wxDefaultPosition, size)
{		
	SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	// Creo la ventana de añadir contacto.
	addContact = new FrameNuevo(_("Nuevo Contacto"), wxDefaultSize);
	
	// Creo sizer y se lo aplico al frame.
	wxBoxSizer* vSizer = new wxBoxSizer( wxVERTICAL );
	SetSizer( vSizer );
	
	// Creo la barra de menus
	barra_menu = new wxMenuBar(0);
	
	// Menu Archivo
	menu_archivo = new wxMenu();
	barra_menu->Append( menu_archivo, _("&Archivo") ); 
	menu_archivo->Insert(0,wxID_EXIT,_("&Salir"));
	
	// Menu Contacto
	menu_contacto = new wxMenu();
	barra_menu->Append( menu_contacto, _("&Contacto") ); 
	menu_contacto->Insert(0, wxID_NEW, _("&Añadir Contacto"));
	
	// Pongo la barra en la ventana
	SetMenuBar( barra_menu );
	Centre();
	
	//Conectamos el boton del menu Añadir contacto con el evento onNewContact
	Connect(wxID_NEW, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FramePrincipal::OnNewContact));
	Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(FramePrincipal::OnQuit));
	Connect(wxEVT_CLOSE_WINDOW, wxCommandEventHandler(FramePrincipal::OnQuit));
}
//--------------------------------------------------------------------------
void FramePrincipal::OnNewContact(wxCommandEvent& WXUNUSED(event)){
	if(addContact->IsVisible()){
		addContact->Restore();
	}
	else addContact->Show();
}
//---------------------------------------------------------------------------
void FramePrincipal::OnQuit(wxCommandEvent& WXUNUSED(event)){
	wxMessageDialog *dial = new wxMessageDialog(NULL,
      _("¿Seguro que quieres salir?"), _("Question"),
      wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);

  if(dial->ShowModal() == wxID_YES) {
	  addContact->Destroy();
	  Destroy();
  }
  
}