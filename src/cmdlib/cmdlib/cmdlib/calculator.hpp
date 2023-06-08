#pragma once
#include <cmdlib/parser.hpp>
#include <cmdlib/stack.hpp>
#include <string>
#include <cstring>

void AddOperation(StackOperation** list_operation, char operation);
void doOperation(StackOperation **list_operation,
StackNumber **list_number, bool &incorrect_flag);
double Calculator(struct token *table, bool &incorrect_flag, int table_index);
