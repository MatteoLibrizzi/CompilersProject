%{
#include <stdio.h>
#include "symbolTable.h"
#include "utils.h"
%}
%union{
    char* string;
    long number;
}

%token<string> DATE SOC_SEC_NUM PART_NAME
%token<number> NAT_NUM TRANSACTION_VALUE

%token FIRST_SEC_END SECOND_SEC_END COLON PLUS MINUS SEMI_COLON COMMA SEPARATOR

%%
s: s1 FIRST_SEC_END s2 SECOND_SEC_END s3 { printf("Parser: Parsing completed successfully.\n"); }
  ;

s1: DATE { setDate($1); }
   ;

s2: transaction s2 { printf("Parser: Found customer section.\n"); }
   | /* eps */ { /* Empty rule for eps */ }
   ;

transaction: SOC_SEC_NUM { printf("Found customer: %s\n", $1); Customer c = customerConstructor($1); setCurrentCustomer(c); addCustomerToList(c);}
    | NAT_NUM COLON TRANSACTION_VALUE SEMI_COLON { printf("Amount: %ld\n", $3); addTransactionToCustomer(currentCustomer, $3); }
    | SEPARATOR {}
    | /* eps */
    ;

customer: SOC_SEC_NUM orders SEPARATOR { printf("Found customer: %s\n", $1); Customer c = customerConstructor($1); setCurrentCustomer(c); addCustomerToList(c);}
        ;

orders: orders order { printf("Parser: Found order.\n"); }
      | /* eps */ { /* Empty rule for eps */ }
      ;

order: NAT_NUM COLON TRANSACTION_VALUE SEMI_COLON { printf("Amount: %ld\n", $3); addTransactionToCustomer(currentCustomer, $3); }
     ;

s3: customer_data s3 { printf("Parser: Found customer data.\n"); }
   | /* eps */ { /* Empty rule for eps */ }
   ;

customer_data: names COMMA SOC_SEC_NUM SEMI_COLON { printf("Parser: Found customer data\n"); }
            ;

names: PART_NAME names { printf("Parser: Found name - %s\n",$1); }
     | /* eps */ { /* Empty rule for eps */ }
     ;

%%

int main() {
    yyparse();

    //printf("Date: %s\n", date);
    //printCustomerListWithTransactions(customerListHead);
    //printf("Curr customer: %s\n", currentCustomer->socialSecurityNumber);
    return 0;
}
int yyerror (char* err) {
    printf("Error %s\n", err);
}