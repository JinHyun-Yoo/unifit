#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "student.h"
#include "university.h"

/*
    main.c
    - UNIFIT 프로그램의 메인 메뉴와 전체 실행 흐름을 담당한다.
*/

/* 메인 메뉴 출력 함수 */
void showMenu(void) {
    printf("\n========== UNIFIT 회원 입시 관리 시스템 ==========" "\n");
    printf("1. 회원 정보 입력\n");
    printf("2. 회원 정보 수정\n");
    printf("3. 회원 탈퇴\n");
    printf("4. 전형별 대학 입시 예상 및 지원\n");
    printf("5. 대학 후기 / 모의 면접\n");
    printf("6. 대학 및 입시 관련 소식\n");
    printf("0. 종료\n");
    printf("메뉴 선택: ");
}

int main(void) {
    Member* root = NULL;    // 회원 정보를 저장하는 이진 탐색 트리의 루트
    int menu;

    while (1) {
        showMenu();
        scanf("%d", &menu);

        if (menu == 1) {
            // 회원 정보를 입력받고 트리에 추가한다.
            Member* newMember = is_login();
            root = insertMember(root, newMember);
        }
        else if (menu == 2) {
            // 회원 번호로 회원을 찾아 이름과 내신 등급을 최신화한다.
            is_remake(root);
        }
        else if (menu == 3) {
            int id;

            printf("삭제할 회원 번호 입력: ");
            scanf("%d", &id);

            root = deleteMember(root, id);
        }
        else if (menu == 4) {
            int id;
            Member* member;

            printf("입시 비교할 회원 번호 입력: ");
            scanf("%d", &id);

            member = searchMember(root, id);

            if (member == NULL) {
                printf("해당 회원을 찾을 수 없습니다.\n");
            }
            else {
                is_verse(member);
            }
        }
        else if (menu == 5) {
            // 대학 후기와 모의 면접 질문을 선택해서 확인한다.
            is_review();
        }
        else if (menu == 6) {
            // 입시 일정과 관련 안내를 출력한다.
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

    // 프로그램 종료 전 동적 할당된 메모리를 해제한다.
    freeTree(root);

    return 0;
}
