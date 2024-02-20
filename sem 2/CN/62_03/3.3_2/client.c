#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/sendfile.h>

#define PORT 8080
#define SEGMENT_SIZE 50
#define BUFFER_SIZE 1500

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int client_socket, file_descriptor;
    struct sockaddr_in server_addr;

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

	//size_t size = sizeof(argv[1]);
	char fname[256];
	printf("Enter filename : ");
	scanf("%s",fname);
    send(client_socket, fname, sizeof(fname)+1, 0);
	
    file_descriptor = open(argv[1], O_RDONLY);
    char buffer[BUFFER_SIZE];
    ssize_t sent_bytes;
    size_t total_bytes = 0;

    while ((sent_bytes = sendfile(client_socket, file_descriptor, NULL, SEGMENT_SIZE)) > 0) {
    total_bytes += sent_bytes;
    printf("Sent segment of %d bytes\n", (int)sent_bytes);
}


    send(client_socket, "SEND-COMPLETE", strlen("SEND-COMPLETE") + 1, 0);
    printf("SEND-COMPLETE");

    close(file_descriptor);
    close(client_socket);

    return 0;
}
