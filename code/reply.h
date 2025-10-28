#ifndef REPLY_H
#define REPLY_H

typedef struct Reply {
    char *username;
    char *content;
    struct Reply *next;
    struct Reply *prev;
} Reply;

Reply* createreply(char *username, char *content);
void freereply(Reply *r);

#endif
