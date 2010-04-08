#include "FramePrincipal.h"
#include "ClassAgenda.h"

Agenda* miAgenda;

FramePrincipal::FramePrincipal(const wxString& titulo, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, titulo, wxDefaultPosition, size)
{		
	 panel = new wxPanel(this, -1);
	
	// Creo la ventana de añadir contacto.
	addContact = new FrameNuevo(_("Nuevo Contacto"), wxDefaultSize);

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
	barra_herramientas->AddTool(wxID_NEW, imgAdd , _("Añadir nuevo contacto"));
	barra_herramientas->Realize();

	// Creo el Grid
	gContactos = new wxGrid(panel, wxID_ANY,wxDefaultPosition, wxDefaultSize);
	gContactos->CreateGrid(12, 8);	// Numero de filas y columnas
	wxString columnas[8] = {_("Nombre"),_("Apellido"),_("DNI"),_("Direccion"),_("Localidad"),_("Telefono1"),_("Telefono2"),_("Telefono3")};
	for(int i=0; i<8;i++)
		gContactos->SetColLabelValue(i,columnas[i]);
	
	// Creo sizer y se lo aplico al frame.
	wxBoxSizer* vSizer = new wxBoxSizer( wxVERTICAL );
	vSizer->Add(gContactos,1,wxEXPAND);	// no funciona, no se expande y tal.
	
	panel->SetSizer( vSizer );
	vSizer->SetSizeHints(this);

	// Centramos
	Centre();
	
	//Empezamos a crear lo necesario para la agenda
	miAgenda = new Agenda(); 
	
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
