CFLAGS = -Wall -Wextra -Wpedantic
CC = gcc
LDFLAGS = 
LIBS = -lwiringPi -lpthread
SOURCES = main.c motors.c TCP.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = wheelrobot

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
	rm -f l_fifo_command
