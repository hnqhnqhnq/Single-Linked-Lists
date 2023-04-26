#pragma once

typedef struct node {
    int key;
    struct node *next;
} NodeT;

typedef struct _SLL_ {
    NodeT *first;
    NodeT *last;
    int size;
} SLL;

NodeT *createNode(int givenKey);

void printList(SLL list);

void insertFirst(SLL *list, int givenKey);

void insertLast(SLL *list, int givenKey);

NodeT *searchNode(SLL list, int givenKey);

void insertAfter(SLL *list, int afterKey, int givenKey);

void insertBefore(SLL *list, int beforeKey, int givenKey);

void deleteFirst(SLL *list);

void deleteLast(SLL *list);

void deleteKey(SLL* list, int givenKey);

void deleteList(SLL *list);

void listSize(SLL *list);

void reverseList(SLL *list);

