DEBUG=no
CC=g++
EXEC=main
WIN=window
PACKWIN=-std=c++0x `pkg-config --CXXFLAGS gtkmm-3.0 --CXXFLAGS --libs`
STRC=src/QtWindow

#################################

ifeq ($(DEBUG), yes)
	CXXFLAGS = -std=c++17 -Wall -Wextra -g
else
	CXXFLAGS = -std=c++17 -Ofast
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

window: run
	cmake src/windowQT/CMakeLists.txt
	make -C src/windowQT
	src/windowQT/./main

#################################

# $@ ref name of target, here Main.o
# $< ref first dependency, here src/main/Main.cpp
Main.o: src/main/Main.cpp
	$(CC) -c $(CXXFLAGS) $< -o src/target/$@

# $< ref first dependency, here src/lib/Tree.cpp
Tree.o: src/lib/Tree.cpp src/lib/Tree.hpp
	$(CC) -c $(CXXFLAGS) $< -o src/target/$@

Writer.o: src/lib/Writer.cpp src/lib/Writer.hpp
	$(CC) -c $(CXXFLAGS) $< -o src/target/$@

Test.o: src/test/Test.cpp src/test/Test.hpp
	$(CC) -c $(CXXFLAGS) $< -o src/target/$@

Parser.o: src/lib/Parser.cpp src/lib/Parser.hpp
	$(CC) -c $(CXXFLAGS) $< -o src/target/$@

#################################

vg:
	valgrind ./src/bin/$(EXEC)

vg2:
	valgrind --leak-check=full --show-leak-kinds=all ./src/bin/$(EXEC)

vg3:
	valgrind -v ./src/bin/$(EXEC)

vg4:
	valgrind --leak-check=full --show-leak-kinds=all ./src/windowQT/$(EXEC)

gdb:
	gdb ./src/bin/$(EXEC)

#################################

cleantarget:
	rm src/target/*.o
	rmdir src/target
	rm src/txtQT/*.txt
	rmdir src/txtQT

cleanQT:
	rm src/windowQT/main
	rm -r src/windowQT/CMakeFiles
	rm -r src/windowQT/main_autogen
	rm src/windowQT/CMakeCache.txt
	rm src/windowQT/cmake_install.cmake
	rm src/windowQT/Makefile

clean: cleantarget cleanQT

mrproper: clean cleanQT
	rm src/bin/$(EXEC)
	rmdir src/bin
