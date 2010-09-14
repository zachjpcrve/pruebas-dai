# Script en bash personalizado que compila usando wxwidgets, y si el archivo resultante existe lo lanza.

nombre=wxAgendaSQL

g++ *.cpp `wx-config --libs` `wx-config --cxxflags` -o $nombre
if [ -e $nombre ]; then
	./$nombre
	rm $nombre
fi
