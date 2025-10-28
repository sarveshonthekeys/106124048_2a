#ifndef POST_H
#define POST_H

#include <stdbool.h>
#include "comment.h"

typedef struct Post {
    char *username;
    char *caption;
    Comment *comments;
    struct Post *next;
    struct Post *prev;
} Post;

Post* createpost(char *username, char *caption);
void freepost(Post *p);

#endif
