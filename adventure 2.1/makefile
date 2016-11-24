all: programa

programa: main.o Tela.o Pecas.o Engine.o Placar.o
	g++ main.o Tela.o Pecas.o Engine.o Placar.o 

main.o: adventure2.1.cpp item.cpp jogador.cpp monstro.cpp interface.cpp engine.cpp
	g++ -c adventure2.1.cpp

item.o: item.cpp Tela.h
	g++ -c item.cpp

jogador.o: jogador.cpp Pecas.h
	g++ -c jogador.cpp

mosntro.o: monstro.cpp mosntro.h
	g++ -c mosntro.cpp
	
interface.o: interface.c interface.h
	g++ -c interface.cpp

engine.o: engine.cpp engine.h
	g++ -c engine.cpp