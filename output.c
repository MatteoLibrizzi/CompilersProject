#include "output.h"

int isCustomerSuspicious(Customer c) {
    return 0;
}

Customer* getSuspiciousCustomersWithNames(Customer node) {
    Customer* suspisiousCustomers = (Customer*) calloc(numberOfCustomers, sizeof(Customer));
    for (int i = 0; node != NULL; node = node->next) {
        if (isCustomerSuspicious(node)) {
            suspisiousCustomers[i] = node;
        }
    }

    return suspisiousCustomers;
}

long countCustomersWithoutNames (Customer node) {
    int count = 0;

    while (node != NULL) {
        if (node->nameListHead != NULL) {
            count++;
        }
        node = node->next;
    }
    return count;
}

void output() {
    printf("%s\n", date);
    Customer* suspisiousCustomers = getSuspiciousCustomersWithNames(customerListHead);
    long customersWithoutNames = countCustomersWithoutNames(customerListHead);

    printCustomerListWithTransactionsAndNames(customerListHead);

    if (suspisiousCustomers[0] == NULL) {
        printf("Nessun movimento sospetto\n");
    } else {
        printf("Si segnala:\n");
    }

    printf("Numero di clienti con dati non definiti: %ld\n", customersWithoutNames);
}