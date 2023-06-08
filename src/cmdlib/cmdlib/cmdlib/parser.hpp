#pragma once

#include <string>
#include <cstring>

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
double getDigit(std::string digit, std::size_t &position);
void parser(std::string string_, struct token *table, std::size_t &position, int &table_index);
void checkTable(struct token *table, int table_index);
