#include <cmdlib/calculator.hpp>
#include <cmdlib/stack.hpp>

void AddOperation(StackOperation **list_operation, char operation) {
    if (operation == ')' && peekOperation(*list_operation) == '(') {
        deleteOperation(&(*list_operation));
    } else {
        pushOperation(&(*list_operation), operation);
    }
}

void doOperation(StackOperation **list_operation, StackNumber **list_number, bool &incorrect_flag) {
    char operation = popOperation(&(*list_operation));
    double x = popNumber(&(*list_number));
    double y = popNumber(&(*list_number));

    switch (operation) {
        case '+': {
            pushNumber(&(*list_number), y + x);
            break;
        }
        case '-': {
            pushNumber(&(*list_number), y - x);
            break;
        }
        case '/': {
            if (x == 0) {
                incorrect_flag = true;
                pushNumber(&(*list_number), 0);
                break;
            }
            pushNumber(&(*list_number), y / x);
            break;
        }
        case '*': {
            pushNumber(&(*list_number), y * x);
            break;
        }
        case '(': {
            pushNumber(&(*list_number), y);
            pushNumber(&(*list_number), x);
            break;
        }
        case ')': {
            pushNumber(&(*list_number), y);
            pushNumber(&(*list_number), x);
            break;
        }
    }
}

double Calculator(struct token *table, bool &incorrect_flag, int table_index) {
    StackNumber *list_number = nullptr;
    StackOperation *list_operation = nullptr;
    int position = 0;
    double answer = 0;

    while (true) {
        if (position == table_index) {
            break;
        }
        if (table[position].operation == 'n') {
            pushNumber(&list_number, table[position].number);
            ++position;
            continue;
        }
        if (getSizeStackOperation(list_operation) == 0) {
            if ((table[position].operation == '-')
            && (getSizeStackNumber(list_number) == 0)) {
                pushNumber(&list_number, 0);
                AddOperation(&list_operation, table[position].operation);
                ++position;
                pushNumber(&list_number, table[position].number);
                doOperation(&list_operation, &list_number, incorrect_flag);
                ++position;
                continue;
            }
            AddOperation(&list_operation, table[position].operation);
            ++position;
            continue;
        }
        if ((table[position].operation == '-')
        && (table[position - 1].operation == '(')) {
            pushNumber(&list_number, 0);
            AddOperation(&list_operation, table[position].operation);
            ++position;
            pushNumber(&list_number, table[position].number);
            doOperation(&list_operation, &list_number, incorrect_flag);
            ++position;
            continue;
        }
        if (table[position].operation == '(') {
            AddOperation(&list_operation, table[position].operation);
            ++position;
            continue;
        }
        while (true) {
            if (getSizeStackOperation(list_operation) == 1) {
                break;
            }
            if (setOperation(peekOperation(list_operation)) == 1) {
                break;
            }
            if (setOperation(peekOperation(list_operation))
            >= setOperation(table[position].operation)) {
                if (incorrect_flag == true) {
                    break;
                }
                doOperation(&list_operation, &list_number, incorrect_flag);
            } else {
                break;
            }
        }
        AddOperation(&list_operation, table[position].operation);
        ++position;
    }
    if (getSizeStackOperation(list_operation) != 0
    && getSizeStackNumber(list_number) != 1) {
        while (getSizeStackOperation(list_operation) != 0){
            if (getSizeStackNumber(list_number) >= 2) {
                if (incorrect_flag == true) {
                    break;
                }
                doOperation(&list_operation, &list_number, incorrect_flag);
            }
        }
    }
    if ((getSizeStackOperation(list_operation) != 0
    && getSizeStackNumber(list_number) != 1)
    && (incorrect_flag)) {
        incorrect_flag = true;
    }
    if (list_number != nullptr) {
        answer = list_number->number;
    }
    return answer;
}
