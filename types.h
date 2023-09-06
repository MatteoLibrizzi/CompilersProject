#ifndef __TYPES_
#define __TYPES_

typedef struct partialNameNode {
    char *partialName;
    struct partialNameNode* next;
} partialNameNode;
typedef struct partialNameNode* PartialNameNode;

typedef struct transactionNode {
    long amount;
    struct transactionNode * next;
} transactionNode;
typedef struct transactionNode * TransactionNode;

typedef struct customer {
    char* socialSecurityNumber;
    PartialNameNode nameListHead;
    TransactionNode transactionListHead;
    struct customer* next;
} customer;
typedef struct customer* Customer;

#endif