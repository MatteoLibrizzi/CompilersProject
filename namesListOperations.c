#include "namesListOperations.h"

void addNamesToCustomer(char* socialSecurityNumber, char* names) {
    Customer c = findCustomerBySocialSecurityNumber(customerListHead, socialSecurityNumber);
    if (c == NULL) {
        return;
    }
    c->names = (char*) malloc(sizeof(char)* (strlen(names)+1));
    c->names = strcpy(c->names, names);
}