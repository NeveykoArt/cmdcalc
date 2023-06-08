#pragma once

#include <cctype>

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
std::size_t getSizeStackNumber(StackNumber *head);
std::size_t getSizeStackOperation(StackOperation *head);
