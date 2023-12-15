
#include "network.h"
#include "tcp.h"

int main()
{
    connection_t *connections = NULL;
    socket_t *server = create_socket(5011);

    if (!tcp_socket_server_setup(server))
        return (0);
    while (1) {
        server_duties(server, &connections);
        for (connection_t *con = connections; con; con = con->next) {
            if (con->status == READ)
                create_buff(&con->write_buff, "Hello\n\0");
            if (con->status == WRITE_SUCCESS)
                con->status = FINISHED;
        }
    }
}

