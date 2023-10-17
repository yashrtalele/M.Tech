/*
============================================================================
Name : server.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program to communicate between two machines using socket.
Date: 6th Oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>

void main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    char message[1024];
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    listen(server_socket, 10);
    client_socket = accept(server_socket, NULL, NULL);
    if (client_socket == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    if (recv(client_socket, message, sizeof(message), 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("Received message from client: %s\n", message);
    if (send(client_socket, "Hello, This is Server!\n", 23, 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    close(server_socket);
    close(client_socket);

}