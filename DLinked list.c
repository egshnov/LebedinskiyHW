#include <stdio.h>
#include <malloc.h>

struct dnode {
    int value;
    struct dnode *next, *previous;
};
typedef struct dnode dnode;
struct list {
    dnode *head;
};
typedef struct list list;

dnode *init_dnode(int value) {
    dnode *new = (dnode *) malloc(sizeof(dnode)); // новый узел
    new->value = value;
    new->next = NULL;
    new->previous = NULL;
    return new;
}

list init_list() {
    list *new_list = (list *) malloc(sizeof(list));
    new_list->head = NULL;
    return *new_list;
}

list copy_list(list *l) {
    list new_list = init_list();
    dnode *tmp = l->head;
    dnode **last = &new_list.head;
    while (tmp != NULL) {
        dnode *new = init_dnode(tmp->value);
        (*last) = new;
        last = &(*last)->next;
        tmp = tmp->next;
    }
    return new_list;
}

void insert(list *l, int d, int ind) {
    dnode *new = init_dnode(d);
    dnode **p = &l->head; //указатель на указатель на голову
    for (int i = 0; i < ind; i++) {
        p = &((*p)->next);
    }
    new->next = *p;
    new->previous = (*p != NULL ? (*p)->previous : NULL);
    *p = new;
    (*p)->previous = new->previous;
}

void print_list(list l) {
    dnode **tmp = &l.head;
    while (*tmp != NULL) {
        printf("%d ", (*tmp)->value);
        tmp = &(*tmp)->next;
    }
    printf("\n");
}

void back_print(list l) {
    dnode *p = l.head;
    while (p->next != NULL) {
        printf("next\n");
        p = p->next;
    }
    while (p->previous != NULL) {
        printf("%d ", p->value);
        p = p->previous;
    }
    printf("\n");
}

int main() {
    list l = init_list();
    for (int i = 0; i < 15; i++) {
        insert(&l, i, i);
    }
    print_list(l);
    back_print(l);
}