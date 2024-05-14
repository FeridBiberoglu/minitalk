CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lminitalk

all: server client

server.o: server.c minitalk.h
    $(CC) $(CFLAGS) -c server.c -o server.o

client.o: client.c minitalk.h
    $(CC) $(CFLAGS) -c client.c -o client.o

server: server.o
    $(CC) server.o -o server $(LIBS)

client: client.o
    $(CC) client.o -o client $(LIBS)

clean:
    rm -f server client

fclean: clean
    rm -f *.o

.PHONY: all clean fclean