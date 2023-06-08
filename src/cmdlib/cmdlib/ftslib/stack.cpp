#include "stack.h"
bool pushOperation(StackOperation** head, char operation)
{
StackOperation* tmp = malloc(sizeof(StackOperation));
if (tmp == NULL) {
return false;
}
tmp->next = *head;
tmp->operation = operation;
*head = tmp;
return true;
}
bool pushNumber(StackNumber** head, double number)
{
StackNumber* tmp = malloc(sizeof(StackNumber));
if (tmp == NULL) {
return false;
}
tmp->next = *head;
tmp->number = number;
*head = tmp;
return true;
}
double popNumber(StackNumber** head)
{
StackNumber* out;
double value;
out = *head;
*head = (*head)->next;
value = out->number;
free(out);
return value;
}
char popOperation(StackOperation** head)
{
StackOperation* out;
char operation;
out = *head;
*head = (*head)->next;
operation = out->operation;
free(out);
return operation;
}
void deleteOperation(StackOperation** head)
{
StackOperation* out;
out = *head;
*head = (*head)->next;
free(out);
}
double peekNumber(StackNumber* head)
{
return head->number;
}
char peekOperation(StackOperation* head)
{
return head->operation;
}
size_t getSizeStackNumber(StackNumber* head)
{
size_t size = 0;
while (head) {
size++;
head = head->next;
}
return size;
}
size_t getSizeStackOperation(StackOperation* head)
{
size_t size = 0;
while (head) {
size++;
head = head->next;
}
return size;
}
