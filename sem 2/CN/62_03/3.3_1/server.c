#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
	int server_fd, new_socket;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[1024] = {0};
	char *quit_message = "QUIT";

	// Create socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    	perror("socket failed");
    	exit(EXIT_FAILURE);
	}

	// Forcefully attach socket to the port
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    	perror("setsockopt");
    	exit(EXIT_FAILURE);
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	// Bind socket to address
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    	perror("bind failed");
    	exit(EXIT_FAILURE);
	}

	// Listen for incoming connections
	if (listen(server_fd, 3) < 0) {
    	perror("listen");
    	exit(EXIT_FAILURE);
	}

	if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
    	perror("accept");
    	exit(EXIT_FAILURE);
	}

	// Chat loop
	while (1) {
    	int valread = read(new_socket, buffer, 1024);
    	if (valread < 0) {
        	perror("read");
        	break;
    	}

    	printf("Client: %s\n", buffer);

    	if (strcmp(buffer, quit_message) == 0) {
        	printf("Client terminated the connection.\n");
        	break;
    	}

    	printf("Server: ");
    	fgets(buffer, 1024, stdin);
    	// buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline
    fflush(stdin);
    	send(new_socket, buffer, strlen(buffer), 0);

    	if (strcmp(buffer, quit_message) == 0) {
        	printf("Server terminated the connection.\n");
        	break;
    	}
	}

	// Close sockets
	close(new_socket);
	close(server_fd);
	return 0;
}

