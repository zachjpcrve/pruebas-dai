#include "cassContacto.h"

Contacto::Contacto()
{
	nombre = "";
   apellido = "";
   dni = "";
   direccion = "";
   localidad = "";
   for (int i=0; i<3; i++) telefonos[i]=0;
}
//--------------------------------------------------
Contacto::Contacto(string nom, string ape, string nif, string direc, string local, int tel1, int tel2, int tel3)
{
   nombre = nom;
   apellido = ape;
   dni = nif;
   direccion = direc;
   localidad = local;
   telefonos[0] = tel1;
   telefonos[1] = tel2;
   telefonos[2] = tel3;
   borrado = false;
}
//---------------------------------------------------
void Contacto::modificar(string nomb, string ape, string nif, string direc, string loca, int tel1, int tel2, int tel3)
{
   nombre = nomb;
   apellido = ape;
   dni = nif;
   direccion = direc;
   localidad = loca;
   telefonos[0] = tel1;
   telefonos[1] = tel2;
   telefonos[2] = tel3;
}
//----------------------------------------------------
Contacto::~Contacto()
{
}


