#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 50

struct Node {
    char value;
    struct Node *next;
};

static struct Node *first = NULL;
static struct Node *last = NULL;
static int count = 0;

int is_empty(void)
{
    return count == 0;
}

int is_full(void)
{
    return count == CAPACITY;
}
int peek_front(char *value)
{
    if (is_empty() == 1)
        return 0;

    *value = first->value;
    return 1;
}

int dequeue(char *value)
{
    if (peek_front(value) == 0)
        return 0;

    struct Node *old = first;
    first = first->next;
    free(old);
    count--;
    if (count == 0)
        last = NULL;
    return 1;
}

int enqueue(char value, char *removed)
{
    if (is_full() == 1) {
        struct Node *old = first;
        *removed = old->value;
        first = first->next;
        last->next = old;
        last = old;
        last->next = NULL;
        last->value = value;
        return 1;
    }

    struct Node *node = malloc(sizeof(struct Node));
    if (node == NULL)
        return -1;

    node->value = value;
    node->next = NULL;
    if (first == NULL)
        first = node;
    else
        last->next = node;
    last = node;
    count++;
    return 0;
}

void print_queue(void)
{
    struct Node *node = first;
    printf("Черга: [");
    while (node != NULL) {
        printf("%c", node->value);
        node = node->next;
    }
    printf("]\n");
}

int main(void)
{
    char command;
    char value;
    char removed;
    int exit_code = 0;

    printf("1 A - додати A, 2 - зчитати, 3 - показати, 0 - вихід.\n");
    printf("Місткість буфера: %d символів.\n", CAPACITY);

    while (scanf(" %c", &command) == 1) {
        if (command == '0')
            break;

        if (command == '1') {
            if (scanf(" %c", &value) != 1) {
                printf("Введіть символ для додавання.\n");
                exit_code = 1;
                break;
            }
            if (value < '!' || value > '~') {
                printf("Потрібен друкований символ ASCII без пробілу.\n");
                continue;
            }

            int result = enqueue(value, &removed);
            if (result == -1) {
                printf("Не вдалося виділити пам'ять.\n");
                exit_code = 1;
                break;
            }
            if (result == 1)
                printf("Витіснено: %c\n", removed);
        } else if (command == '2') {
            if (dequeue(&value) == 1)
                printf("Зчитано: %c\n", value);
            else
                printf("Черга порожня.\n");
        } else if (command == '3') {
            print_queue();
        } else {
            printf("Невідома команда.\n");
        }
    }

    printf("Підсумок. ");
    print_queue();

    while (is_empty() == 0)
        dequeue(&value);

    return exit_code;
}