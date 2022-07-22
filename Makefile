all: output run
	
build: 
	g++ -I src/include -c main.cpp ./Client/*.cpp

output: *.o
	g++ *.o -o game.exe -L src/lib -l sfml-graphics -l sfml-window -l sfml-audio -l sfml-system -l openal32 -static-libgcc -static-libstdc++

./main.o: main.cpp	
	g++ -I src/include -c main.cpp -o main.o

./Game.o: ./Client/Game.cpp	
	g++ -I src/include -c ./Client/Game.cpp -o Game.o

./State.o: ./Client/State.cpp
	g++ -I src/include -c ./Client/State.cpp -o State.o

./Piece.o: ./Client/Piece.cpp
	g++ -I src/include -c ./Client/Piece.cpp -o Piece.o

./King.o: ./Client/King.cpp
	g++ -I src/include -c ./Client/King.cpp -o King.o

./Rook.o: ./Client/Rook.cpp
	g++ -I src/include -c ./Client/Rook.cpp -o Rook.o

run:
	./game.exe
