
#include "lib/core.h"

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 8585
#define BUFFER_SIZE 1024

fn error(const char *msg)
{
    perror(msg);
    exit(1);
}
fn panic(const char *message) {
    fprintf(stderr, "Panic: %sn", message);
    exit(EXIT_FAILURE); // یا می‌توانید از abort() استفاده کنید
}

Int main()
{
    Int server_fd = 0;
    Int new_socket = 0;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    char buffer[BUFFER_SIZE];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        error("ERROR opening socket");
    }

    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        error("ERROR on binding");
    }

    if (listen(server_fd, 3) < 0)
    {
        error("ERROR on listen");
    }

    printf("Server is listening on port %d\n", PORT);

    while (1)
    {

        new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);
        if (new_socket < 0)
        {
            error("ERROR on accept");
        }

        memset(buffer, 0, BUFFER_SIZE);
        read(new_socket, buffer, BUFFER_SIZE);
        printf("Received request:\n%s\n", buffer);

        if (strstr(buffer, "GET") != null)
        {
            printf("Hello\n");
        }

        const char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nHello\n";
        write(new_socket, response, strlen(response));

        close(new_socket);
    }

    close(server_fd);
    return 0;
}
