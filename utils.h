#ifndef __UTILS_
#define __UTILS_
#include "types.h"
#include <stdio.h>
#include <stdlib.h>

Customer findCustomerBySocialSecurityNumber (char* socialSecurityNumber);
void printCustomerList (Customer head);
void printCustomerListWithTransactions (Customer head);
#endif