#ifndef __SYM_TABL_
#define __SYM_TABL_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"


char* date;
Customer customerListHead;
Customer currentCustomer;

void init();

void setDate (char* parsedDate);

void addCustomerToList (Customer c);

void setCurrentCustomer (Customer c);

Customer customerConstructor (char* socialSecurityNumber);

void addTransactionToCustomer (Customer customer, long amount);

void addTransactionToTransactionList (TransactionNode head);

#endif