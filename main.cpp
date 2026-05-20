#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "student.h"
#include "university.h"

void showMenu(void) {
    printf("\n========== UNIFIT 학생 입시 관리 시스템 ==========" "\n");
    printf("1. 회원 정보 입력\n");
    printf("2. 회원 정보 수정\n");
    printf("3. 회원 탈퇴\n");
    printf("4. 대학 입시 예상 및 지원\n");
    printf("5. 약점 탐색\n");
    printf("6. 모의 면접 & 대학 후기\n");
    printf("7. 대학 및 입시 관련 소식\n");
    printf("0. 종료\n");
    printf("메뉴 선택: ");
}

int inputStudentId(void) {
    int id;
    printf("학번 입력: ");
    scanf("%d", &id);
    return id;
}

int main(void) {
    Student* root = NULL;
    int menu;

    while (1) {
        showMenu();
        scanf("%d", &menu);

        if (menu == 1) {
            Student* newStudent = is_login();
            root = insertStudent(root, newStudent);
        }
        else if (menu == 2) {
            int id = inputStudentId();
            Student* student = searchStudent(root, id);
            is_remake(student);
        }
        else if (menu == 3) {
            int id = inputStudentId();
            root = deleteStudent(root, id);
        }
        else if (menu == 4) {
            int id = inputStudentId();
            Student* student = searchStudent(root, id);
            is_verse(student);
        }
        else if (menu == 5) {
            int id = inputStudentId();
            Student* student = searchStudent(root, id);
            is_weak(student);
        }
        else if (menu == 6) {
            is_review();
        }
        else if (menu == 7) {
            is_date();
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
