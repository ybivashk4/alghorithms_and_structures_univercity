CC=g++
CFLAGS=
DIR=../build_folder/
SOURCES=lab5/lab5.cpp
RFLAGS=-lm
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=lab_5

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(SOURCES)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(DIR)$(EXECUTABLE)

lab5.o: lab5/lab5.cpp
	$(CC) $(CFLAGS) -c lab5/lab5.cpp -o $(DIR)lab5.o $(RFLAGS)

clean:
	rm -rf *.o