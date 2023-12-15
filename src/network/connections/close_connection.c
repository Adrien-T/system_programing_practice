
#include "network.h"

#include <unistd.h>

void close_connection(connection_t *connect)
{
    close(connect->fd);
    destroy_buffer(&connect->read_buff);
    destroy_buffer(&connect->write_buff);
}
