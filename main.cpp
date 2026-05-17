#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "student.h"
#include "university.h"

void showMenu() {
    printf("\n========== 성적 관리 시스템 ==========\n");
    printf("1. 회원 정보 입력\n");
    printf("2. 회원 정보 수정\n");
    printf("3. 회원 탈퇴\n");
    printf("4. 대학교 입시 비교\n");
    printf("0. 종료\n");
    printf("메뉴 선택: ");
}

int main() {
    Student* root = NULL;
    int menu;

    while (1) {
        showMenu();
        scanf("%d", &menu);

        if (menu == 1) {
            int id, korean, english, math, science;
            char name[30];

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

            Student* newStudent = createStudent(id, name, korean, english, math, science);
            root = insertStudent(root, newStudent);

            printf("학생 정보가 추가되었습니다.\n");
        }

        else if (menu == 2) {
            int id;

            printf("수정할 학생의 학번 입력: ");
            scanf("%d", &id);

            updateStudentInfo(root, id);
        }

        else if (menu == 3) {
            int id;

            printf("삭제할 학번 입력: ");
            scanf("%d", &id);

            root = deleteStudent(root, id);
        }

        else if (menu == 4) {
            int id;

            printf("입시 비교할 학생의 학번 입력: ");
            scanf("%d", &id);

            Student* result = searchStudent(root, id);

            if (result == NULL) {
                printf("학생을 찾을 수 없습니다.\n");
            }
            else {
                compareUniversity(result);
            }
        }

        else if (menu == 0) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        else {
            printf("잘못된 메뉴입니다. 다시 선택하세요.\n");
        }
    }

    freeTree(root);

    return 0;
}