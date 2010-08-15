#!/usr/bin/python
import sqlite3 as lite # sqlite ya viene en python, no es necesario instalar nada
import time            # para el sleep
import os              # para borrar la pantalla

################# Clases   #################
# En este segundo ejemplo meteremos todos los metodos y las dos variables usadas en el ejemplo anterior en el interior de una Clase.
class BaseDeDatos:
    
    ###Atributos
    """Cadena de documentacion de la clase, esta ayuda saldra al programador si se hace instancia.__doc__ en el programa"""
    __connection = None     # None es Null. En esta variable guardaremos el objeto de tipo conecion a BD.
    __cursor = None         # Esta variable guarda datos de tipo consulta, y es la encargada de hacer las consultas a la BD.
    __conectado = False     # Esta variable booleana sera True cuando estemos conectados a la BD.    

    #### Metodos
    # Aunque no es exactamente un constructor, el __init__ es lo mas parecido a un constructor de C. En mi caso lo utilizo para conectar a la BD.
    def __init__ (self, archivo):                     # Los atributos/metodos que se llaman __nombre__ son predefinidos de python tipo constructores. 
        try:                                          # No uses nunca __nombre__ en tus propios atributos y metodos.                   
            self.__connection = lite.connect(archivo) # Los atributos de la clase se llaman con "self". Conectamos a la BD.
        except lite.Error, error:                     # Devolvemos error si no hay permisos de escritura. lite.Error guarda el nombre del ultimo error.
            print "Error: " + str(error)              # Este error se guarda en "error" el cual convertimos a string e imprimimos.
            return                                    # Si hubo error hacemos Break y self.__conectado queda como False.                 
        self.__cursor = self.__connection.cursor()    # Si un atributo/metodo se llama __nombre es privado (__ al inicio solo). Sino es publico.       
        self.crearTablaOperacion()                    # Llamamos al metodo crearTabla en el constructor por si aun no existe.
        self.__conectado = True
    
    # Este metodo crea la tabla si no existe. Ademas de llamarlo en el constructor se puede llamar manualmente si hace falta.
    def crearTablaOperacion(self):
        self.__cursor.execute("create table if not exists tabla1 (numero1 int, numero2 int, signo varchar(1));") 

    # Introducimos datos en la base de datos. En este tipo de "formateo" de string de python las ? son sustituidas despues por lo valores entre
    # parentesis en orden. No se puede utilizar en identificadores como el nombre de la tabla, para ellos se debe usar el del estilo printf de C con %.
    def introducir(self, number1, number2, sign):
        try:
            self.__cursor.execute("insert into tabla1 values(?,?,?);", (number1,number2,sign))
        except lite.Error, error:
            print "Error: " + str(error)

    # Esta funcion extrae todos los datos de la BD, los guarda en un array y los devuelve. Se podria modificar para que que extraiga partes.
    def extraer(self):
        try:
            self.__cursor.execute("select * from tabla1;")
            return self.__cursor.fetchall()
        except lite.Error, error:
            print "Error: " + str(error)
    
    # Borramos la Tabla. Este metodo se puede modificar para que borre una tabla distinta cada vez mandandole parametros.
    def borrar(self):
        try:
            self.__cursor.execute("delete from tabla1;")
            print "Borrando el historial..."
            time.sleep(1)
            print "Historial borrado"
        except lite.Error, error:
            print "Error: " + str(error)

    # Utilizando este comando guardaremos los cambios realizados en la BD que actualmente estan en memoria en el fichero.
    # Es importante usarlo periodicamente para ir guardando los cambios. Si no se usa se perdera todo al cerrar la BD.    
    def commit(self):    
        self.__connection.commit() 
   
    # Cerramos los procesos de memoria abiertos una vez vayamos a finalizar de usar la base de datos. 
    def cerrar(self):
        self.commit()
        self.__cursor.close()
        self.__connection.close()
        self.__conectado = False
    
    # Devuelve True o False segun el valor booleano del atributo conectado. Esto seria un getConectado.
    def estaConectado(self):
        return self.__conectado
    

################# Funciones  #################

# Esta funcion recibe un unico string que devolvera convertida en (int,int,string). Si el string no es correcto devolvera (None,None,None) (3 NULLs)   
def numerear(cadena):
    if len(cadena.split()) == 3:  # Comprobamos que la cadena recibida conste de 3 palabras (numero signo numero)
        numeros = [cadena.split()[0],cadena.split()[2]] # Creamos una variable-lista nueva con las palabras 0,2 (1 es signo)
        sign = cadena.split()[1]    # guardamos el signo en una variable propia.

        for i in 0,1:   # Este for tendra dos iteracciones. En la primera valdra 0, en la segunda valdra 1.
             # comprueba que el numero sea entero digitos o en su defecto que el primer valor sea "-" y los posteriores sean digitos.
            if numeros[i].isdigit() or ( numeros[i][0] == "-" and numeros[i][1:].isdigit()):   
                numeros[i] = int(numeros[i])    # convertimos a entero el numero evaluado del for.
            else:  return None,None,None        # Devolvemos None,None,None si en alguna interaccion sale un no-numero.
        if sign!="+" and sign!="-" and sign!="*" and sign!="/" and sign!="**": return None,None,None    # comprobamos que el string sea lo que queremos.
        
        return numeros + [sign] # Si hemos llegado aqui con exito devolvemos nuestro trabajo como (int,int,string)
    else:
        return None,None,None   # Si hay menos de 3 palabras o mas, devolvemos None,None,None

# Imprimir parecido al de C pero comprobando que se divida por 0.
def imprimir_operacion(number1, number2, sign):
   if sign=="+":  print "%d %s %d = %d" % (number1,sign,number2,number1+number2)   # Print estilo C
   if sign=="-":  print "%d %s %d = %d" % (number1,sign,number2,number1-number2)
   if sign=="*":  print "%d %s %d = %d" % (number1,sign,number2,number1*number2)
   if sign=="**": print "%d %s %d = %d" % (number1,sign,number2,number1**number2)
   try:
       if sign=="/":  print "%d %s %d = %f" % (number1,sign,number2,number1/float(number2)) # dividimos entre decimal para obtener decimal.
   except ZeroDivisionError:    # Si al intentarlo el error devuelve ZeroDivisionError (error de dividir por 0) no hacemos la operacion.
       print "%d %s %d = -No se puede-" % (number1,sign,number2)

# Esta funcion comprueba que estes en Windows para hacer "cls" o "clear" en la consola al limpiarla.
def borrar():
    if os.name == "nt": os.system("cls")        #Windows
    elif os.name == "posix": os.system("clear") # Unix
    
################# Main  #################
bd  = BaseDeDatos("database.db")   # Instanciamos nuestra clase personalizada de datos que ya conecta automaticamente a la BD.
while bd.estaConectado():                   # Si conectamos mal a la base de datos o nos desconectamos el while no se ejecutara.
    borrar()
    opcion = "0"

    # Las comillas triples permiten hacer strings de varias lineas sin tener que usar \n
    print '''Elige una opcion:  
    1) Introducir nueva operacion
    2) Mostrar Historial de operaciones
    3) Borrar historial
    4) Salir'''

    opcion = raw_input() # Esto es el cin/scanf
    if opcion == "1":
        # Mandamos un unico string que volvera convertida en (int,int,string). Si se mando mal obentedremos (None,None,None)       
        numero1,numero2,signo = numerear(raw_input("Introduce una operacion separada por espacios:\n")) 
        if numero1 == None:
            print ''' Introduce la operacion correctamente:
            El numero de parametros totales deben ser tres siguiendo el formato "numero signo numero"
            Se permiten los siguientes signos: "+ - * / **". El numero puede ser negativo, pero no decimal. '''
        else:
            imprimir_operacion(numero1,numero2,signo) ; time.sleep(0.5)
            bd.introducir(numero1, numero2, signo)
    elif opcion == "2":
        # En python False es 0, [] , () , {} . True es todo lo demas. Si obtenemos una lista vacia [] de la BD la funcion estara devolviendo False.
        if not bd.extraer(): print "El historial esta Vacio. ",
        else: print "Operaciones:"
        # Extraer devuelve un array de dos dimenciones (filas por columnas). 
        # Recorremos las filas con un For almacenandolas en "i" y accedemos a las columnas con un indice.        
        for i in bd.extraer():
            imprimir_operacion(i[0],i[1],i[2]) ; time.sleep(0.3)
    elif opcion == "3":
        bd.borrar()         # Borramos la BD entera
    elif opcion == "4":
        bd.cerrar() # Cerramos la BD. Al acabar este bucle __estaConectado devolvera False y el programa acabara.      
        print "Saliendo del programa.",
    else:
        print "Opcion incorrecta.",

    raw_input("Pulse una tecla...")

