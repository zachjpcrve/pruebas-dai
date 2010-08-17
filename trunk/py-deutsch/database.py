import sqlite3 as lite

class BaseDeDatos:
    """Clase gestora de base de datos sqlite3 para el programa py-deutsch."""
    connection = None
    cursor = None
    conectado = False  

    def __init__ (self, archivo):                     
        try:                                                     
            self.connection = lite.connect(archivo) 
        except lite.Error, error:                     
            print "Error: " + str(error)          
            return                                        
        self.cursor = self.connection.cursor()     
        self.crearTablaOperacion()
        self.conectado = True
    
    def crearTablaOperacion(self):
        self.cursor.execute("create table if not exists palabras (indice int, palabra varchar, genero char(1), plural varchar, traduccion varchar, tema tinyint, notas varchar);") 
        self.cursor.execute("create table if not exists gramatica (indice int, texto varchar);") 
        self.cursor.execute("create table if not exists opciones (nombre varchar, valor boolean);") 

    def introducir(self, indice, palabra):
        try:
            self.cursor.execute("insert into palabras values("+indice+",'"+palabra+"',NULL,NULL,NULL,NULL,NULL);")
        except lite.Error, error:
            print "Error: " + str(error)

    def extraer(self):
        try:
            self.cursor.execute("select * from palabras;")
            lista = []  # Creo una lista (vector)
            for i in self.cursor.fetchall(): # Recorro cada linea de la base de datos
                lista.append(i[1])  # Cojo la columna de "texto" de esa linea y la meto en el vector
            return lista    # Devuelvo ese vector.
        except lite.Error, error:
            print "Error: " + str(error)

    def borrar(self, indice):
        try:
            self.cursor.execute("delete from palabras WHERE indice = "+indice+";")
        except lite.Error, error:
            print "Error: " + str(error)

    def borrarTodo(self):
        try:
            self.cursor.execute("delete from palabras;")
        except lite.Error, error:
            print "Error: " + str(error)

    def commit(self):    
        self.connection.commit() 
   
    def cerrar(self):
        self.cursor.close()
        self.connection.close()
        self.conectado = False
    
    def estaConectado(self):
        return self.conectado
