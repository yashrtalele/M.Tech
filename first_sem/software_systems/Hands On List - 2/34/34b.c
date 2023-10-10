#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>
#define PORT 8888

void *Thread(void *sd) {
    int nsd = *(int *)sd;
    char buffer[1024];
    read(nsd, buffer, sizeof(buffer));
    printf("%s\n", buffer);
    char *Send = "Hi";
    write(nsd, Send, strlen(Send));
    printf("Client Acknowledged\n");
}

void main() {
    struct sockaddr_in address;
    int opt = 1;
    int len = sizeof(address);
    char buffer[1024];
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(sd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    bind(sd, (struct sockaddr *)&address, sizeof(address));
    listen(sd, 1);
    pthread_t clients;
    while (1) {
        int nsd = accept(sd, (struct sockaddr *)&address, (socklen_t *)&len);
        pthread_create(&clients, NULL, Thread, (void *)&nsd);
    }
}