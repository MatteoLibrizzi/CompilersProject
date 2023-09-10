#ifndef __CUST_LIST_OPS_
#define __CUST_LIST_OPS_
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "symbols.h"
#include <string.h>

void setCurrentCustomerData();
void addCurrentCustomerToList ();
void setCurrentSocialSecurityNumber (char* s);
void addNamesToCustomer(char* names, char* socialSecurityNumber);

#endif