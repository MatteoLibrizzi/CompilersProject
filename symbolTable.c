#include "symbolTable.h"

void init() {
    date = NULL;
    customerListHead = NULL;
    currentCustomer = NULL;
    currentNamesHead = NULL;
}

void setDate (char* parsedDate){
    int length = strlen(parsedDate);
    date = (char*) malloc(sizeof(char) * length);
    date = strcpy(date, parsedDate);
}

void addCustomerToList (Customer c) {
    if (customerListHead == NULL) {
        customerListHead = c;
        return;
    }

    Customer node = customerListHead;
    while (node->next != NULL) {
        node = node->next;
    }
    node->next = c;
}

void setCurrentCustomer (Customer c) {
    currentCustomer = c;
}

Customer customerConstructor (char* socialSecurityNumber) {
    Customer c = (Customer) malloc(sizeof(customer));
    int length = strlen(socialSecurityNumber);
    c->socialSecurityNumber = (char*) malloc(sizeof(char) * length);
    c->socialSecurityNumber = strcpy(c->socialSecurityNumber, socialSecurityNumber);
    c->nameListHead = NULL;
    c->transactionListHead = NULL;
    c->next = NULL;
    return c;
}

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

TransactionNode transactionNodeConstructor (long amount) {
    TransactionNode t = (TransactionNode) malloc(sizeof(transactionNode));
    t->next = NULL;
    t->amount = amount;

    return t;
}

void addTransactionToCustomer (Customer customer, long amount) {
    TransactionNode newNode = transactionNodeConstructor(amount);
    if (customer == NULL) {
        printf("aha\n");
        return;
    }
    if (customer->transactionListHead == NULL) {
        customer->transactionListHead = newNode;
        return;
    }
    TransactionNode node = customer->transactionListHead;
    while (node->next != NULL) {
        node = node->next;
    }
    node->next = newNode;
}


void addCurrentNameListToCustomer (char* socialSecurityNumber) {
    Customer c = findCustomerBySocialSecurityNumber(customerListHead, socialSecurityNumber);
    if (c == NULL) {
        return;
    }
    c->nameListHead = currentNamesHead;
    currentNamesHead = NULL;
}