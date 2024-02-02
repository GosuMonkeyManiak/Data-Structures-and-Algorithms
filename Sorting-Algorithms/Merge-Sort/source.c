#include "mergeSort.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char *firstName;
    char *lastName;
    unsigned int facultyId;
} Student;


int cmp(void *a, void *b)
{
    Student *first = a;
    Student *second = b;

    if (first -> facultyId < second -> facultyId)
    {
        return -1;
    }

    if (first -> facultyId > second -> facultyId)
    {
        return 1;
    }
    
    return 0;
}

void main()
{
    int n;
    printf("number of students = ");
    scanf("%d", &n);

    Student *students = calloc(n, sizeof(Student));

    puts("Enter students:");
    for (int i = 0; i < n; i++)
    {
        char *firstName = calloc(20, sizeof(char));
        char *lastName = calloc(20, sizeof(char));

        printf("First name: ");
        scanf("%20s", firstName);

        printf("Last name: ");
        scanf("%20s", lastName);

        printf("Faculty number: ");
        scanf("%i", &((students + i) -> facultyId));

        (students + i) -> firstName = firstName;
        (students + i) -> lastName = lastName;
    }

    mergeSort(students, sizeof(Student), n, cmp);
    
    puts("Sorted student:");
    for (int i = 0; i < n; i++)
    {
        printf("%d. %s %s %i\n", i + 1, students[i].firstName, students[i].lastName, students[i].facultyId);
    }
    
    for (int i = 0; i < n; i++)
    {
        free((students + i) -> firstName);
        free((students + i) -> lastName);
    }
    
    free(students);
}