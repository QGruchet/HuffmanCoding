DEBUG=yes
CC=g++
EXEC=main

#################################

ifeq ($(DEBUG), yes)
	CFLAGS = -std=c++17 -Wall -g
else
	CFLAGS = -std=c++17 -Wall
endif

#################################

all: $(EXEC)

$(EXEC) : Main.o Tree.o
	$(CC) src/target/Main.o src/target/Main.o -o src/bin/$@

#################################

run :
	./src/bin/$(EXEC)

#################################

Main.o: src/main/Main.cpp
	$(CC) -c $(CFLAGS) $< -o src/target/$@

Tree.o: lib/Tree.cpp lib/Tree.hpp
    $(CC) -c $(CFLAGS) $< -o src/target/$@

#################################

vg:
	valgrind ./src/bin/$(EXEC)

vg2:
	valgrind --leak-check=full ./src/bin/$(EXEC)

vg3:
	valgrind -v ./src/bin/$(EXEC)

#################################

clean:
	rm src/target/*.o

mrproper: clean
	rm bin/$(EXEC)
