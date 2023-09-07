#include "setDate.h"

void setDate (char* parsedDate){
    int length = strlen(parsedDate);
    date = (char*) malloc(sizeof(char) * length);
    date = strcpy(date, parsedDate);
}
