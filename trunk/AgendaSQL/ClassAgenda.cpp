#include "ClassAgenda.h"

Agenda::Agenda(int size)
{
   longitud = size;
   ocupado = 0;
   //Creamos el vectror con punteros a Contacto
   lista = new Contacto* [size];
   //Inicializamos a NULL
   for (int i=0; i<size; i++) lista[i]=NULL;
} 
//--------------------------------------------------------------------------
void Agenda::addContacto(Contacto* persona)
{
   /*
   * Contacto* contac = new Contacto (Esto iria aqui si le pasaramos como para-
   * metros a la funcion todos los atributos en vez del puntero
   */
   if(ocupado==longitud) aumentarAgenda(); //Si no hay hueco, hacemos.

   for (int i=0; i<longitud; i++)
      if(lista[i]==NULL)
      {
         lista[i] = persona;
         ocupado++;
         break;
      }
}
//--------------------------------------------------------------------------
void Agenda::aumentarAgenda()
{
   //Creamos un **aux para aumentar la agenda
   Contacto** aux;

   //Creamos el nuevo vector de punteros a contactos pero con mas capacidad
   aux = new Contacto*[longitud+5];

   for (int i=0; i<longitud+5; i++) aux[i]=NULL;
   //Copiamos todo a la nueva agenda aumentada
   for (int k=0; k<longitud; k++) aux[k]=lista[k];

   //Actualizamos la variable longitud
   longitud+=5;

   delete[] lista; //Borramos donde apunta lista (el vector de punteros)
   lista = aux; //hacemos que lista apunte donde aux
}
//---------------------------------------------------------------------------
Contacto* Agenda::buscar(string dni)
{
   //Recorremos la agenda para encontrar el contacto por dni
   for (int i=0; lista[i]; i++)
      if (lista[i]->getDni() == dni) return lista[i];
}
//---------------------------------------------------------------------------
void Agenda::delContacLog(Contacto* borralo)
{
   borralo->setBorrado(true);
}
//---------------------------------------------------------------------------
/*void Agenda::listarAgenda(TListView* listar)
{
   TListItem* fila;
   //Limpiamos el listview para la proxima vez que entremos
   listar->Clear();
   int i=0;
   //Para controlar que no se intente mostrar el lisview cuando no hay nada
   //intentamos meter en un entero longitud, si no se puede, no lo mostramos
   try
   {
      int entero = longitud;

      while(i<longitud)
      {
         if (lista[i])
            if(!lista[i]->getBorrado())
            {
               fila = listar->Items->Add();
               fila->Caption=(lista[i]->getNombre());
               fila->SubItems->Add(lista[i]->getApellido());
               fila->SubItems->Add(lista[i]->getDni());
               fila->SubItems->Add(lista[i]->getDireccion());
               fila->SubItems->Add(lista[i]->getLocalidad());
               //Mostramos solo los telefonos rellenos
               lista[i]->getTelefono1() ? fila->SubItems->Add(lista[i]->getTelefono1()) : fila->SubItems->Add("");
               lista[i]->getTelefono2() ? fila->SubItems->Add(lista[i]->getTelefono2()) : fila->SubItems->Add("");
               lista[i]->getTelefono3() ? fila->SubItems->Add(lista[i]->getTelefono3()) : fila->SubItems->Add("");
            }
         i++;
      }
   }
   catch(...){} //Si no se puede que no haga nada
}*/
//----------------------------------------------------------------------------
void Agenda::delContacto(string dni)
{
   for (int i=0; i<longitud; i++)
      if (lista[i]->getDni() == dni)
      {
         delete lista[i];
         lista[i] = NULL;
         //Actualizamos la lista de ocupados
         ocupado--;
         return;
      }
}