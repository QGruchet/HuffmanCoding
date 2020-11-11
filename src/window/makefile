run: compile
	./main

compile: main.cpp main.hpp
	g++ -Wall -Wextra main.cpp -o main -std=c++0x `pkg-config --cflags gtkmm-3.0 --cflags --libs`

clean:
	rm main
	rm *.o