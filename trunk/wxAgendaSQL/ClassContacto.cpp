#include "ClassContacto.h"
#include <string.h>

using namespace std;

Contacto::Contacto(string c_dni,string c_nombre,string c_apellidos,string c_direccion,string c_localidad,int telefono1,int telefono2,int telefono3)
{
	dni=c_dni;
	nombre=c_nombre;
	apellidos=c_apellidos;
	direccion=c_direccion;
	localidad=c_localidad;
	telefonos[0]=telefono1;
	telefonos[1]=telefono2;
	telefonos[2]=telefono3;
	siguiente=NULL;
}
