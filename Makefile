CC=g++
CFLAGS=-c -Wall 
HEADERS=game.h draw.h alien.h player.h opengl.h
SOURCES=main.cpp game.cpp draw.cpp alien.cpp player.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=run

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
LDFLAGS= -lGL -lglut
endif
ifeq ($(UNAME), Darwin)
LDFLAGS= -framework OpenGL -framework GLUT
endif

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC)  $(OBJECTS) $(LDFLAGS) -lGL -lglut -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.gch *.o run

.PHONY: clean
