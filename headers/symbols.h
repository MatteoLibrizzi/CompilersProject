#ifndef __SYMB_
#define __SYMB_
#include "types.h"

#define SUSPICIOUS_TRESHOLD 8000.0
#define SIGNIFICANT_DIGITS 2
char* date;
Customer customerListHead;
Customer currentCustomer;
int numberOfCustomers;
TransactionNode currentTransactionsHead;
char* currentSocialSecurityNumber;

#endif