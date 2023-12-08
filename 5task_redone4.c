#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 2

// ТЕПЕРЬ С ФУНКЦИЯМИ
// Задание на структуры
// Написать программу абонентский справочник. Список абонентов
// представляет собой статический массив (100 элементов) из структур
// следующего в вида:
// struct abonent {
// char name[10];
// char second_name[10];
// char tel[10];
// };
// При запуске на экран выводится текстовое меню:
// 1) Добавить абонента
// 2) Удалить абонента
// 3) Поиск абонентов по имени
// 4) Вывод всех записей
// 5) Выход
// и пользователю предлагается ввести пункт меня с клавиатуры. Добавление
// абонента в массив реализуется простым заполнением свободной структуры,
// при выходе за 100 абонентов уведомить пользователя о переполнении
// справочника и не позволять больше добавлять абонентов. При удалении
// структура заполняется нулями. При поиске пользователь вводит с клавиатуры
// имя абонентов и на экран выводится список всех абонентов с таким же именем.
// Программа продолжает выполняться пока пользователь не введет пункт 5.

struct Subscriber
{
    char name[30];
    char second_name[30];
    char tel[11];
};

struct Subscriber subscriberBook[MAX_SUBSCRIBERS];

void initSubscriberBook()
{
    for (int i = 0; i < MAX_SUBSCRIBERS; i++)
    {
        strcpy(subscriberBook[i].name, "");
        strcpy(subscriberBook[i].second_name, "");
        strcpy(subscriberBook[i].tel, "");
    }
}

void drawMenu();

void addSubscriber()
{
    for (int i = 0; i < MAX_SUBSCRIBERS; i++)
    {
        if (strcmp(subscriberBook[i].name, "") == 0)
        {
            printf("\nВведите имя, фамилию и номер телефона абонента (через пробел):");
            scanf("%s %s %s", subscriberBook[i].name, subscriberBook[i].second_name, subscriberBook[i].tel);
            drawMenu();
            return;
        }
    }
    printf("\nПревышен лимит (%d) абонентов\n", MAX_SUBSCRIBERS);
    drawMenu();
}

void deleteSubscriber()
{
    int id;
    printf("\nВведите ID абонента, которого нужно удалить: ");
    scanf("%d", &id);

    if (id < 0 || id >= MAX_SUBSCRIBERS)
    {
        printf("\nПревышен лимит (%d) абонентов\n", MAX_SUBSCRIBERS);
    }
    else if (strcmp(subscriberBook[id].name, "") == 0)
    {
        printf("\nАбонент с ID %d не существует\n", id);
    }
    else
    {
        strcpy(subscriberBook[id].name, "");
        strcpy(subscriberBook[id].second_name, "");
        strcpy(subscriberBook[id].tel, "");
    }
    drawMenu();
}

void findSubscriber()
{
    char searchName[30];
    printf("\nВведите имя абонента для поиска: ");
    scanf("%s", searchName);

    for (int i = 0; i < MAX_SUBSCRIBERS; i++)
    {
        if (strcmp(subscriberBook[i].name, searchName) == 0)
        {
            printf("%s %s, %s\n", subscriberBook[i].name, subscriberBook[i].second_name, subscriberBook[i].tel);
        }
    }
    drawMenu();
}

void printAllSubscribers()
{
    printf("\nСписок абонентов::\n");
    for (int i = 0; i < MAX_SUBSCRIBERS; i++)
    {
        if (strcmp(subscriberBook[i].name, "") != 0)
        {
            printf("%s %s, %s\n", subscriberBook[i].name, subscriberBook[i].second_name, subscriberBook[i].tel);
        }
    }
    drawMenu();
}

void drawMenu()
{
    int taskNumber;
    printf("\nПожалуйста, выберите действие от 1 до 5\n\n");
    printf("1. Добавить нового абонента\n");
    printf("2. Удалить абонента\n");
    printf("3. Найти абонента по имени\n");
    printf("4. Показать всех абонентов\n");
    printf("5. Выйти\n");
    scanf("%d", &taskNumber);

    switch (taskNumber)
    {
    case 1:
        addSubscriber();
        break;
    case 2:
        deleteSubscriber();
        break;
    case 3:
        findSubscriber();
        break;
    case 4:
        printAllSubscribers();
        break;
    case 5:
        exit(0);
    default:
        printf("\nЗадача с номером %d не существует\n", taskNumber);
    }
}

int main()
{
    initSubscriberBook();
    drawMenu();
    return 0;
}