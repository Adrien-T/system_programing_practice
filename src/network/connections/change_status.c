
#include "network.h"

void change_status(connection_t *connect)
{
    if (connect->status == DISCONNECTED || connect->status == EXCEPT || connect->status == FINISHED)
        return;
    if (connect->status == WRITE && connect->write_buff == NULL) {
        connect->status = WRITE_SUCCESS;
        return;
    }
    if (connect->status == WRITE) {
        connect->status = READ;
        return;
    }
    connect->status = READ;
    if (connect->write_buff)
        connect->status = WRITE;
}
