#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

bool imprimir_operacion(int number1, int number2, char sign);
bool numerear(int &destino, string origen);

int main(){
	sqlite3 *miDB;	         // Creo un objeto de tipo sqlite para interactuar con la base de datos.
	int result = 0;          // Guardará los exitos o fracasos de los comandos como codigo INT. http://www.sqlite.org/c3ref/c_abort.html
	char *error = 0;         // Guardará los exitos o fracasos de los comandos con una cadena de texto con el error concreto detallado.  
	char sql[100];	         // Usaremos está variable para almacenar las consultas que realizaremos a la base de datos.  
	sqlite3_stmt *datos;  	 // Los objetos "stmt" de sqlite almacenan los datos obetenidos de la consulta realizada.	
	/* 
	 *  Abro el archivo de la base de datos y lo meto en el objeto de tipo base de datos. Si no existe el archivo lo recreará así que funcionará 		
	 *  igualmente. Solo devolverá error (result==1) si no tiene permisos de escritura al intentar crear el archivo. En ese caso cierro el programa.
	 */
	result = sqlite3_open("database.db",&miDB);	
	if(result) { 
		sqlite3_close(miDB);	// Cerramos la base de datos ya que cargó mal.
		cout << "No hay permisos de escritura para crear la base de datos."  << endl;
		return 1;	// Este return cerrará el programa saliendo del main con return (devolverá 1 que significa error).
	}	 

	/*
	 *  Ahora creamos la tabla donde guardaremos los datos. Solo se creará si no ha sido creada en una ejecucion anterior (si se lanza por primera vez)
	 *  el programa o si se ha borrado el archivo "database". Crea tres columnas, dos para numereros y una con un char de una sola letra que servirán 		 *	 para guardar los dos numeros y el signo matematico. Los tres NULL del final son opciones extra que yo no voy a usar.
	 */
	result = sqlite3_exec(miDB,"create table if not exists tabla1(numero1 int, numero2 int, signo varchar(1));",NULL,NULL,NULL ); 
	
	// Menu principal	

	string opcion;
	while(opcion != "4"){
		cout << endl << "Elige una opcion:" << endl;
		cout << "1) Introducir nueva operacion" << endl;
		cout << "2) Mostrar Historial de operaciones" << endl;
		cout << "3) Borrar historial" << endl;
		cout << "4) Salir" << endl;
		cin >> opcion;
		
		if(opcion=="1"){
			char signo;//, *temp;
			int numero1=0,numero2=0;
			string temp;
			
			cout << endl << "Introduce una operación separada por espacios. Ej: '4 + 5' .No se permiten negativos ni decimales." << endl;
			cin >> temp;
			if(numerear(numero1,temp)){cout << endl << "*** Solo se permiten digitos en los numeros ***" << endl; continue;}
			cin >> signo;
			cin >> temp;
			if(numerear(numero2,temp)){cout << endl << "*** Solo se permiten digitos en los numeros ***" << endl; continue;}
	
			cout << endl << "================================" << endl;
			result = imprimir_operacion(numero1,numero2,signo); // imprimo la operación. True si el usuario metio mal el signo.
			cout << "================================" << endl;
			
			if(result) cout << "signo incorrecto, vuelva a intentarlo" << endl;
			else{
			/*
			*   Introducimos los dos numeros y el signo en la tabla con "insert into". result puede ir de 0-30 (posibles errores) así que usaremos
			*	 variable 'error' para almacenar el error en concreto como texto. 		
		    */
				sprintf(sql,"insert into tabla1 values(%d,%d,'%c');",numero1,numero2,signo); //Concatenacion.
				result = sqlite3_exec(miDB,sql,NULL,NULL,&error);
				if(result){
					sqlite3_close(miDB);
					cout << "error: " << error << endl;
					continue;
				}			
			} 
		}
		else if(opcion=="2"){
			// En este caso cojemos información de la base de datos en lugar de introducir. En este caso uso las secuencias: prepare, step, finalize.
			strcpy(sql,"select * from tabla1;");			

			// Prepare hace la consulta y la guarda en un objeto de tipo STMT.
			result = sqlite3_prepare(miDB, sql, strlen(sql), &datos, NULL);
        	if(result != SQLITE_OK){		
				cout << "SQL error:" << sqlite3_errmsg(miDB);	// Otra forma de obtener errores. sqlite3_errmsg recuerda el ultimo error de la DB.
				continue;
			}
        	cout << endl << "================================" << endl;
			result = sqlite3_step(datos);	// Avanzamos una fila (la primera fila tiene los nombres de las columnas y no nos interesa)
			//ncolumnas = sqlite3_column_count(datos); 	// Contamos el numero de columnas de la tabla STMT.

			while(result== SQLITE_ROW){	
				/*
				 * SQLITE_ROW es una constante que vale 100. 100 es el resulttcode que significa que quedan filas en el objeto.
				 * http://www.sqlite.org/c3ref/c_abort.html
				 * sqlite_column_(tipo) devuelve los valores de las columnas mandandole el objeto STMT más el numero de la columna.
				*/				
				imprimir_operacion(sqlite3_column_int(datos,0),sqlite3_column_int(datos,1), sqlite3_column_text(datos,2)[0]);
				result = sqlite3_step(datos);	// Avanzamos una fila.			
			}
			cout << "================================" << endl;
			sqlite3_finalize(datos);		// Finalizamos la consulta y destruimos el objeto stmt datos.
		}
		else if(opcion=="3"){
			result = sqlite3_exec(miDB, "delete from tabla1;", NULL, NULL, &error);
			if(result) cout << "Error: " << error << endl;
			else{
				cout << "Limpiando el historial" <<endl;
				sleep(1);
				cout << "Historial borrado" << endl;	
			}
		}
	}
	
	//menu(miDB);
	
	sqlite3_close(miDB);	//cerramos la base de datos
	return 0;
	
}
//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

bool imprimir_operacion(int number1, int number2, char sign){

	if(sign=='+') cout << "Operacion: " << number1 << " " << sign << " " << number2 << " = " << number1 + number2 << endl;
	else if(sign=='-') cout << "Operacion: " << number1 << " " << sign << " " << number2 << " = " << number1 - number2 << endl;
	else if(sign=='*') cout << "Operacion: " << number1 << " " << sign << " " << number2 << " = " << number1 * number2 << endl;
	else if(sign=='/') cout << "Operacion: " << number1 << " " << sign << " " << number2 << " = " << (float) number1 / number2 << endl;
	else return true;
	
	return false;					
}
//--------------------------------------------------------------------------------------------------------------

// Convierte un string a integer. Si se encuentra algun caracter que no sea un digito se devuelve True.
bool numerear(int &destino, string origen){
	for(int i =0 ; i < origen.length() ; i++){
		if( (origen[i] > 47 && origen[i] < 58))
			destino += ((int) origen[i] - 48) * pow(10,origen.length()-1-i) ;
		else return true;
	}
	return false;
}

