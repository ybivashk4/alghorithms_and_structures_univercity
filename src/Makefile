CC=g++
CFLAGS=-Wall -Wextra -Werror
DIR=../build_folder/
SOURCES=lab2/lab2.cpp lab1/lab1.cpp
RFLAGS=-lm
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=lab_2

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(SOURCES)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(DIR)$(EXECUTABLE)

lab1.o: lab1/lab1.cpp
	$(CC) $(CFLAGS) -c lab1/lab1.cpp -o $(DIR)lab1.o $(RFLAGS)

lab2.o: lab1/lab1.cpp lab2/lab2.cpp
	$(CC) $(CFLAGS) -c lab2/lab2.cpp -o $(DIR)lab2.o $(RFLAGS)

clean:
	rm -rf *.o