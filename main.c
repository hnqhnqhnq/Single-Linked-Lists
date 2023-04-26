#include <stdio.h>
#include "single_linked_list.h"

int main() {
    SLL list;

    list.first = NULL;
    list.last = NULL;
    list.size = 0;

    insertFirst(&list, 5);
    insertFirst(&list, 4);
    insertFirst(&list, 3);
    insertFirst(&list, 2);
    insertFirst(&list, 1);

    insertLast(&list, 6);
    insertLast(&list, 7);
    insertLast(&list, 8);
    insertLast(&list, 9);
    insertLast(&list, 10);

    insertAfter(&list, 10, 11);
    insertAfter(&list, 3, 12);
    insertAfter(&list, 1, 13);

    insertBefore(&list, 1, 14);
    insertBefore(&list, 2, 15);
    insertBefore(&list, 5, 16);

    deleteFirst(&list);
    deleteFirst(&list);
    deleteFirst(&list);
    deleteFirst(&list);
    deleteFirst(&list);
    deleteFirst(&list);
    deleteFirst(&list);
    deleteFirst(&list);
    deleteFirst(&list);
    deleteFirst(&list);
    deleteFirst(&list);
    deleteFirst(&list);
    deleteFirst(&list);
    deleteFirst(&list);
    deleteFirst(&list);
    deleteFirst(&list);
    deleteFirst(&list);

    insertFirst(&list, 5);
    insertFirst(&list, 4);
    insertFirst(&list, 3);
    insertFirst(&list, 2);
    insertFirst(&list, 1);

    deleteLast(&list);
    deleteLast(&list);
    deleteLast(&list);
    deleteLast(&list);
    deleteLast(&list);

    insertFirst(&list, 5);
    insertFirst(&list, 4);
    insertFirst(&list, 3);
    insertFirst(&list, 2);
    insertFirst(&list, 1);

//    deleteKey(&list,1);
//    deleteKey(&list,2);
//    deleteKey(&list,3);
//    deleteKey(&list,4);
//    deleteKey(&list,5);

    //deleteList(&list);

    printList(list);
    listSize(&list);

    reverseList(&list);

    printList(list);



//    printf("\n%p", searchNode(list,1));
//    printf("\n%p", searchNode(list,10));
//    printf("\n%p", searchNode(list,5));
//    printf("\n%p", searchNode(list,11));

    return 0;
}
