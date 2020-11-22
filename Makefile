
all: end


TicTacGame: main.o Board.o Player.o
	@if [ -e TicTacGame ];  then rm TicTacGame; fi
	@g++ -o TicTacGame main.o Board.o Player.o   -lglut -lGLU -lGL
	@echo "Tic Tac Game generated"

main.o: main.cpp
	@g++ -c main.cpp
	@echo "main.o generated"

Board.o: Structures/Board.cpp Structures/Board.h
	@g++ -c Structures/Board.cpp
	@echo "Board.o generated"

Player.o: Structures/Player.cpp Structures/Player.h
	@g++ -c Structures/Player.cpp
	@echo "Player.o generated"


end: TicTacGame
	@if [ -e Build ];  then rm -r Build; fi
	@mkdir Build
	@mv *.o Build/
	@echo "Files moved to Build/"
