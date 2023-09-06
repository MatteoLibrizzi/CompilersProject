#include "transactionListOperations.h"


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
