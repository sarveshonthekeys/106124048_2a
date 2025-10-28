#include <stdlib.h>
#include <string.h>
#include "comment.h"
#include "utils.h"

Comment* createcomment(char *username, char *content) {
    if (!username || !content) return NULL;
    Comment *c = malloc(sizeof(Comment));
    if (!c) return NULL;
    c->username = str_duplicate(username);
    c->content = str_duplicate(content);
    c->replies = NULL;
    c->next = NULL;
    c->prev = NULL;
    return c;
}

void freecomment(Comment *c) {
    if (!c) return;
    free(c->username);
    free(c->content);
    Reply *r = c->replies;
    while (r) {
        Reply *next = r->next;
        freereply(r);
        r = next;
    }
    free(c);
}
