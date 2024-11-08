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

/*
 * Function to send messages to a peer.
 */
void send_message() {
    // TODO: Implement message sending to a peer at a specified port.
    printf("Sending is not implemented yet.\n");
}

/*
 * Function to receive messages on this peer's port.
 */
void *receive_messages(void *server_socket_ptr) {
    // TODO: Implement receiving messages from other peers.
    printf("Receiving is not implemented yet.\n");
}
