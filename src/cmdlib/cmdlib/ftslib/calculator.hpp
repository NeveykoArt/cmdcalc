#pragma once
#include "parcer.h"
#include "stack.h"
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void AddOperation(StackOperation** list_operation, char operation);
void doOperation(StackOperation **list_operation,
StackNumber **list_number, bool *incorrect_flag);
double Calculator(struct token *table, bool *incorrect_flag, int table_index);
