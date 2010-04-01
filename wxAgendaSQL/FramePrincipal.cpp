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
	menu_archivo = new wxMenu(); 	// Menu Archivo
	barra_menu->Append( menu_archivo, _("&Archivo") ); 
	menu_archivo->Insert(0,wxID_EXIT,_("&Salir"));
	menu_contacto = new wxMenu();	// Menu Contacto
	barra_menu->Append( menu_contacto, _("&Contacto") ); 
	menu_contacto->Insert(0, wxID_NEW, _("&Añadir Contacto"));
	SetMenuBar( barra_menu ); 	// Pongo la barra en la ventana
	
	// Barra de Herramientas 
	wxBitmap imgAdd(wxT("new.png"));	// Aqui no se usa _() ya que no hay que traducir las rutas!
	barra_herramientas = CreateToolBar();
	barra_herramientas->AddTool(wxID_NEW, imgAdd , _("Exit application"));
	barra_herramientas->Realize();

	// Centramos
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