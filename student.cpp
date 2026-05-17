#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

double calculateAverage(int korean, int english, int math, int science) {
    return (korean + english + math + science) / 4.0;
}

double calculateGrade(double average) {
    if (average >= 95) return 1.0;
    else if (average >= 90) return 1.5;
    else if (average >= 85) return 2.0;
    else if (average >= 80) return 2.5;
    else if (average >= 75) return 3.0;
    else if (average >= 70) return 3.5;
    else if (average >= 65) return 4.0;
    else if (average >= 60) return 4.5;
    else return 5.0;
}

Student* createStudent(int id, char name[], int korean, int english, int math, int science) {
    Student* newStudent = (Student*)malloc(sizeof(Student));

    if (newStudent == NULL) {
        printf("메모리 할당 실패\n");
        exit(1);
    }

    newStudent->id = id;
    strcpy(newStudent->name, name);

    newStudent->korean = korean;
    newStudent->english = english;
    newStudent->math = math;
    newStudent->science = science;

    newStudent->average = calculateAverage(korean, english, math, science);
    newStudent->grade = calculateGrade(newStudent->average);

    newStudent->left = NULL;
    newStudent->right = NULL;

    return newStudent;
}

Student* insertStudent(Student* root, Student* newStudent) {
    if (root == NULL) {
        return newStudent;
    }

    if (newStudent->id < root->id) {
        root->left = insertStudent(root->left, newStudent);
    }
    else if (newStudent->id > root->id) {
        root->right = insertStudent(root->right, newStudent);
    }
    else {
        printf("이미 존재하는 학번입니다.\n");
        free(newStudent);
    }

    return root;
}

Student* searchStudent(Student* root, int id) {
    if (root == NULL) {
        return NULL;
    }

    if (id == root->id) {
        return root;
    }
    else if (id < root->id) {
        return searchStudent(root->left, id);
    }
    else {
        return searchStudent(root->right, id);
    }
}

Student* findMin(Student* root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }

    return root;
}

Student* deleteStudent(Student* root, int id) {
    if (root == NULL) {
        printf("삭제할 학생을 찾을 수 없습니다.\n");
        return NULL;
    }

    if (id < root->id) {
        root->left = deleteStudent(root->left, id);
    }
    else if (id > root->id) {
        root->right = deleteStudent(root->right, id);
    }
    else {
        Student* temp;

        if (root->left == NULL) {
            temp = root->right;
            free(root);
            printf("학생 정보가 삭제되었습니다.\n");
            return temp;
        }
        else if (root->right == NULL) {
            temp = root->left;
            free(root);
            printf("학생 정보가 삭제되었습니다.\n");
            return temp;
        }

        temp = findMin(root->right);

        root->id = temp->id;
        strcpy(root->name, temp->name);

        root->korean = temp->korean;
        root->english = temp->english;
        root->math = temp->math;
        root->science = temp->science;

        root->average = temp->average;
        root->grade = temp->grade;

        root->right = deleteStudent(root->right, temp->id);
    }

    return root;
}

// 학생 정보 수정 기능
void updateStudentInfo(Student* root, int id) {
    Student* student = searchStudent(root, id);

    if (student == NULL) {
        printf("수정할 학생을 찾을 수 없습니다.\n");
        return;
    }

    printf("\n[현재 학생 정보]\n");
    printStudent(student);

    printf("\n수정할 정보를 입력하세요.\n");
    printf("※ 학번은 트리의 기준값이므로 수정하지 않습니다.\n");

    printf("새 이름 입력: ");
    scanf("%s", student->name);

    printf("새 국어 점수 입력: ");
    scanf("%d", &student->korean);

    printf("새 영어 점수 입력: ");
    scanf("%d", &student->english);

    printf("새 수학 점수 입력: ");
    scanf("%d", &student->math);

    printf("새 과학 점수 입력: ");
    scanf("%d", &student->science);

    student->average = calculateAverage(
        student->korean,
        student->english,
        student->math,
        student->science
    );

    student->grade = calculateGrade(student->average);

    printf("\n학생 정보가 수정되었습니다.\n");

    printf("\n[수정된 학생 정보]\n");
    printStudent(student);
}

void printStudent(Student* student) {
    if (student == NULL) {
        return;
    }

    printf("학번: %d\n", student->id);
    printf("이름: %s\n", student->name);
    printf("국어: %d\n", student->korean);
    printf("영어: %d\n", student->english);
    printf("수학: %d\n", student->math);
    printf("과학: %d\n", student->science);
    printf("평균: %.2lf\n", student->average);
    printf("내신 등급: %.1lf\n", student->grade);
}

void freeTree(Student* root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}