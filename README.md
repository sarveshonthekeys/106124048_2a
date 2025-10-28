# CSPC32 - Assignment 2 (Task 2a)
## Social Media Platform ADT (in C)

### Description
Implements a modular social media platform supporting:
- Posts, Comments, and Replies
- View, Add, Delete, and Navigate operations
- Fully modular ADTs: `Post`, `Comment`, `Reply`, and `Platform`

### Files
| File | Purpose |
|------|----------|
| post.[ch] | Defines Post ADT |
| comment.[ch] | Defines Comment ADT |
| reply.[ch] | Defines Reply ADT |
| platform.[ch] | Defines Platform ADT |
| utils.[ch] | Helper functions |
| io_helper.[ch] | Centralized I/O printing |
| main.c | CLI driver |
| Makefile | Builds executable |

### Build
```bash
cd code
make
./app
```

### Notes about naming
All function and variable identifiers are lowercase with no underscores as requested.
Type names (Post, Comment, Reply, Platform) are kept capitalized.

### Assumptions
- Each username and caption are single strings (no spaces).
- Comments and replies are stored in chronological order.
- Platform supports one instance globally.
