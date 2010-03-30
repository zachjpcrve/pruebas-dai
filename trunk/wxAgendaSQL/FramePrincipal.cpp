#include "FramePrincipal.h"


FramePrincipal::FramePrincipal(const wxString& titulo, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, titulo, wxDefaultPosition, size)
{		
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	// Creo sizer y se lo aplico al frame.
	wxBoxSizer* bSizer = new wxBoxSizer( wxVERTICAL );
	this->SetSizer( bSizer );
	
	// Creo la barra de menus
	barra_menu = new wxMenuBar( 0 );
	
	// Menu Archivo
	menu_archivo = new wxMenu();
	barra_menu->Append( menu_archivo, _("&Archivo") ); 
	menu_archivo->Insert(0,wxID_ANY,_("&Salir"));
	
	// Menu Contacto
	menu_contacto = new wxMenu();
	barra_menu->Append( menu_contacto, _("&Contacto") ); 
	menu_contacto->Insert(0,wxID_ANY,_("&Añadir Contacto"));
	
	// Pongo la barra en la ventana
	this->SetMenuBar( barra_menu );
	this->Centre();
	
}