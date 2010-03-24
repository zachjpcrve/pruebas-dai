// Manual: http://docs.wxwidgets.org/stable/wx_contents.html

//incluyo las librerias WxWidgets completas. 
//Se podría hacer este include modularmente parte a parte, por ejemplo primero wx/window.h etc.)
#include "wx/wx.h" 

// Creamos nuestra clase aplication derivandola de la generica wxApp y le añadimos un metodo onInit.
class MiAplicacion: public wxApp
{
    virtual bool OnInit();
};

/*  Creamos nuestra ventana llamada MiFrame (miFrame sería el equivalente a Form1 en Borland).
	Creamos nuestra propia funcion constructor en la que pedimos titulo, posicion y tamaño de la ventana.
	Añadimos dos eventos a la ventana, el evento Quitar (onQuit) y el evento About (onAbout)
*/
class MiFrame: public wxFrame
{
public:

    MiFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    DECLARE_EVENT_TABLE()
};

// Un Enum es una forma simplificada de struct solo para integers muy usada en C. Si no se asigna valor la variable vale el anterior valor +1. Así ID_Quit vale 1 y ID_About vale 2. Estos numeros guardan las ID de señales del menu.
enum
{
    ID_Quit = 1,
    ID_About,
};

// Ahora asociamos cada evento del frame con su ID del enum. Este sistema de "begin... end..." deben ser plantillas de C o algo.
BEGIN_EVENT_TABLE(MiFrame, wxFrame)
    EVT_MENU(ID_Quit, MiFrame::OnQuit)
    EVT_MENU(ID_About, MiFrame::OnAbout)
END_EVENT_TABLE()


// =========================== MAIN ===================================

// IMPLEMENT_APP es una plantilla que incluye en su interior el Main() del programa. Es tan facil como mandarle la "apliccation" que has dervivado y definido y esta funcion dibuja todo y hace el main y tal. Como es una plantilla no lleva punto y coma.

IMPLEMENT_APP(MiAplicacion)


// ======================== METODOS DE CLASES ==========================

/* Definimos el "init" de nuestra aplicacion, que obviamente lo primero que hace es instanciar la clase MiFrame (Form1 en Borland) con el nombre de frame_hola_mundo. Tras instanciarla la mostramos con Show y la nombramos TopWindow (ventana principal). */
bool MiAplicacion::OnInit()
{
    MiFrame *frame_hola_mundo = new MiFrame( _("Hola Mundo"), wxPoint(50, 50),
                                  wxSize(450,340) );
    frame_hola_mundo->Show(true);
    SetTopWindow(frame_hola_mundo);
    return true;
} 

/* Constructor de nuestra ventana. 
	-Llamamos al constructor del padre del que heredó. (http://docs.wxwidgets.org/2.6/wx_wxframe.html#wxframector) "
	- Luego creamos un wxMenu (menu desplegable) y le metemos las opciones About y Exit con el texto que queramos y usando & para resltar la letra 
	que tendrá acceso directo con el ALT. 
	- Luego creamos un wxMenuBar (la barra de menus desplegables) y le metemos nuestro "menu" con el caption Archivo. Finalmente usamos SetMenuBar para
	añadir la barra al frame.
	- Creamos una barra de estado en la que pondrá Bienvenido a wxWidgets en la tipica zona inferior.
*/
MiFrame::MiFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame( NULL, -1, title, pos, size )
{
    wxMenu *miMenu = new wxMenu;

    miMenu->Append( ID_About, _("A&bout...") );
    miMenu->AppendSeparator();
    miMenu->Append( ID_Quit, _("&Salir") );

    wxMenuBar *barra = new wxMenuBar;
    barra->Append( miMenu, _("&Archivo") );

    SetMenuBar( barra );

    CreateStatusBar();
    SetStatusText( _("¡Bienvenido a wxWidgets!") );
}

// Cerramos con el evento onQuit. El parametro true de close indica que si hay varias ventanas las otras no pueden evitar que esta se cierre.
void MiFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}

// Evento About usando los equivalentes a showmessage del borland. http://docs.wxwidgets.org/stable/wx_dialogfunctions.html#wxmessagebox
void MiFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	//wxMessageBox( _("Esto es un ejemplo de About...")); 	// Equivalente al ShowMessage
	wxMessageBox( _("Esto es un ejemplo de About..."), _("About..."), wxOK | wxICON_INFORMATION, this);	// // Equivalente al MsgDialog
}

