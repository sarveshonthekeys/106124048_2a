#ifndef COMMENT_H
#define COMMENT_H

#include "reply.h"

typedef struct Comment {
    char *username;
    char *content;
    Reply *replies;
    struct Comment *next;
    struct Comment *prev;
} Comment;

Comment* createcomment(char *username, char *content);
void freecomment(Comment *c);

#endif
