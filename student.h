#ifndef STUDENT_H
#define STUDENT_H

/*
    student.h
    - 회원 정보를 저장할 구조체와 회원 관리 함수 선언 파일
    - 실제 구현은 student.c에 작성되어 있음
*/

#ifdef __cplusplus
extern "C" {
#endif

    /* 회원 정보를 저장하는 구조체
       트리 기반 관리를 위해 left, right 포인터를 사용한다. */
    typedef struct Member {
        int id;                 // 회원 번호 또는 학번
        char name[30];          // 회원 이름
        double grade;           // 회원 내신 등급, 숫자가 낮을수록 좋음

        struct Member* left;    // 현재 회원보다 id가 작은 회원
        struct Member* right;   // 현재 회원보다 id가 큰 회원
    } Member;

    /* 회원 정보 입력 함수
       사용자가 회원 번호, 이름, 내신 등급을 입력하면 새 회원 노드를 생성한다. */
    Member* is_login(void);

    /* 회원 추가, 검색, 삭제 함수 */
    Member* insertMember(Member* root, Member* newMember);
    Member* searchMember(Member* root, int id);
    Member* deleteMember(Member* root, int id);

    /* 회원 정보 최신화 함수 */
    void is_remake(Member* root);

    /* 회원 정보 출력 및 전체 메모리 해제 함수 */
    void printMember(Member* member);
    void freeTree(Member* root);

#ifdef __cplusplus
}
#endif

#endif
