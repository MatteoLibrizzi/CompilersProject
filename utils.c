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
        printf("NULL\n");
        return;
    }
    while (node->next != NULL) {
        printf("%ld -> ", node->amount);
        node = node->next;
    }
    printf("%ld -> NULL\n", node->amount);
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

void printCustomerListWithTransactionsAndNames (Customer node) {
    while (node != NULL) {
        printf("%s\n    ", node->socialSecurityNumber);
        printCustomerTransactionList(node);
        if (node->names) {
            printf("    %s\n",node->names);
        }
    }
}