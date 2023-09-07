#include "customerListOperations.h"


Customer customerConstructor (char* socialSecurityNumber, TransactionNode transactionsHead, PartialNameNode namesHead, Customer next) {
    Customer c = (Customer) malloc(sizeof(customer));
    c->socialSecurityNumber = (char*) malloc(sizeof(char) * (strlen(socialSecurityNumber) + 1));
    c->socialSecurityNumber = strcpy(c->socialSecurityNumber, socialSecurityNumber);
    c->nameListHead = namesHead;
    c->transactionListHead = transactionsHead;
    c->next = next;
    return c;
}

void addCurrentCustomerToList () {
    if (customerListHead == NULL) {
        customerListHead = currentCustomer;
        currentCustomer = NULL;
        return;
    }

    Customer node = customerListHead;
    while (node->next != NULL) {
        node = node->next;
    }
    node->next = currentCustomer;
    numberOfCustomers++;
    currentCustomer = NULL;
}


void setCurrentCustomerData () {
    currentCustomer = customerConstructor(currentSocialSecurityNumber, currentTransactionsHead, currentNamesHead, NULL);
    currentTransactionsHead = NULL;
    currentNamesHead = NULL;
}


void setCurrentSocialSecurityNumber (char* s) {
    currentSocialSecurityNumber = (char*) malloc(sizeof(char)*(strlen(s)+1));
    strcpy(currentSocialSecurityNumber, s);
}