#include "symbolTable.h"

void init() {
    date = NULL;
    customerListHead = NULL;
    currentCustomer = NULL;
    currentNamesHead = NULL;
    numberOfCustomers = 0;
}

void setDate (char* parsedDate){
    int length = strlen(parsedDate);
    date = (char*) malloc(sizeof(char) * length);
    date = strcpy(date, parsedDate);
}
