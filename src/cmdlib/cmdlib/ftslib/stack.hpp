#pragma once
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node_i {
char operation;
struct Node_i *next;
} StackOperation;
typedef struct Node_n {
double number;
struct Node_n *next;
} StackNumber;
bool pushOperation(StackOperation **head, char operation);
bool pushNumber(StackNumber **head, double number);
double popNumber(StackNumber **head);
char popOperation(StackOperation **head);
void deleteOperation(StackOperation **head);
double peekNumber(StackNumber *head);
char peekOperation(StackOperation *head);
size_t getSizeStackNumber(StackNumber *head);
size_t getSizeStackOperation(StackOperation *head);
