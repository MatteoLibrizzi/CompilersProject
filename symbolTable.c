#include "symbolTable.h"

void init() {
    date = NULL;
    customerListHead = NULL;
    currentCustomer = NULL;
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
