#include <stdlib.h>
#include <string.h>
#include "reply.h"
#include "utils.h"

Reply* createreply(char *username, char *content) {
    if (!username || !content) return NULL;
    Reply *r = malloc(sizeof(Reply));
    if (!r) return NULL;
    r->username = str_duplicate(username);
    r->content = str_duplicate(content);
    r->next = NULL;
    r->prev = NULL;
    return r;
}

void freereply(Reply *r) {
    if (!r) return;
    free(r->username);
    free(r->content);
    free(r);
}
