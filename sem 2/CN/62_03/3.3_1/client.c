#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
	int sock = 0;
	struct sockaddr_in serv_addr;
	char buffer[1024] = {0};
	char *quit_message = "QUIT";

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    	printf("\n Socket creation error \n");
    	return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	// Convert IPv4 and IPv6 addresses from text to binary form
	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
    	printf("\nInvalid address/ Address not supported \n");
    	return -1;
	}

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    	printf("\nConnection Failed \n");
    	return -1;
	}

	// Chat loop
	while (1) {
    	printf("Client: ");
    	fgets(buffer, 1024, stdin);
    	//buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline
    fflush(stdin);
    	send(sock, buffer, strlen(buffer), 0);

    	if (strcmp(buffer, quit_message) == 0) {
        	printf("Client terminated the connection.\n");
        	break;
    	}

    	int valread = read(sock, buffer, 1024);
    	if (valread < 0) {
        	perror("read");
        	break;
    	}

    	printf("Server: %s\n", buffer);
	}

	close(sock);
	return 0;
}

