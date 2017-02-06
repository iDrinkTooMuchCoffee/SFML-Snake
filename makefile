CC= G++

Project: src/main.cpp
	$(CC) src/*.cpp src/*.hpp -o bin/snake.exe -lmingw32 -lsfml-main -lsfml-graphics -lsfml-system -lsfml-window -lopengl32 -std=c++11 -w
