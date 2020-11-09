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

all: build $(EXEC)

build:
	./build.sh

# $@ ref name of target, here $(EXEC)
$(EXEC) : Main.o Tree.o Test.o Parser.o
	$(CC) src/target/Main.o src/target/Tree.o src/target/Test.o src/target/Parser.o -o src/bin/$@

#################################

run :
	./src/bin/$(EXEC)

#################################

# $@ ref name of target, here Main.o
# $< ref first dependency, here src/main/Main.cpp
Main.o: src/main/Main.cpp
	$(CC) -c $(CFLAGS) $< -o src/target/$@

# $< ref first dependency, here src/lib/Tree.cpp
Tree.o: src/lib/Tree.cpp src/lib/Tree.hpp
	$(CC) -c $(CFLAGS) $< -o src/target/$@

Test.o: src/test/Test.cpp src/test/Test.hpp
	$(CC) -c $(CFLAGS) $< -o src/target/$@

Parser.o: src/lib/Parser.cpp src/lib/Parser.hpp
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
	rmdir src/target

mrproper: clean
	rm src/bin/$(EXEC)
