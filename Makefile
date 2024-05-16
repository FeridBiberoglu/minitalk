SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server client

server: server.o libft/libft.a
	$(CC) -o $@ $< -Llibft -lft

client: client.o libft/libft.a
	$(CC) -o $@ $< -Llibft -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	
fclean: clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: all bonus clean fclean re