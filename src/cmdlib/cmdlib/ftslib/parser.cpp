#include "parcer.h"
bool checkOperation(char symbol) {
if (symbol == '\0') {
return false;
}
if (strchr("+-/*()", symbol) != NULL) {
return true;
}
return false;
}
int setOperation(char symbol) {
switch (symbol) {
case Opening: {
return 1;
}
case Addition: {
return 3;
}
case Subraction: {
return 2;
}
case Division: {
return 4;
}
case Multiplication: {
return 5;
}
case Closing: {
return 1;
}
case Number: {
return 6;
}
}
return 0;
}
double getDigit(char *digit, size_t *position) {
char buffer[20];
int index = 0;
while (isdigit(digit[*position]) || digit[*position] == '.') {
buffer[index] = digit[*position];
++index;
++(*position);
}
buffer[index] = '\0';
return atof(buffer);
}
bool parcer(char *string, struct token *table, size_t *position, int* table_index) {
while (true) {
if (string[*position] == ' ') {
++(*position);
continue;
}
if (checkOperation(string[*position])) {
table[*table_index].operation = string[*position];
++(*table_index);
++(*position);
continue;
}
if (isdigit(string[*position])) {
table[*table_index].number = getDigit(string, &(*position));
table[*table_index].operation = 'n';
++(*table_index);
continue;
}
if (*position >= strlen(string)) {
break;
} else {
free(table);
return false;
}
}
return true;
}
bool checkTable(struct token *table, int table_index) {
int number_flag = 0;
int operation_flag = 0;
int bracket_flag = 0;
int enough_flag = 0;
for (int i = 0; i < table_index; i++) {
if (table[i].operation == 'n') {
++enough_flag;
operation_flag = 0;
++number_flag;
if (number_flag == 2) {
return false;
}
} else {
number_flag = 0;
if (table[i].operation == ')' && table[i - 1].operation == '(') {
return false;
}
if (table[i].operation == '(' && table[i - 1].operation == ')') {
return false;
}
if (bracket_flag < 0) {
return false;
}
if (table[i].operation == '(') {
++bracket_flag;
continue;
}
if (table[i].operation == ')') {
--bracket_flag;
continue;
}
if (table[i].operation == '-' && table[i - 1].operation == '(') {
continue;
}
++operation_flag;
++enough_flag;
if (operation_flag == 2) {
return false;
}
}
}
if (enough_flag < 3) {
return false;
}
if (bracket_flag != 0) {
return false;
}
return true;
}
