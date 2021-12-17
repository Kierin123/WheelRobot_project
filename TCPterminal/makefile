CFLAGS = -Wall -Wextra -Wpedantic
CC = gcc
LDFLAGS = 
LIBS = -lpthread
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = program

#Rule which build all project
all: clean $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE) $(LIBS)

#Rule to build obj files
$(OBJECTS): 
	$(CC) -c $(CFLAGS) $(SOURCES) 

#Rule to clean
clean: 
	rm -f $(OBJECTS)
	rm -f $(EXECUTABLE)