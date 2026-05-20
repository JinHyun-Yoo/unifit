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
        printf("학생 정보가 입력되었습니다.\n");
        return newStudent;
    }

    if (newStudent->id < root->id) {
        root->left = insertStudent(root->left, newStudent);
    }
    else if (newStudent->id > root->id) {
        root->right = insertStudent(root->right, newStudent);
    }
    else {
        printf("이미 존재하는 학번입니다. 입력이 취소되었습니다.\n");
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

static Student* findMin(Student* root) {
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

/*
    학생 정보 입력 함수
    함수명: is_login()
    설명: 학번, 이름, 점수를 입력받아 새로운 학생 노드를 만든다.
*/
Student* is_login(void) {
    int id, korean, english, math, science;
    char name[30];

    printf("\n========== 학생 정보 입력 ==========" "\n");

    printf("학번 입력: ");
    scanf("%d", &id);

    printf("이름 입력: ");
    scanf("%s", name);

    printf("국어 점수 입력: ");
    scanf("%d", &korean);

    printf("영어 점수 입력: ");
    scanf("%d", &english);

    printf("수학 점수 입력: ");
    scanf("%d", &math);

    printf("과학 점수 입력: ");
    scanf("%d", &science);

    return createStudent(id, name, korean, english, math, science);
}

/*
    학생 정보 최신화 함수
    함수명: is_remake()
    설명: 기존 학생의 이름과 점수를 수정하고 평균과 내신 등급을 다시 계산한다.
*/
void is_remake(Student* student) {
    if (student == NULL) {
        printf("수정할 학생을 찾을 수 없습니다.\n");
        return;
    }

    printf("\n========== 학생 정보 최신화 ==========" "\n");
    printf("[기존 학생 정보]\n");
    printStudent(student);

    printf("\n새 이름 입력: ");
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

    printf("\n학생 정보가 최신화되었습니다.\n");
    printf("\n[최신화된 학생 정보]\n");
    printStudent(student);
}

/*
    약점 탐색 함수
    함수명: is_weak()
    설명: 학생 성적 중 가장 낮은 과목을 찾아 학습 조언을 출력한다.
*/
void is_weak(Student* student) {
    if (student == NULL) {
        printf("학생을 찾을 수 없습니다.\n");
        return;
    }

    int min = student->korean;

    if (student->english < min) min = student->english;
    if (student->math < min) min = student->math;
    if (student->science < min) min = student->science;

    printf("\n========== 약점 탐색 결과 ==========" "\n");
    printf("학생 이름: %s\n", student->name);
    printf("국어: %d점\n", student->korean);
    printf("영어: %d점\n", student->english);
    printf("수학: %d점\n", student->math);
    printf("과학: %d점\n", student->science);

    printf("\n가장 약한 과목: ");
    if (student->korean == min) printf("국어 ");
    if (student->english == min) printf("영어 ");
    if (student->math == min) printf("수학 ");
    if (student->science == min) printf("과학 ");

    printf("\n최저 점수: %d점\n", min);

    printf("\n[학습 조언]\n");
    if (min >= 85) {
        printf("전체적으로 성적이 좋은 편입니다. 심화 문제 위주로 공부하면 좋습니다.\n");
    }
    else if (min >= 70) {
        printf("기본 개념은 어느 정도 되어 있습니다. 오답 노트를 활용해 보완하세요.\n");
    }
    else {
        printf("기초 개념부터 다시 정리하고 쉬운 문제부터 반복 학습하세요.\n");
    }

    if (student->korean == min) printf("- 국어: 지문 독해 연습과 어휘 정리를 추천합니다.\n");
    if (student->english == min) printf("- 영어: 단어 암기와 문법 기초 복습을 추천합니다.\n");
    if (student->math == min) printf("- 수학: 공식 암기보다 문제 풀이 과정을 이해하는 연습이 필요합니다.\n");
    if (student->science == min) printf("- 과학: 개념 정리 후 기출 문제를 풀어보는 것을 추천합니다.\n");
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
