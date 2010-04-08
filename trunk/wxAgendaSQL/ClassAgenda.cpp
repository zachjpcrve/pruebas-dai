#include "ClassAgenda.h"
#include <string.h>

using namespace std;

void Agenda::push(string c_dni,string c_nombre,string c_apellidos,string direccion,string localidad,int telefono1,int telefono2,int telefono3)
{
	Contacto* nuevo=new Contacto(c_dni,c_nombre,c_apellidos,direccion,localidad,telefono1,telefono2,telefono3);
	if(primero==NULL)
		primero=nuevo;
	else
	{	
		Contacto* temp=primero;
		while(temp!=NULL)
		{
			if(nuevo->getNombre()>temp->getNombre())
			{
				nuevo->setSiguiente(temp->getSiguiente());
				temp->setSiguiente(nuevo);
				return;
			}
			else
				temp=temp->getSiguiente();
		} 
	}
};
void Agenda::pop(string id){
	Contacto* temp=primero;
	Contacto* temp2;	
	while(temp->getDni()!=id){
		temp2=temp;
		temp=temp->getSiguiente();
	}
	temp2->setSiguiente(temp->getSiguiente());
	delete(temp);
};
