CC=g++
CFLAGS=-c -Wall 
LDFLAGS= -lGL -lglut
SOURCES=main.cpp game.cpp game.h draw.cpp draw.h alien.cpp alien.h player.h player.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=run

all: $(SOURCES) $(EXECUTABLE) -lGL -lglut
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -lGL -lglut -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.gch *.o run
