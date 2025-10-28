#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "post.h"
#include "utils.h"

Post* createpost(char *username, char *caption) {
    if (!username || !caption) return NULL;
    Post *p = malloc(sizeof(Post));
    if (!p) return NULL;
    p->username = str_duplicate(username);
    p->caption = str_duplicate(caption);
    p->comments = NULL;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void freepost(Post *p) {
    if (!p) return;
    free(p->username);
    free(p->caption);
    Comment *c = p->comments;
    while (c) {
        Comment *next = c->next;
        freecomment(c);
        c = next;
    }
    free(p);
}
