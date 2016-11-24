all: programa

programa: main.o item.o jogador.o monstro.o interface.o engine.o 
	g++ main.o item.o jogador.o monstro.o interface.o engine.o 

main.o: main.cpp item.cpp jogador.cpp monstro.cpp interface.cpp engine.cpp
	g++ -c main.cpp

item.o: item.cpp item.h
	g++ -c item.cpp

jogador.o: jogador.cpp jogador.h
	g++ -c jogador.cpp

monstro.o: monstro.cpp monstro.h
	g++ -c monstro.cpp
	
interface.o: interface.cpp interface.h
	g++ -c interface.cpp

engine.o: engine.cpp engine.h
	g++ -c engine.cpp