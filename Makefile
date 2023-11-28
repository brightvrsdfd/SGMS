# Makefile
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lpthread

all: server client

server: server/server.o server/user.o server/file.o server/snapshot.o
	$(CC) $(CFLAGS) -o bin/server $^ $(LDFLAGS)

client: client/client.o client/menu.o
	$(CC) $(CFLAGS) -o bin/client $^ $(LDFLAGS)

server/server.o: server/server.c server/server.h
	$(CC) $(CFLAGS) -c -o $@ $<

server/user.o: server/user.c server/server.h
	$(CC) $(CFLAGS) -c -o $@ $<

server/file.o: server/file.c server/server.h
	$(CC) $(CFLAGS) -c -o $@ $<

server/snapshot.o: server/snapshot.c server/server.h
	$(CC) $(CFLAGS) -c -o $@ $<

client/client.o: client/client.c client/client.h
	$(CC) $(CFLAGS) -c -o $@ $<

client/menu.o: client/menu.c client/client.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean_o:
	rm -f server/*.o client/*.o

clean_all:
	rm -f server/*.o client/*.o bin/server bin/client