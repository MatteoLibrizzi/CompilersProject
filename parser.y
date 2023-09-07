%{
#include <stdio.h>
#include "symbolTable.h"
#include "utils.h"
#include "output.h"
#include "transactionListOperations.h"
#include "namesListOperations.h"
#include "customerListOperations.h"

int yylex();
int yyerror(char* s);
%}
%union{
    char* string;
    long number;
}

%token<string> DATE SOC_SEC_NUM PART_NAME
%token<number> DAY_OF_MONTH TRANSACTION_VALUE

%token FIRST_SEC_END SECOND_SEC_END COLON SEMI_COLON COMMA SEPARATOR ERROR

%%
s: s1 FIRST_SEC_END s2 SECOND_SEC_END s3 {
    #ifdef DEBUG
        printf("Parser: Parsing completed successfully.\n");
    #endif
    }
  ;

s1: DATE { setDate($1); }
   ;

s2: customer s2 { }
   | /* eps */ { }
   ;

customer: SOC_SEC_NUM orders SEPARATOR { setCurrentSocialSecurityNumber($1); setCurrentCustomerData(); addCurrentCustomerToList();}
    ;

orders: DAY_OF_MONTH COLON TRANSACTION_VALUE SEMI_COLON orders { addTransactionToCurrentList($3); }
    | /* eps */ {}
    ;

s3: customer_data s3 { }
   | /* eps */ { }
   ;

customer_data: names COMMA SOC_SEC_NUM SEMI_COLON { addCurrentNameListToCustomer($3); }
            ;

names: names PART_NAME { addPartialNameToCurrentList($2);}
     | /* eps */ { }
     ;

%%

int main() {
    if (!yyparse()) {

        output();
        return 0;
    } else {
        printf("Errore sintattico\n");
        return 1;
    }
}
int yyerror (char* err) {
}