#include "ClassContacto.h"

using namespace std;

class Agenda{
	private:	
		Contacto* primero;
	public:
		Agenda() {primero=NULL;}

		bool listaVacia(){return primero ? false : true;}
		
		void push(string c_dni,string c_nombre,string c_apellidos,string direccion,string localidad,int telefono1,int telefono2,int telefono3);
		void pop(string);
};
