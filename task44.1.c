#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#define NODE(TYPE) \
struct Node_##TYPE \
{ \
TYPE d; \
struct Node_##TYPE *n; \
};

#define get_i(TYPE) \
struct Node_##TYPE *get_i##TYPE(struct Node_##TYPE *st, int i){ \
    struct Node_##TYPE *p = st;\
    for(int j = 0; j < i; j ++){               \
        p = p->n;           \
    }               \
    return p;                    \
}
NODE(int)
NODE(double)

get_i(double)

get_i(int)

struct Node {
    int d;
    struct Node *n;
};

bool check(int n) {
    return n % 2 != 0;
}

int cnt(struct Node_int *st, bool(*check)(int)) {
    struct Node_int *p = st;
    int cnt = 0;
    while (p != NULL) {
        if (check(p->d)) {
            cnt++;
        }
        p = p->n;
    }
    return cnt;
}

struct Node *get_fl(struct Node *st, int num, bool first) {
    struct Node *p = st;
    struct Node *ans = NULL;
    while (p != NULL) {
        if (p->d == num) {
            ans = p;
            if (first) {
                break;
            }
        }
        p = p->n;
    }
    return ans;
}

void add(struct Node **f, int d, int ind) {
    struct Node *p = f;
    if (ind == 0) {
        p = (struct Node *) (malloc(sizeof(struct Node)));
        p->d = d;
        p->n = f;
        f = p;
    } else {
        for (int i = 0; i < ind; i++) {
            p = p->n;
        }
    }
}

int main() {
    struct Node n1 = {1, NULL};
    add(&n1, 10, 0);
    printf("%d", n1.d);
}