#!/usr/bin/python
import sqlite3 as lite # sqlite ya viene en python, no es necesario instalar nada
import time            # para el sleep
import os              # para borrar la pantalla

## Funciones del programa
# Funciones de bases de datos

def conectarBD():
    try:
        con = lite.connect("database.db")
    except lite.Error, error:
        exit()
    cur = con.cursor() 
    cur.execute("create table if not exists tabla1(numero1 int, numero2 int, signo varchar(1));") 
    return con, cur

def introducirBD(cur, number1, number2, sign):
    try:
        cur.execute("insert into tabla1 values(?,?,?);", (number1,number2,sign))
    except lite.Error, error:
        print "Error: " + str(error)

def extraerBD(cur):
    try:
        cursor.execute("select * from tabla1;")
        return cursor.fetchall()
    except lite.Error, error:
        print "Error: " + str(error)
        
def borrarBD(cur):
    try:
        cur.execute("delete from tabla1;")
        print "Borrando el historial..."
        time.sleep(1)
        print "Historial borrado"
    except lite.Error, error:
        print "Error: " + str(error)
        
def cerrarBD(con,cur):
    con.commit()  
    cur.close()
    con.close()

# Funciones de operaciones

def numerear(cadena):
    if len(cadena.split()) == 3:
        numeros = [cadena.split()[0],cadena.split()[2]]
        sign = cadena.split()[1]

        for i in 0,1:
            if numeros[i].isdigit() or ( numeros[i][0] == "-" and numeros[i][1:].isdigit()):
                numeros[i] = int(numeros[i])
            else:  return None,None,None
        if sign!="+" and sign!="-" and sign!="*" and sign!="/" and sign!="**": return None,None,None
        
        return numeros + [sign]
    else:
        return None,None,None

def imprimir_operacion(number1, number2, sign):
   if sign=="+":  print "%d %s %d = %d" % (number1,sign,number2,number1+number2) 
   if sign=="-":  print "%d %s %d = %d" % (number1,sign,number2,number1-number2)
   if sign=="*":  print "%d %s %d = %d" % (number1,sign,number2,number1*number2)
   if sign=="**": print "%d %s %d = %d" % (number1,sign,number2,number1**number2)
   try:
       if sign=="/":  print "%d %s %d = %f" % (number1,sign,number2,number1/float(number2))
   except ZeroDivisionError:
       print "%d %s %d = -No se puede-" % (number1,sign,number2)

# Borrar personalizado
def borrar():
    if os.name == "nt": os.system("cls") #Windows
    elif os.name == "posix": os.system("clear") # Unix
    
## Main
connection,cursor = conectarBD()
opcion = "0"
while opcion != "4":

    borrar()
    print '''Elige una opcion:
    1) Introducir nueva operacion
    2) Mostrar Historial de operaciones
    3) Borrar historial
    4) Salir'''

    opcion = raw_input()
    if opcion == "1":
       numero1,numero2,signo = numerear(raw_input("Introduce una operacion separada por espacios:\n"))
       if numero1 == None:
           print ''' Introduce la operacion correctamente:
           El numero de parametros totales deben ser tres siguiendo el formato "numero signo numero"
           Se permiten los siguientes signos: "+ - * / **". El numero puede ser negativo, pero no decimal. '''
       else:
           imprimir_operacion(numero1,numero2,signo) ; time.sleep(0.5)
           introducirBD(cursor, numero1, numero2, signo )
    elif opcion == "2":
        if not extraerBD(cursor): print "El historial esta Vacio. ",
        else: print "Operaciones:"
        for i in extraerBD(cursor):
            imprimir_operacion(i[0],i[1],i[2]) ; time.sleep(0.3)
    elif opcion == "3":
        borrarBD(cursor)
    elif opcion == "4":
        print "Saliendo del programa.",
    else:
        print "Opcion incorrecta.",

    raw_input("Pulse una tecla...")
 
cerrarBD(connection,cursor)
