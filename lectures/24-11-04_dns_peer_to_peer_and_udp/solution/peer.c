#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

char peer_name[20];
int local_port;

void send_message();
void *receive_messages(void *server_socket_ptr);

int main() {
    printf("Enter your name: ");
    scanf("%s", peer_name);

    printf("Enter your port number: ");
    scanf("%d", &local_port);

    int server_socket;
    struct sockaddr_in local_address;

    // Create a socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure the local address
    local_address.sin_family = AF_INET;
    local_address.sin_addr.s_addr = INADDR_ANY;
    local_address.sin_port = htons(local_port);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&local_address, sizeof(local_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", local_port);

    // Start the receiving thread
    pthread_t receiver_thread;
    pthread_create(&receiver_thread, NULL, receive_messages, &server_socket);

    // Menu to send messages
    int choice;
    do {
        printf("\n1. Send message\n0. Quit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                send_message();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    close(server_socket);
    return 0;
}

void send_message() {
    int peer_port;
    char message[1024];
    char formatted_message[2048];
    struct sockaddr_in peer_address;

    printf("Enter the recipient's port: ");
    scanf("%d", &peer_port);

    // Create a socket to connect to the peer
    int peer_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (peer_socket < 0) {
        perror("Socket creation failed");
        return;
    }

    // Configure the peer's address
    peer_address.sin_family = AF_INET;
    peer_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // Always connecting to localhost
    peer_address.sin_port = htons(peer_port);

    if (connect(peer_socket, (struct sockaddr *)&peer_address, sizeof(peer_address)) < 0) {
        perror("Connection failed");
        close(peer_socket);
        return;
    }

    printf("Enter your message: ");
    getchar(); // Clear the buffer
    fgets(message, sizeof(message), stdin);
    snprintf(formatted_message, sizeof(formatted_message), "%s [PORT %d]: %s", peer_name, local_port, message);

    send(peer_socket, formatted_message, strlen(formatted_message), 0);
    printf("Message sent.\n");

    close(peer_socket);
}

void *receive_messages(void *server_socket_ptr) {
    int server_socket = *((int *)server_socket_ptr);
    struct sockaddr_in client_address;
    int client_socket;
    socklen_t addr_len = sizeof(client_address);
    char buffer[2048];

    while (1) {
        // Accept an incoming connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        // Receive the message
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received > 0) {
            printf("\nReceived: %s", buffer);
        }

        close(client_socket);
    }
    return NULL;
}
