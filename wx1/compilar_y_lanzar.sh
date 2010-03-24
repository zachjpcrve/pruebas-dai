# Script en bash personalizado que compila usando wxwidgets, y si el archivo resultante existe lo lanza.

path=hola_mundo

g++ $path.cpp `wx-config --libs` `wx-config --cxxflags` -o $path
if [ -e $path ]; then
	./$path
fi
