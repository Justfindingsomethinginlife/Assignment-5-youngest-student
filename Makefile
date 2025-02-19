CC = g++
LIBSRC = $(wildcard src/*.cpp)
LIBOBJ = $(addprefix build/, $(patsubst %.cpp, %.o, $(notdir $(LIBSRC))))
LIBINCL = 

LIBNAME =


default: build

.PHONY: libstatic clean-all build $(LIBOBJ) 

libstatic: 
	make $(LIBOBJ)

build: src/main.cpp 
	@echo ------------- Building -------------
	$(CC) -o build/main.o -I../include/ -c src/main.cpp
	@echo ------------- Linking  -------------
	$(CC) -o bin/main -Llib/ build/main.o $(LIBINCL)
	@echo ------------- Run ------------------
	valgrind --leak-check=full ./bin/main

$(LIBOBJ): $(LIBSRC)	
	@echo ------------- Building -------------
	$(CC) -o $@ -c -Iinclude/ src/$(strip $(notdir $(patsubst %.o, %.cpp, $@)))
	ar rcs bin/$(LIBNAME).a $(LIBOBJ)

clean-all: bin/* build/*
	rm bin/*
	rm build/*
