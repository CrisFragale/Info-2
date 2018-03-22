all: client server

client: client.c EZsockets.c
	gcc client.c EZsockets.c -o client -Wall

server: EZsockets.c server.c server_fnt.c
	gcc EZsockets.c server.c server_fnt.c -o server -Wall
