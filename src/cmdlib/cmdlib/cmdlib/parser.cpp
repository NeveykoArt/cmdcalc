#include <cmdlib/parser.hpp>
#include <stdexcept>

bool checkOperation(char symbol) {
    if (symbol == '\0') {
        return false;
    }
    if (strchr("+-/*()", symbol) != nullptr) {
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

double getDigit(std::string digit, std::size_t &position) {
    char buffer[20];
    int index = 0;

    while (isdigit(digit[position]) || digit[position] == '.') {
        buffer[index] = digit[position];
        ++index;
        ++position;
    }

    buffer[index] = '\0';
    return atof(buffer);
}

void parser(std::string string_, struct token *table, std::size_t &position, int &table_index) {
    while (true) {
        if (string_[position] == ' ') {
            ++position;
            continue;
        }
        if (checkOperation(string_[position])) {
            table[table_index].operation = string_[position];
            ++table_index;
            ++position;
            continue;
        }
        if (isdigit(string_[position])) {
            table[table_index].number = getDigit(string_, position);
            table[table_index].operation = 'n';
            ++table_index;
            continue;
        }
        if (position >= string_.size()) {
            break;
        } else {
            throw std::runtime_error("Wrong input at " + std::to_string(position) + " position.\n");
        }
    }
}

void checkTable(struct token *table, int table_index) {
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
                throw std::runtime_error("Impossible example. Change the input.\n");
            }
        } else {
            number_flag = 0;
            if (table[i].operation == ')' && table[i - 1].operation == '(') {
                throw std::runtime_error("Impossible example. Change the input.\n");
            }
            if (table[i].operation == '(' && table[i - 1].operation == ')') {
                throw std::runtime_error("Impossible example. Change the input.\n");
            }
            if (bracket_flag < 0) {
                throw std::runtime_error("Impossible example. Change the input.\n");
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
                throw std::runtime_error("Impossible example. Change the input.\n");
            }
        }
    }
    if (enough_flag < 3) {
        throw std::runtime_error("Impossible example. Change the input.\n");
    }
    if (bracket_flag != 0) {
        throw std::runtime_error("Impossible example. Change the input.\n");
    }
}
