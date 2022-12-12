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

void insert(list *l, int value, int ind) {
    dnode *new = init_dnode(value);
    dnode **p = &l->head; //указатель на указатель на голову
    for (int i = 0; i < ind - 1; i++) {
        p = &((*p)->next);
    }
    if (*p == NULL) {
        *p = new;
    } else if ((*p)->next == NULL) {
        (*p)->next = new;
        new->previous = (*p);
    } else {
        new->next = (*p)->next;
        (*p)->next = new;
        new->previous = (*p);
        new->next->previous = new;
    }
}

list copy_list(list *l) {
    list new_list = init_list();
    dnode *tmp = l->head;
    dnode **last = &new_list.head;
    dnode *prev = NULL;
    while (tmp != NULL) {
        dnode *new = init_dnode(tmp->value);
        new->previous = prev;
        prev = new;
        (*last) = new;
        last = &(*last)->next;
        tmp = tmp->next;
    }
    return new_list;
}

void del(list *l, dnode *target) {
    if (l->head == NULL || target == NULL) {
        return;
    }
    if (l->head == target) {
        l->head = target->next;
    }
    if (target->next != NULL) {
        target->next->previous = target->previous;
    }
    if (target->previous != NULL) {
        target->previous->next = target->next;
    }
    free(target);
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
    list new_list = copy_list(&l);
    print_list(new_list);
    back_print(new_list);
    insert(&new_list, 1000, 5);
    print_list(new_list);
    back_print(new_list);
    dnode *target = get_i(&new_list, 5);
    del(&new_list, target);
    print_list(new_list);
    back_print(new_list);
}