#ifndef __TYPES_
#define __TYPES_

typedef struct transactionNode {
    long amount;
    struct transactionNode * next;
} transactionNode;
typedef struct transactionNode * TransactionNode;

typedef struct customer {
    char* socialSecurityNumber;
    TransactionNode transactionListHead;
    char* names;
    struct customer* next;
} customer;
typedef struct customer* Customer;

#endif