#include <stdlib.h>
#include "platform.h"
#include "utils.h"

Platform platform = {NULL, NULL};

static Post* getnthpost(int n) {
    Post *it = platform.posts;
    for (int i = 1; it && i < n; i++) it = it->next;
    return it;
}

static Comment* getnthcomment(Post *p, int n) {
    if (!p) return NULL;
    int count = 0;
    for (Comment *c = p->comments; c; c = c->next) count++;
    if (n > count || n <= 0) return NULL;
    int target = count - n;
    Comment *c = p->comments;
    for (int i = 0; i < target; i++) c = c->next;
    return c;
}

static Reply* getnthreply(Comment *c, int m) {
    if (!c) return NULL;
    int count = 0;
    for (Reply *r = c->replies; r; r = r->next) count++;
    if (m > count || m <= 0) return NULL;
    int target = count - m;
    Reply *r = c->replies;
    for (int i = 0; i < target; i++) r = r->next;
    return r;
}

Platform* createplatform() {
    platform.posts = NULL;
    platform.lastviewedpost = NULL;
    return &platform;
}

bool addpost(char *username, char *caption) {
    Post *p = createpost(username, caption);
    if (!p) return false;
    p->next = platform.posts;
    if (platform.posts) platform.posts->prev = p;
    platform.posts = p;
    if (!platform.lastviewedpost) platform.lastviewedpost = p;
    return true;
}

bool deletepost(int n) {
    Post *target = getnthpost(n);
    if (!target) return false;
    if (target->prev) target->prev->next = target->next;
    else platform.posts = target->next;
    if (target->next) target->next->prev = target->prev;
    freepost(target);
    return true;
}

Post* viewpost(int n) {
    Post *p = getnthpost(n);
    if (p) platform.lastviewedpost = p;
    return p;
}

Post* currpost() {
    return platform.lastviewedpost ? platform.lastviewedpost : platform.posts;
}

Post* nextpost() {
    if (!platform.lastviewedpost) return NULL;
    if (!platform.lastviewedpost->next) {
        platform.lastviewedpost = platform.lastviewedpost;
        return platform.lastviewedpost;
    }
    platform.lastviewedpost = platform.lastviewedpost->next;
    return platform.lastviewedpost;
}

Post* previouspost() {
    if (!platform.lastviewedpost) return NULL;
    if (!platform.lastviewedpost->prev) {
        platform.lastviewedpost = platform.lastviewedpost;
        return platform.lastviewedpost;
    }
    platform.lastviewedpost = platform.lastviewedpost->prev;
    return platform.lastviewedpost;
}

bool addcomment(char *username, char *content) {
    Post *p = currpost();
    if (!p) return false;
    Comment *c = createcomment(username, content);
    if (!c) return false;
    if (!p->comments) p->comments = c;
    else {
        Comment *iter = p->comments;
        while (iter->next) iter = iter->next;
        iter->next = c;
        c->prev = iter;
    }
    return true;
}

bool deletecomment(int n) {
    Post *p = currpost();
    if (!p) return false;
    Comment *target = getnthcomment(p, n);
    if (!target) return false;
    if (target->prev) target->prev->next = target->next;
    else p->comments = target->next;
    if (target->next) target->next->prev = target->prev;
    freecomment(target);
    return true;
}

Comment* viewcomments() {
    Post *p = currpost();
    return p ? p->comments : NULL;
}

bool addreply(char *username, char *content, int n) {
    Post *p = currpost();
    if (!p) return false;
    Comment *c = getnthcomment(p, n);
    if (!c) return false;
    Reply *r = createreply(username, content);
    if (!r) return false;
    if (!c->replies) c->replies = r;
    else {
        Reply *it = c->replies;
        while (it->next) it = it->next;
        it->next = r;
        r->prev = it;
    }
    return true;
}

bool deletereply(int n, int m) {
    Post *p = currpost();
    if (!p) return false;
    Comment *c = getnthcomment(p, n);
    if (!c) return false;
    Reply *r = getnthreply(c, m);
    if (!r) return false;
    if (r->prev) r->prev->next = r->next;
    else c->replies = r->next;
    if (r->next) r->next->prev = r->prev;
    freereply(r);
    return true;
}
