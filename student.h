#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student {
    int id;
    char name[30];

    int korean;
    int english;
    int math;
    int science;

    double average;
    double grade;

    struct Student* left;
    struct Student* right;
} Student;

double calculateAverage(int korean, int english, int math, int science);
double calculateGrade(double average);

Student* createStudent(int id, char name[], int korean, int english, int math, int science);
Student* insertStudent(Student* root, Student* newStudent);
Student* searchStudent(Student* root, int id);
Student* deleteStudent(Student* root, int id);

void updateStudentInfo(Student* root, int id);

void printStudent(Student* student);
void freeTree(Student* root);

#endif