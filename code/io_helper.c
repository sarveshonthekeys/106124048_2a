#include <stdio.h>
#include "io_helper.h"

void printpost(Post *p) {
    if (!p) {
        printf("Post does not exist.\n");
        return;
    }
    printf("%s %s\n", p->username, p->caption);
}

void printcomments(Comment *c) {
    while (c) {
        printf("%s %s\n", c->username, c->content);
        Reply *r = c->replies;
        while (r) {
            printf("%s %s\n", r->username, r->content);
            r = r->next;
        }
        c = c->next;
    }
}
