#include <stdbool.h>
#include "Linked list.c"

struct stack {
    list l;
    node *last;
};
typedef struct stack stack;

stack init_stack() {
    stack st;
    st.l = init_list();
    st.last = st.l.head;
    return st;
}

bool is_empty(stack *st) {
    return st->l.head == st->last;
}

void push(stack *st, int new) {
    node *tmp = init_node(new);
    node **head = &(st->l.head);
    tmp->next = (*head);
}

int main() {
    list l = init_list();
    for (int i = 0; i < 15; i++) {
        append(&l, i);
    }

}