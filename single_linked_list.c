#include <stdio.h>
#include <stdlib.h>
#include "single_linked_list.h"

NodeT *createNode(int givenKey) {
    NodeT *node = malloc(sizeof(NodeT));

    if (node == NULL) {
        printf("Couldn't allocate memory for the node.");
        return NULL;
    }

    node->key = givenKey;
    node->next = NULL;

    return node;
}

void insertFirst(SLL *list, int givenKey) {
    NodeT *node = createNode(givenKey);

    if (list->first == NULL) {
        list->first = list->last = node;
        return;
    }

    node->next = list->first;
    list->first = node;
}

void printList(SLL list) {
    NodeT *current = list.first;

    while (current != NULL) {
        printf("%d ", current->key);
        current = current->next;
    }
}

void insertLast(SLL *list, int givenKey) {
    NodeT *node = createNode(givenKey);

    if (list->first == NULL) {
        list->first = list->last = node;
        return;
    }

    list->last->next = node;
    list->last = node;
}

NodeT *searchNode(SLL list, int givenKey) {
    NodeT *current = list.first;

    while (current != NULL) {
        if (current->key == givenKey)
            return current;
        current = current->next;
    }
}

void insertAfter(SLL *list, int afterKey, int givenKey) {
    NodeT *current = list->first;
    NodeT *node = createNode(givenKey);

    if (afterKey == list->last->key) {
        list->last->next = node;
        list->last = node;
        return;
    }

    while (current != NULL) {
        if (current->key == afterKey) {
            node->next = current->next;
            current->next = node;
            return;
        }

        current = current->next;
    }
}

void insertBefore(SLL *list, int beforeKey, int givenKey) {
    NodeT *node = createNode(givenKey);
    NodeT *current = list->first;

    if (beforeKey == list->first->key) {
        node->next = list->first;
        list->first = node;
        return;
    }

    while (current != NULL) {
        if (current->next->key == beforeKey) {
            node->next = current->next;
            current->next = node;
            return;
        }

        current = current->next;
    }
}

void deleteFirst(SLL *list) {
    NodeT *current = list->first;

    if (list->first != NULL) {
        if (list->first == list->last) {
            list->first = list->last = NULL;
            return;
        }

        list->first = list->first->next;
        free(current);

        if (list->first == NULL) {
            list->last = NULL;
            return;
        }
    }
}

void deleteLast(SLL *list) {
    NodeT *current = list->first;
    NodeT *aux = list->last;

    if (list->first != NULL) {
        if (list->first == list->last) {
            list->first = list->last = NULL;
            return;
        }

        while (current->next != list->last)
            current = current->next;

        list->last = current;
        current->next = NULL;
        free(aux);

        if (list->first == NULL) {
            list->last = NULL;
            return;
        }
    }
}

void deleteKey(SLL *list, int givenKey) {
    NodeT *current = list->first;
    NodeT *previous = NULL;

    if (list->first != NULL) {
        while (current->next != NULL) {
            if (current->key == givenKey)
                break;
            else {
                previous = current;
                current = current->next;
            }
        }

        if (current != NULL) {
            if (current == list->first) {
                list->first = list->first->next;
                free(current);

                if (list->first == NULL)
                    list->last = NULL;
            } else {
                previous->next = current->next;
                if (current = list->last)
                    list->last = previous;
                free(current);
            }

        }
    }
}

void deleteList(SLL *list) {
    NodeT *current = list->first;
    NodeT *previous = NULL;

    if (list == NULL)
        return;

    while (current != NULL) {
        previous = current;
        current = current->next;
        free(previous);
    }
    free(current);

    list->first = list->last = NULL;
}

void listSize(SLL *list) {
    list->size = 0;

    NodeT *current = list->first;

    while (current != NULL) {
        current = current->next;
        list->size++;
    }

    printf("\nThe size of the list is: %d\n", list->size);
}

void reverseList(SLL *list) {

    NodeT *current = list->first;
    NodeT *previous = NULL;
    NodeT *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    list->first = previous;
}
