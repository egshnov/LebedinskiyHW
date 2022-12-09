#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};
typedef struct node node;

node *init_node(int value) {
    node *new = (node *) malloc(sizeof(node)); // новый узел
    new->value = value;
    new->next = NULL;
    return new;
}

node *init_node_nx(int value, node *nx) {
    node *new = (node *) malloc(sizeof(node)); // новый узел
    new->value = value;
    new->next = nx;
    return new;
}

struct List {
    node *head;
};
typedef struct List list;

list init_list() {
    list *new_list = (list *) malloc(sizeof(list));
    new_list->head = NULL;
    return *new_list;
}

void insert(list *l, int d, int ind) {
    node *new = init_node(d);
    node **p = &l->head; //указатель на указатель на голову
    for (int i = 0; i < ind; i++) {
        p = &((*p)->next);
    }
    new->next = *p;
    *p = new;
}

list copy_list(list *l) {
    list new_list = init_list();
    node *tmp = l->head;
    node **last = &new_list.head;
    while (tmp != NULL) {
        node *new = init_node(tmp->value);
        (*last) = new;
        last = &(*last)->next;
        tmp = tmp->next;
    }
    return new_list;
}

list merge(list *l1, list *l2) {
    list new_list = init_list();
    node **last = &new_list.head;
    node *p1 = l1->head;
    node *p2 = l2->head;
    while (p1 != NULL && p2 != NULL) {
        if (p1->value <= p2->value) {
            node *new = p1;
            p1 = p1->next;
            (*last) = new;
            last = &(*last)->next;
        } else {
            node *new = p2;
            p2 = p2->next;
            (*last) = new;
            last = &(*last)->next;
        }
    }
    if (p1 == NULL) {
        *last = p2;
    } else {
        *last = p1;
    }

    return new_list;
}

node *rec_copy_node(node *nd) {
    if (nd == NULL) {
        return nd;
    }
    return init_node_nx(nd->value, rec_copy_node(nd->next));
}

list rec_copy(list *l) {
    list new_list = init_list();
    new_list.head = rec_copy_node(l->head);
    return new_list;
}


node *get_i(list *l, int ind) {
    node *p = l->head;
    for (int i = 0; i < ind; i++) {
        p = p->next;
    }
    return p;
}

node *get_first(list *l, int value) {
    node *p = l->head;
    while (p != NULL) {
        if (p->value == value) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

node *get_last(list *l, int value) {
    node *p = l->head;
    node *ans = NULL;
    while (p != NULL) {
        if (p->value == value) {
            ans = p;
        }
        p = p->next;
    }
    return ans;
}

void remove_i(list *l, int ind) {
    node **p = &(l->head);
    for (int i = 0; i < ind; i++) {
        p = &(*p)->next;
    }
    node *tst = *p;
    *p = (*p)->next;
    free(tst);
}

void remove_if(list *l, _Bool(*check)(int)) {
    node **p = &(l->head);
    while (*p != NULL) {
        //printf("%d\n", (*p)->value);
        if (check((*p)->value)) {
            node *tst = *p;
            *p = (*p)->next;
            free(tst);
        } else { p = &(*p)->next; }
    }
}

int cnt(list *l, _Bool(*check)(int)) {
    node *p = l->head;
    int cnt = 0;
    while (p != NULL) {
        if (check(p->value)) {
            cnt++;
        }
        p = p->next;
    }
    return cnt;
}

void reverse_list(list *l) {
    node *cur = l->head;
    node *prev = NULL;
    while (cur != NULL) {
        node *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    l->head = prev;
}

void print_list(list l) {
    node **tmp = &l.head;
    while (*tmp != NULL) {
        printf("%d\n", (*tmp)->value);
        tmp = &(*tmp)->next;
    }
}

_Bool check(int i) {
    return i % 2 == 0;
}

int main() {
    list l1 = init_list();
    for (int i = 0, ind = 0; i <= 16; i += 2, ind++) {
        insert(&l1, i, ind);
    }
    list l2 = init_list();
    for (int i = 1, ind = 0; i <= 16; i += 2, ind++) {
        insert(&l2, i, ind);
    }
    list ans = merge(&l1, &l2);
    print_list(ans);
}