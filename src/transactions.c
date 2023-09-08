#include "../headers/transactions.h"


TransactionNode transactionNodeConstructor (double amount) {
    TransactionNode t = (TransactionNode) malloc(sizeof(transactionNode));
    t->next = NULL;
    t->amount = amount;

    return t;
}


void addTransactionToCurrentList (double amount) {
    TransactionNode newNode = transactionNodeConstructor(amount);
    if (currentTransactionsHead == NULL) {
        currentTransactionsHead = newNode;
        return;
    }
    TransactionNode node = currentTransactionsHead;
    while (node->next != NULL) {
        node = node->next;
    }
    node->next = newNode;
}
