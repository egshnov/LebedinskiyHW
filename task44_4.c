#include <stdio.h>
#include <malloc.h>

struct node {
    int value;
    struct node *next;
};
typedef struct node node;
struct List {
    node *head;
};
typedef struct List list;

void insert(list *l, int d, int ind) {
    node *new = (node *) malloc(sizeof(node)); // новый узел
    new->value = d;
    node **p = &l->head; //указатель на указатель на голову
    for (int i = 0; i < ind; i++) {
        p = &((*p)->next);
    }
    *p = new;
    new->next
}

int main() {
    node head = {1000, NULL};
    list l = {&head};
    insert(&l, 100, 0);
    printf("%d", l.head->value);
}