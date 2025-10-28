CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
OBJS = main.o platform.o post.o comment.o reply.o utils.o io_helper.o

app: $(OBJS)
	$(CC) $(CFLAGS) -o app $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o app
