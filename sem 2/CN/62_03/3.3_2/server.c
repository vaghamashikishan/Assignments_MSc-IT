#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <fcntl.h>

#define PORT 8080
#define SEGMENT_SIZE 50
#define BUFFER_SIZE 1500

typedef struct {
    int client_socket;
    char filename[256];
} client_data;

void *handle_client(void *arg) {
    client_data *data = (client_data *)arg;
    int client_socket = data->client_socket;
    char filename[256];
    strcpy(filename, data->filename);
    int file_descriptor = open(filename, O_WRONLY | O_CREAT, 0644);
    char buffer[BUFFER_SIZE];
    ssize_t received_bytes;
    size_t total_bytes = 0;

    while ((received_bytes = recv(client_socket, buffer, SEGMENT_SIZE, 0)) > 0) {
    write(file_descriptor, buffer, received_bytes);
    total_bytes += received_bytes;
    printf("Received segment of %d bytes\n", (int)received_bytes);
}


    // Check for "SEND-COMPLETE" after the loop
    if (strstr(buffer, "SEND-COMPLETE") != NULL) {
    printf("File %s received completely\n", filename);
    send(client_socket, "FILE-RECEIVED", strlen("FILE-RECEIVED") + 1, 0);
}


    // Close the file and socket
    close(file_descriptor);
    close(client_socket);
    free(data);

    return NULL;
}


int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Buffer to store received data
    char buffer[BUFFER_SIZE];

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Configure the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Listen for incoming connections
    listen(server_socket, 3);

    printf("Server started and waiting for clients...\n");

    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len))) {
        printf("Client connected\n");

        // Receive filename from the client
        recv(client_socket, buffer, BUFFER_SIZE, 0);
        printf("Received filename: %s\n", buffer);

        // Create a data structure to pass to the thread
        client_data *data = malloc(sizeof(client_data));
        strcpy(data->filename, buffer);
        data->client_socket = client_socket;

        // Create a new thread to handle the client
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)data);
        pthread_detach(thread_id);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}
