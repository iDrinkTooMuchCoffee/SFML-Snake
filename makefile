CC= G++

Project: src/main.cpp
	$(CC) -std=c++11 src/*.cpp src/*.hpp -o bin/snake.exe -lmingw32 -lsfml-main -lsfml-graphics -lsfml-system -lsfml-window -lopengl32 -w
