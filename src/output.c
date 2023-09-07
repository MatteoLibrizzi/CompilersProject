#include "../headers/output.h"

long getPositiveTransactionsAmount (TransactionNode node) {
    long amount = 0;
    while (node != NULL) {
        if (node->amount > 0) {
            amount += node->amount;
        }
        node = node->next;
    }
    return amount;
}

long getNegativeTransactionsAmount (TransactionNode node) {
    long amount = 0;
    while (node != NULL) {
        if (node->amount < 0) {
            amount += node->amount;
        }
        node = node->next;
    }
    return amount;
}

int isCustomerSuspicious(Customer c) {
    long positiveTransactionsTotal = getPositiveTransactionsAmount(c->transactionListHead);
    long negativeTransactionsTotal = getNegativeTransactionsAmount(c->transactionListHead);

    return positiveTransactionsTotal > SUSPICIOUS_TRESHOLD || negativeTransactionsTotal < -SUSPICIOUS_TRESHOLD;
}

int isCustomersNameKnown (Customer c) {
    return c->names != NULL;
}

Customer* getSuspiciousCustomersWithNames(Customer node) {
    Customer* suspisiousCustomers = (Customer*) calloc(numberOfCustomers, sizeof(Customer));
    int i = 0;
    for (; node != NULL; node = node->next) {
        if (isCustomersNameKnown(node) && isCustomerSuspicious(node)) {
            suspisiousCustomers[i] = node;
            i++;
        }
    }
    return i == 0 ? NULL : suspisiousCustomers;
}

long countCustomersWithoutNames (Customer node) {
    int count = 0;

    while (node != NULL) {
        if (!isCustomersNameKnown(node)) {
            count++;
        }
        node = node->next;
    }
    return count;
}

void printSuspiciousCustomers (Customer* suspisiousCustomers) {
    int i = 0;
    Customer c = suspisiousCustomers[i];

    while (c != NULL) {
        if (c->names != NULL) {
            printf("%s, ",c->names);
        }

        printf("%s, ",c->socialSecurityNumber);


        long positiveTransactionsTotal = getPositiveTransactionsAmount(c->transactionListHead);
        long negativeTransactionsTotal = getNegativeTransactionsAmount(c->transactionListHead);

        if (abs(positiveTransactionsTotal) > abs(negativeTransactionsTotal)) {
            printf("+ %ld", positiveTransactionsTotal);
        } else {
            printf("- %d",abs(negativeTransactionsTotal));
        }

        printf("\n");
        i++;
        c = suspisiousCustomers[i];
    }
}

void output() {
    printf("%s\n", date);
    Customer* suspisiousCustomers = getSuspiciousCustomersWithNames(customerListHead);

    if (suspisiousCustomers == NULL) {
        printf("Nessun movimento sospetto\n");
    } else {
        printf("Si segnala:\n");
        printSuspiciousCustomers(suspisiousCustomers);
    }

    long customersWithoutNames = countCustomersWithoutNames(customerListHead);
    if (customersWithoutNames) {
        printf("Numero di clienti con dati non definiti: %ld\n", customersWithoutNames);
    }
}