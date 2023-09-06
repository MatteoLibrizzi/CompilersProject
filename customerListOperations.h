#ifndef __CUST_LIST_OPS_
#define __CUST_LIST_OPS_
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "symbols.h"
#include <string.h>
#include "utils.h"

Customer customerConstructor (char* socialSecurityNumber);

void setCurrentCustomer (Customer c);

void addCustomerToList (Customer c);

#endif