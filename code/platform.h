#ifndef PLATFORM_H
#define PLATFORM_H

#include <stdbool.h>
#include "post.h"

typedef struct Platform {
    Post *posts;
    Post *lastviewedpost;
} Platform;

extern Platform platform;

Platform* createplatform();
bool addpost(char *username, char *caption);
bool deletepost(int n);
Post* viewpost(int n);
Post* currpost();
Post* nextpost();
Post* previouspost();
bool addcomment(char *username, char *content);
bool deletecomment(int n);
Comment* viewcomments();
bool addreply(char *username, char *content, int n);
bool deletereply(int n, int m);

#endif
