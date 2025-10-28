#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "platform.h"
#include "io_helper.h"

int main() {
    createplatform();

    char command[128];
    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "create") == 0) {
            char arg[32];
            if (scanf("%s", arg) != 1) break;
            if (strcmp(arg, "platform") == 0) createplatform();
        }
        else if (strcmp(command, "add") == 0) {
            char type[32];
            if (scanf("%s", type) != 1) break;
            if (strcmp(type, "post") == 0) {
                char user[256], caption[1024];
                if (scanf("%s %s", user, caption) != 2) break;
                addpost(user, caption);
            } else if (strcmp(type, "comment") == 0) {
                char user[256], content[1024];
                if (scanf("%s %s", user, content) != 2) break;
                addcomment(user, content);
            } else if (strcmp(type, "reply") == 0) {
                char user[256], content[1024];
                int n;
                if (scanf("%s %s %d", user, content, &n) != 3) break;
                addreply(user, content, n);
            }
        }
        else if (strcmp(command, "delete") == 0) {
            char type[32];
            if (scanf("%s", type) != 1) break;
            if (strcmp(type, "post") == 0) {
                int n; if (scanf("%d", &n) != 1) break;
                deletepost(n);
            } else if (strcmp(type, "comment") == 0) {
                int n; if (scanf("%d", &n) != 1) break;
                deletecomment(n);
            } else if (strcmp(type, "reply") == 0) {
                int n,m; if (scanf("%d %d", &n, &m) != 2) break;
                deletereply(n,m);
            }
        }
        else if (strcmp(command, "view") == 0) {
            char type[32];
            if (scanf("%s", type) != 1) break;
            if (strcmp(type, "post") == 0) {
                int n; if (scanf("%d", &n) != 1) break;
                printpost(viewpost(n));
            } else if (strcmp(type, "comments") == 0) {
                printcomments(viewcomments());
            }
        }
        else if (strcmp(command, "current") == 0) {
            char arg[32];
            if (scanf("%s", arg) != 1) break;
            if (strcmp(arg, "post") == 0) printpost(currpost());
        }
        else if (strcmp(command, "next") == 0) {
            char arg[32];
            if (scanf("%s", arg) != 1) break;
            if (strcmp(arg, "post") == 0) printpost(nextpost());
        }
        else if (strcmp(command, "previous") == 0) {
            char arg[32];
            if (scanf("%s", arg) != 1) break;
            if (strcmp(arg, "post") == 0) printpost(previouspost());
        }
    }

    return 0;
}
