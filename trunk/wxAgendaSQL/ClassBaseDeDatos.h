#include <sqlite3.h>
#include <string.h>
#include "ClassContacto.h"

class BaseDeDatos{
	private:
		sqlite3 *db;	         // Objeto de tipo sqlite donde se almacena la conexión con la base de datos.
		sqlite3_stmt *datos;  	 // Los objetos "stmt" de sqlite almacenan los datos obetenidos con una consulta/query (ej: Select...)	
	
	public:
		BaseDeDatos(string archivo);
        void conectar();
		void crearTabla();
		void introducir( string dni, string nombre, string apellido, string direccion, string localidad, int telefono1, int telefono2, int telefono3 );
		void prepararExtraer();
        Contacto* extraer();
        void cerrar();
};
