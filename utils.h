#ifndef __UTILS_
#define __UTILS_
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// returns null if it is not found
Customer findCustomerBySocialSecurityNumber (Customer head, char* socialSecurityNumber);
void printCustomerList (Customer head);
void printCustomerListWithTransactions (Customer head);
void printNames (PartialNameNode node);
void printCustomerListWithTransactionsAndNames (Customer head);
#endif