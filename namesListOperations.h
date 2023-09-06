#ifndef __NAMES_LIST_OPS
#define __NAMES_LIST_OPS
#include "types.h"
#include "symbols.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
PartialNameNode partialNameNodeConstructor (char* partialName);

void addPartialNameToCurrentList (char* partialName);

#endif