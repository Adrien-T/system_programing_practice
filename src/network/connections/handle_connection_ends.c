
#include "network.h"
#include <unistd.h>

void handle_connection_ends(connection_t **connect)
{
    connection_t *tmp = *connect;

    while (tmp && (tmp->status == FINISHED
    || tmp->status == DISCONNECTED)) {
        close_connection(tmp);
        *connect = tmp->next;
        free(tmp);
        tmp = *connect;
    }
    for (connection_t *curr = tmp; curr && curr->next; curr = curr->next) {
        if (curr->next->status == DISCONNECTED || curr->next->status ==
        FINISHED) {
            close_connection(curr->next);
            tmp = curr->next;
            curr->next = tmp->next;
            free(tmp);
        }
    }
}
