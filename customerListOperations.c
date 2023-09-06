#include "customerListOperations.h"

void addCurrentNameListToCustomer (char* socialSecurityNumber) {
    Customer c = findCustomerBySocialSecurityNumber(customerListHead, socialSecurityNumber);
    if (c == NULL) {
        return;
    }
    c->nameListHead = currentNamesHead;
    currentNamesHead = NULL;
}

Customer customerConstructor (char* socialSecurityNumber) {
    Customer c = (Customer) malloc(sizeof(customer));
    int length = strlen(socialSecurityNumber);
    c->socialSecurityNumber = (char*) malloc(sizeof(char) * length);
    c->socialSecurityNumber = strcpy(c->socialSecurityNumber, socialSecurityNumber);
    c->nameListHead = NULL;
    c->transactionListHead = NULL;
    c->next = NULL;
    return c;
}

void setCurrentCustomer (Customer c) {
    currentCustomer = c;
}

void addCustomerToList (Customer c) {
    if (customerListHead == NULL) {
        customerListHead = c;
        return;
    }

    Customer node = customerListHead;
    while (node->next != NULL) {
        node = node->next;
    }
    node->next = c;
    numberOfCustomers++;
}