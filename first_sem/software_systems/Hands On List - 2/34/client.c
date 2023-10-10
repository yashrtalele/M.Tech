#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORT 8888

void main() {
    struct sockaddr_in serv;
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(PORT);
    connect(sd, (struct sockaddr *)&serv, sizeof(serv));
    char buf[1024];
    write(sd, "Client", 6);
    read(sd, buf, 3);
    printf("%s\n", buf);
}