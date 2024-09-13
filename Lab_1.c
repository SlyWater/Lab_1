#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#define MAX_STUDENTS 10


typedef struct {
    char lastName[20];
    char firstName[20];
    int age;
    char group[10];
} student;

void print_students(student *found, int n) {
    system("cls");
    printf("Студентов найдено: %d\n", n);
    for (int i = 0; i < n; ++i) {
        printf("Фамилия: %s\n", found[i].lastName);
        printf("Имя: %s\n", found[i].firstName);
        printf("Возраст: %d\n", found[i].age);
        printf("Группа: %s\n", found[i].group);
    }
}

int main() {
    setlocale(LC_ALL, "Rus");

    student* found_students = (student*)malloc(sizeof(student) * MAX_STUDENTS);
    student students[MAX_STUDENTS] = {
        {"Ivanov", "Ivan", 20, "23VVV1"},
        {"Ivanov", "Ivan", 24, "23VVV4"},
        {"Petrov", "Petr", 22, "23VVV3"},
        {"Sidorov", "Sergey", 21, "23VVV1"},
        {"Kuznetsov", "Andrey", 23, "23VVV2"},
        {"Smirnov", "Alexey", 20, "23VVV3"},
    };

    int n = sizeof(students) / sizeof(student);

    char targetLastName[20];
    char targetFirstName[20];

    printf("Введите фамилию: ");
    scanf("%s", targetLastName);

    printf("Введите имя: ");
    scanf("%s", targetFirstName);


    int found = 0;
    for (int i = 0; i < n; ++i) {
        if (strcmp(students[i].lastName, targetLastName) == 0 &&
            strcmp(students[i].firstName, targetFirstName) == 0) {
            *(found_students + found) = students[i];
            found += 1;
        }
    }
    print_students(found_students, found);
    

    return 0;
}
