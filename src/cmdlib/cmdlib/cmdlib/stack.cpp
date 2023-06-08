#include <cmdlib/stack.hpp>

bool pushOperation(StackOperation** head, char operation) {
    auto* tmp = new StackOperation;
    tmp->next = *head;
    tmp->operation = operation;
    *head = tmp;
    return true;
}

bool pushNumber(StackNumber** head, double number) {
    auto* tmp = new StackNumber;
    tmp->next = *head;
    tmp->number = number;
    *head = tmp;
    return true;
}

double popNumber(StackNumber** head) {
    StackNumber* out = nullptr;
    double value = 0.0;
    out = *head;
    *head = (*head)->next;
    value = out->number;
    return value;
}

char popOperation(StackOperation** head) {
    StackOperation* out = nullptr;
    char operation;
    out = *head;
    *head = (*head)->next;
    operation = out->operation;
    return operation;
}

void deleteOperation(StackOperation** head) {
    *head = (*head)->next;
}

double peekNumber(StackNumber* head) {
    return head->number;
}

char peekOperation(StackOperation* head) {
    return head->operation;
}

std::size_t getSizeStackNumber(StackNumber* head) {
    std::size_t size = 0;
    while (head != nullptr) {
        size++;
        head = head->next;
    }
    return size;
}

std::size_t getSizeStackOperation(StackOperation* head) {
    std::size_t size = 0;
    while (head != nullptr) {
        size++;
        head = head->next;
    }
    return size;
}
