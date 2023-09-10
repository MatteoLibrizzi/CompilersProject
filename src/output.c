#include "../headers/output.h"

double getPositiveTransactionsAmount(TransactionNode node)
{
    double amount = 0;
    while (node != NULL)
    {
        if (node->amount > 0)
        {
            amount += node->amount;
        }
        node = node->next;
    }
    return amount;
}

double getNegativeTransactionsAmount(TransactionNode node)
{
    double amount = 0;
    while (node != NULL)
    {
        if (node->amount < 0)
        {
            amount += node->amount;
        }
        node = node->next;
    }
    return amount;
}

int isAmountSuspicious(double val)
{
    return fabs(val) > SUSPICIOUS_TRESHOLD;
}

int isCustomerSuspicious(Customer c)
{
    double positiveTransactionsTotal = getPositiveTransactionsAmount(c->transactionListHead);
    double negativeTransactionsTotal = getNegativeTransactionsAmount(c->transactionListHead);

    return isAmountSuspicious(positiveTransactionsTotal) || isAmountSuspicious(negativeTransactionsTotal);
}

int isCustomersNameKnown(Customer c)
{
    return c->names != NULL;
}

int numberOfSuspiciousCustomersWithNames = 0;
Customer *getSuspiciousCustomersWithNames(Customer node)
{
    Customer *suspisiousCustomers = (Customer *)calloc(numberOfCustomers, sizeof(Customer));
    for (; node != NULL; node = node->next)
    {
        if (isCustomersNameKnown(node) && isCustomerSuspicious(node))
        {
            suspisiousCustomers[numberOfSuspiciousCustomersWithNames] = node;
            numberOfSuspiciousCustomersWithNames++;
        }
    }
    return numberOfSuspiciousCustomersWithNames == 0 ? NULL : suspisiousCustomers;
}

long countCustomersWithoutNames(Customer node)
{
    int count = 0;

    while (node != NULL)
    {
        if (!isCustomersNameKnown(node))
        {
            count++;
        }
        node = node->next;
    }
    return count;
}

void printSuspiciousCustomer(Customer c, double amt)
{
    if (c->names != NULL)
    {
        printf("%s, ", c->names);
    }

    printf("%s, ", c->socialSecurityNumber);
    if (amt > 0)
    {
        printf("+ %.*lf", SIGNIFICANT_DIGITS, amt);
    }
    else
    {
        printf("- %.*lf", SIGNIFICANT_DIGITS, fabs(amt));
    }
    printf("\n");
}

void printSuspiciousCustomers(Customer *suspisiousCustomers)
{
    int i = 0;
    Customer c = suspisiousCustomers[i];

    while (c != NULL)
    {
        double positiveTransactionsTotal = getPositiveTransactionsAmount(c->transactionListHead);
        double negativeTransactionsTotal = getNegativeTransactionsAmount(c->transactionListHead);

        if (isAmountSuspicious(positiveTransactionsTotal)) {
            printSuspiciousCustomer(c, positiveTransactionsTotal);
        }
        if (isAmountSuspicious(negativeTransactionsTotal)) {
            printSuspiciousCustomer(c, negativeTransactionsTotal);
        }
        i++;
        c = suspisiousCustomers[i];
    }
}

// insertion sort
void sortCustomersByName(Customer *customers, int n)
{
    int i, j;
    char *key;
    for (i = 1; i < n; i++)
    {
        Customer backup = customers[i];
        key = customers[i]->names;
        j = i - 1;

        while (j >= 0 && strcmp(customers[j]->names, key) > 0)
        {
            customers[j + 1] = customers[j];
            j = j - 1;
        }
        customers[j + 1] = backup;
    }
}

void output()
{
    printf("%s\n", date);
    Customer *suspisiousCustomers = getSuspiciousCustomersWithNames(customerListHead);

    sortCustomersByName(suspisiousCustomers, numberOfSuspiciousCustomersWithNames);

    if (suspisiousCustomers == NULL)
    {
        printf("Nessun movimento sospetto\n");
    }
    else
    {
        printf("Si segnala:\n");
        printSuspiciousCustomers(suspisiousCustomers);
    }

    long customersWithoutNames = countCustomersWithoutNames(customerListHead);
    if (customersWithoutNames)
    {
        printf("Numero di clienti con dati non definiti: %ld\n", customersWithoutNames);
    }
}