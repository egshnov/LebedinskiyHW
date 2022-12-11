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

void insert(list *l, int d, int ind) {
    dnode *new = init_dnode(d);
    dnode **p = &l->head; //указатель на указатель на голову
    dnode *prev = NULL;
    for (int i = 0; i < ind; i++) {
        if (i != ind - 2) {
            prev = (*p);
        }
        p = &((*p)->next);
    }
    new->next = (*p);
    if ((*p) != NULL) {
        prev = (*p)->previous;
        (*p)->previous = new;

    }
    new->previous = prev;
    *p = new;
}

list copy_list(list *l) {
    list new_list = init_list();
    dnode *tmp = l->head;
    dnode **last = &new_list.head;
    while (tmp != NULL) {
        dnode *new = init_dnode(tmp->value);
        new->previous = tmp->previous;
        (*last) = new;
        last = &(*last)->next;
        tmp = tmp->next;
    }
    return new_list;
}

void del(list *l, dnode *node) {
    if (l->head == node) {
        l->head = NULL;
        return;
    }
    dnode **prev = &node->previous;
    dnode **next = &node->next;
    (*prev)->next = (*next);
    (*next)->previous = (*prev);
    free(node);
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
        p = p->next;
    }
    while (p != NULL) {
        printf("%d ", p->value);
        p = p->previous;
    }
    printf("\n");
}

dnode *get_i(list *l, int ind) {
    dnode *p = l->head;
    for (int i = 0; i < ind; i++) {
        p = p->next;
    }
    return p;
}

int main() {
    list l = init_list();
    for (int i = 0; i < 15; i++) {
        insert(&l, i, i);
    }
    //print_list(l);
    insert(&l, 100000, 5);
    //print_list(l);
    //back_print(l);
    list new = copy_list(&l);
    dnode *p = get_i(&l, 5);
    del(&new, p);
    print_list(new);
    back_print(new);
}