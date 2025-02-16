#include<stdio.h>

#define MAX_STUDENTS 100

struct Student {
    char name[50];
    int rollNumber;
    int marks;
};

void addStduent(struct Student students[], int *studentCount, char name[], int rollNumber, int marks) {
    if (*studentCount < MAX_STUDENTS) {
        int i;
        for (i = 0; name[i] != '\0'; i++) {
            students[*studentCount].name[i] = name[i];
        }
        students[*studentCount].name[i] = '\0';

        students[*studentCount].rollNumber = rollNumber;
        students[*studentCount].marks = marks;
        (*studentCount)++;
    
        printf("Student added successfully.\n");
    } else {
        printf("Database full. Cannot add more students.\n");
    }
}

void displayAllStudents(struct Student students[], int studentCount) {
    printf("Student Records:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("Name: %s, Roll Number: %d, Marks: %d\n", students[i].name, students[i].rollNumber,students[i].marks);
    }
}

void searchStudent(struct Student students[], int studentCount, int rollNumber) {
    for (int i = 0; i < studentCount; i++) {
        if(students[i].rollNumber == rollNumber) {
            printf("Student Found:\n");
            printf("Name: %s, Roll Number: %d, Marks: %d\n", students[i].name, students[i].rollNumber,students[i].marks);
            return;
        }
    }
    printf("Student not found.\n");
}

int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;

    addStduent(students, &studentCount, "John", 101, 85);
    addStduent(students, &studentCount, "Alice", 102, 90);
    displayAllStudents(students, studentCount);
    searchStudent(students, studentCount, 102);

    return 0;
}