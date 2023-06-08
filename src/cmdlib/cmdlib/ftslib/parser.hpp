#pragma once
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct token {
char operation;
double number;
};
enum operation {
Opening = '(',
Closing = ')',
Addition = '+',
Subraction = '-',
Division = '/',
Multiplication = '*',
Number = 'n'
};
bool checkOperation(char symbol);
int setOperation(char symbol);
double getDigit(char *digit, size_t *position);
bool parcer(char *string, struct token *table, size_t *position, int* table_index);
bool checkTable(struct token *table, int table_index);
