#include "utils.h"

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
    printf("%s\n", node->socialSecurityNumber);
}

