#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define sz 10
typedef long long ll;
struct stack {
    int *arr;
    int *last;
    int size;
};
typedef struct stack stack;

stack init_stack() {
    stack st;
    st.size = sz;
    st.arr = (int *) malloc(st.size * sizeof(int));
    st.last = &st.arr[0];
    return st;
}

bool empty(stack *st) {
    return st->last == st->arr;
}

void push(stack *st, int new) {
    if (st->last - st->arr + 1 == st->size) {
        ll ind = st->last - st->arr;
        st->size += sz;
        st->arr = (int *) realloc(st->arr, st->size * (sizeof(int)));
        st->last = &st->arr[ind];
    }
    st->last++;
    *(st->last) = new;
}

int pop(stack *st) {
    int ans = *(st->last);
    st->last--;
    return ans;
}

int get_last(stack *st) {
    return *(st->last);
}

int main() {
    stack st = init_stack();
    for (int i = 0; i < 30; i++) {
        push(&st, i);
        printf("%d ", get_last(&st));
    }
    printf("\n");
    while (!empty(&st)) {
        printf("%d ", pop(&st));
    }
    push(&st, 1000);
    printf("\n");
    printf("%d", get_last(&st));
}