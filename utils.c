#include "utils.h"

Customer findCustomerBySocialSecurityNumber (Customer node, char* socialSecurityNumber) {
    while (node != NULL && strcmp(node->socialSecurityNumber, socialSecurityNumber)) {
        node = node->next;
    }
    
    return node;
}

void printCustomerList (Customer head) {
    Customer node = head;
    if (node == NULL) {
        return;
    }
    while (node->next != NULL) {
        printf("%s -> ", node->socialSecurityNumber);
        node = node->next;
    }
    printf("%s\n", node->socialSecurityNumber);
}

void printCustomerTransactionList (Customer c) {
    TransactionNode node = c->transactionListHead;
    if (node == NULL) {
        return;
    }
    while (node->next != NULL) {
        printf("%ld -> ", node->amount);
        node = node->next;
    }
    printf("%ld\n", node->amount);
}

void printCustomerListWithTransactions (Customer head) {
    Customer node = head;
    if (node == NULL) {
        return;
    }
    while (node->next != NULL) {
        printf("%s\n    ", node->socialSecurityNumber);
        printCustomerTransactionList(node);
        node = node->next;
    }
    printf("%s\n    ", node->socialSecurityNumber);
    printCustomerTransactionList(node);
}

void printNames (PartialNameNode node) {
    if (node == NULL) {
        return;
    }
    while (node->next != NULL) {
        printf("%s -> ", node->partialName);
        node = node->next;
    }
    printf("%s\n", node->partialName);
}


void printCustomerListWithTransactionsAndNames (Customer head) {
    Customer node = head;
    if (node == NULL) {
        return;
    }
    while (node->next != NULL) {
        printf("%s\n    ", node->socialSecurityNumber);
        printCustomerTransactionList(node);
        printf("    ");
        printNames(node->nameListHead);
        node = node->next;
    }
    printf("%s\n    ", node->socialSecurityNumber);
    printCustomerTransactionList(node);
}