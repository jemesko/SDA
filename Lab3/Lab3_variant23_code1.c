#include <stdio.h>
#define CAPACITY 50

static char buffer[CAPACITY];
static int first = 0;
static int next = 0;
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

    *value = buffer[first];
    return 1;
}

int dequeue(char *value)
{
    if (peek_front(value) == 0)
        return 0;

    first++;
    if (first == CAPACITY)
        first = 0;
    count--;
    return 1;
}

int enqueue(char value, char *removed)
{
    int full = is_full();
    if (full == 1) {
        *removed = buffer[first];
        first++;
        if (first == CAPACITY)
            first = 0;
    } else {
        count++;
    }

    buffer[next] = value;
    next++;
    if (next == CAPACITY)
        next = 0;
    return full;
}

void print_queue(void)
{
    int index = first;
    printf("Черга: [");
    for (int i = 0; i < count; i++) {
        printf("%c", buffer[index]);
        index++;
        if (index == CAPACITY)
            index = 0;
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