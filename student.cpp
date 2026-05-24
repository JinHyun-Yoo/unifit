#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/*
    is_login()
    - 회원 정보를 입력받는 함수
    - 과목 점수와 평균 계산은 사용하지 않고, 내신 등급을 직접 입력받는다.
*/
Member* is_login(void) {
    Member* newMember = (Member*)malloc(sizeof(Member));

    if (newMember == NULL) {
        printf("메모리 할당 실패\n");
        exit(1);
    }

    printf("회원 번호 입력: ");
    scanf("%d", &newMember->id);

    printf("회원 이름 입력: ");
    scanf("%29s", newMember->name);

    printf("내신 등급 입력 예: 2.5 : ");
    scanf("%lf", &newMember->grade);

    newMember->left = NULL;
    newMember->right = NULL;

    return newMember;
}

/*
    insertMember()
    - 이진 탐색 트리에 회원을 추가하는 함수
    - 회원 번호가 작으면 왼쪽, 크면 오른쪽에 저장한다.
*/
Member* insertMember(Member* root, Member* newMember) {
    if (newMember == NULL) {
        return root;
    }

    if (root == NULL) {
        printf("회원 정보가 입력되었습니다.\n");
        return newMember;
    }

    if (newMember->id < root->id) {
        root->left = insertMember(root->left, newMember);
    }
    else if (newMember->id > root->id) {
        root->right = insertMember(root->right, newMember);
    }
    else {
        printf("이미 존재하는 회원 번호입니다. 입력한 정보는 저장하지 않습니다.\n");
        free(newMember);
    }

    return root;
}

/*
    searchMember()
    - 회원 번호를 기준으로 회원을 찾는 함수
*/
Member* searchMember(Member* root, int id) {
    if (root == NULL) {
        return NULL;
    }

    if (id == root->id) {
        return root;
    }
    else if (id < root->id) {
        return searchMember(root->left, id);
    }
    else {
        return searchMember(root->right, id);
    }
}

/*
    findMin()
    - 삭제 과정에서 오른쪽 서브트리의 가장 작은 노드를 찾는 함수
    - student.c 내부에서만 사용하므로 헤더 파일에는 선언하지 않는다.
*/
static Member* findMin(Member* root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

/*
    deleteMember()
    - 회원 번호를 기준으로 회원을 삭제하는 함수
*/
Member* deleteMember(Member* root, int id) {
    if (root == NULL) {
        printf("삭제할 회원을 찾을 수 없습니다.\n");
        return NULL;
    }

    if (id < root->id) {
        root->left = deleteMember(root->left, id);
    }
    else if (id > root->id) {
        root->right = deleteMember(root->right, id);
    }
    else {
        Member* temp;

        // 자식이 없거나 오른쪽 자식만 있는 경우
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            printf("회원 정보가 삭제되었습니다.\n");
            return temp;
        }

        // 왼쪽 자식만 있는 경우
        if (root->right == NULL) {
            temp = root->left;
            free(root);
            printf("회원 정보가 삭제되었습니다.\n");
            return temp;
        }

        // 자식이 두 명인 경우: 오른쪽 서브트리에서 가장 작은 값을 가져온다.
        temp = findMin(root->right);
        root->id = temp->id;
        strcpy(root->name, temp->name);
        root->grade = temp->grade;

        root->right = deleteMember(root->right, temp->id);
    }

    return root;
}

/*
    is_remake()
    - 회원 정보를 최신화하는 함수
    - 회원 번호는 트리 정렬 기준이므로 수정하지 않고, 이름과 내신 등급만 수정한다.
*/
void is_remake(Member* root) {
    int id;
    Member* member;

    if (root == NULL) {
        printf("등록된 회원 정보가 없습니다.\n");
        return;
    }

    printf("수정할 회원 번호 입력: ");
    scanf("%d", &id);

    member = searchMember(root, id);

    if (member == NULL) {
        printf("해당 회원을 찾을 수 없습니다.\n");
        return;
    }

    printf("\n[현재 회원 정보]\n");
    printMember(member);

    printf("\n새 이름 입력: ");
    scanf("%29s", member->name);

    printf("새 내신 등급 입력 예: 2.5 : ");
    scanf("%lf", &member->grade);

    printf("\n회원 정보가 최신화되었습니다.\n");
    printf("\n[최신화된 회원 정보]\n");
    printMember(member);
}

/*
    printMember()
    - 회원 1명의 정보를 출력하는 함수
*/
void printMember(Member* member) {
    if (member == NULL) {
        return;
    }

    printf("회원 번호: %d\n", member->id);
    printf("회원 이름: %s\n", member->name);
    printf("내신 등급: %.2lf\n", member->grade);
}

/*
    freeTree()
    - 프로그램 종료 전 동적 할당된 회원 노드를 모두 해제하는 함수
*/
void freeTree(Member* root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
