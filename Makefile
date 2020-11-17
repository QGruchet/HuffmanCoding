DEBUG=yes
CC=g++
EXEC=main
WIN=window
PACKWIN=-std=c++0x `pkg-config --cflags gtkmm-3.0 --cflags --libs`

#################################

ifeq ($(DEBUG), yes)
	CFLAGS = -std=c++17 -Wall -Wextra -g
else
	CFLAGS = -std=c++17
endif

#################################

all: build $(EXEC)

build:
	./build.sh

# $@ ref name of target, here $(EXEC)
$(EXEC) : Main.o Tree.o Test.o Writer.o Parser.o
	$(CC) src/target/Main.o src/target/Tree.o src/target/Test.o src/target/Writer.o src/target/Parser.o -o src/bin/$@

#################################

run :
	./src/bin/$(EXEC)

dot :
	dot -Tpng src/out/binary_tree.dot > src/out/test.png


#################################

window : src/window/window.cpp src/window/window.hpp
	$(CC) src/window/window.cpp -o src/bin/$@ $(PACKWIN)
	./src/bin/$(WIN);

#################################

# $@ ref name of target, here Main.o
# $< ref first dependency, here src/main/Main.cpp
Main.o: src/main/Main.cpp
	$(CC) -c $(CFLAGS) $< -o src/target/$@

# $< ref first dependency, here src/lib/Tree.cpp
Tree.o: src/lib/Tree.cpp src/lib/Tree.hpp
	$(CC) -c $(CFLAGS) $< -o src/target/$@

Writer.o: src/lib/Writer.cpp src/lib/Writer.hpp
	$(CC) -c $(CFLAGS) $< -o src/target/$@

Test.o: src/test/Test.cpp src/test/Test.hpp
	$(CC) -c $(CFLAGS) $< -o src/target/$@

Parser.o: src/lib/Parser.cpp src/lib/Parser.hpp
	$(CC) -c $(CFLAGS) $< -o src/target/$@

#################################

vg:
	valgrind ./src/bin/$(EXEC)

vg2:
	valgrind --leak-check=full --show-leak-kinds=all ./src/bin/$(EXEC)

vg3:
	valgrind -v ./src/bin/$(EXEC)

gdb:
	gdb ./src/bin/$(EXEC)

#################################

cleantarget:
	rm src/target/*.o
	rmdir src/target

cleanQT:
	rm main

clean: cleantarget

mrproper: clean
	rm src/bin/$(EXEC)
