#ifndef AGENDA_H
#define AGENDA_H

#include <string>
#include "ClassContacto.h"

class Agenda { 
private:
	Contacto** lista; //El vector de contactos que sera de punteros
   int longitud, ocupado;

   void aumentarAgenda();
public:
   //Constructor por defecto
   //Agenda::Agenda(){};              
   //Cosntruc personalizado
   Agenda(int);

   void addContacto(Contacto*); //addconcatto debe comprobar si la agenda esta llena
   Contacto* buscar(string);
   void delContacto(string);
   void delContacLog(Contacto*);
   //void listarAgenda(TListView*); //Pasamos un puntero a un listview

};

#endif // AGENDA_H
