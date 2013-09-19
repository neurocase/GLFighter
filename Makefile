CC=g++
CFLAGS=-c -Wall 
HEADERS=game.h draw.h alien.h player.h opengl.h
SOURCES=main.cpp game.cpp draw.cpp alien.cpp player.cpp asteroid.h asteroid.cpp laser.h laser.cpp timer.h timer.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=run

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
LDFLAGS= -lGL -lglut -lboost_system -lboost_timer
endif
ifeq ($(UNAME), Darwin)
LDFLAGS= -framework OpenGL -framework GLUT -lboost_system-mt -lboost_timer-mt
endif

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC)  $(OBJECTS) $(LDFLAGS)  -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.gch *.o run

.PHONY: clean
