#ifndef CONTACTO_H
#define CONTACTO_H
//#include <string.h>
#include <iostream>

using namespace std;

class Contacto {

	string nombre;
   string apellido;
   string dni;
   string localidad;
   int telefonos[3];
   bool borrado;

public:
   //Constructor por defecto
   Contacto();
   //Constructor de la funcion.
   Contacto(string, string, string, string, string, int, int, int);
   
   //Destructor
   ~Contacto();

   void modificar(string, string, string , string , string, int , int , int);
   //SETS
   void setNombre(string nombreMod){nombre=nombreMod;}
   void setApellido(string apeMod){apellido=apeMod;}
   void setdni(string dniMod){dni=dniMod;}
   void setDireccion(string direcMod){direccion=direcMod;}
   void setLocalidad(string locaMod){localidad=locaMod;}
   void setTelefono(int tel, int ind);
   void setBorrado(bool estado){borrado = estado;}

   //GETS
   string getNombre(){return nombre;}
   string getApellido(){return apellido;}
   string getDni(){return dni;}
   string getDireccion(){return direccion;}
   string getLocalidad(){return localidad;}
   int getTelefono1(){return telefonos[0];}
   int getTelefono2(){return telefonos[1];}
   int getTelefono3(){return telefonos[2];}
   bool getBorrado(){return borrado;}

};

#endif // CONTACTO_H
