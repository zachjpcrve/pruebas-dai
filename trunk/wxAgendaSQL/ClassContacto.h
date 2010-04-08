#ifndef CONTACTO_H
#define CONTACTO_H

#include <iostream>

using namespace std;
#define TELEFONOS 3

class Contacto {
	private:
		string dni;
		string nombre;
		string apellidos;
		string direccion;
		string localidad;
		int telefonos[TELEFONOS];
		Contacto* siguiente;

	public:
		//Constructor
		Contacto(string,string,string,string,string,int,int,int);
		//getters
		string getDni(){return dni;}
		string getNombre(){return nombre;}
		string getApellidos(){return apellidos;}
		string getDireccion(){return direccion;}
		string getLocalidad(){return localidad;}
		int* getTelefonos(){return telefonos;}
		Contacto* getSiguiente(){return siguiente;}
		//setters
		void setSiguiente(Contacto* dato){siguiente=dato;}
		void setNombre(string dato){nombre=dato;}
		void setApellidos(string dato){apellidos=dato;}
		void setDireccion(string dato){direccion=dato;}
		void setLocalidad(string dato){localidad=dato;}
		void setTelefonos(int* dato){for(int i=0;i<TELEFONOS;i++)telefonos[i]=dato[i];}
};

#endif // CONTACTO_H