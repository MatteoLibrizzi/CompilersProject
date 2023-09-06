#include "namesListOperations.h"

PartialNameNode partialNameNodeConstructor (char* partialName) {
    PartialNameNode n = (PartialNameNode) malloc(sizeof(partialNameNode));
    n->next = NULL;
    int length = strlen(partialName);
    n->partialName = (char*) malloc(sizeof(char) * length);
    n->partialName = strcpy(n->partialName, partialName);

    return n;
}

void addPartialNameToCurrentList (char* partialName) {
    PartialNameNode newNode = partialNameNodeConstructor(partialName);
    if (currentNamesHead == NULL) {
        currentNamesHead = newNode;
        return;
    }
    PartialNameNode node = currentNamesHead;
    while (node->next != NULL) {
        node = node->next;
    }
    node->next = newNode;
}

void addCurrentNameListToCustomer (char* socialSecurityNumber) {
    Customer c = findCustomerBySocialSecurityNumber(customerListHead, socialSecurityNumber);
    if (c == NULL) {
        currentNamesHead = NULL;
        return;
    }
    c->nameListHead = currentNamesHead;
    currentNamesHead = NULL;
}