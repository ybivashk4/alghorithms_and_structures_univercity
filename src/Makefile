CC=g++
CFLAGS=-Wall -Wextra -Werror
DIR=lab1/
SOURCES=$(DIR)lab1.cpp
RFLAGS=-lm
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=lab_1

all: $(EXECUTABLE)

$(EXECUTABLE): lab1.o $(SOURCES)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(DIR)lab_1

lab1.o: $(DIR)lab1.cpp
	$(CC) $(CFLAGS) -c $(SOURCES) -o $(DIR)lab1.o $(RFLAGS)

clean:
	rm -rf *.o