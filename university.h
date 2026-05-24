#ifndef UNIVERSITY_H
#define UNIVERSITY_H

/*
    university.h
    - 대학 입시 비교, 대학 후기, 모의 면접, 입시 소식 함수 선언 파일
*/

#include "student.h"

#ifdef __cplusplus
extern "C" {
#endif

    /* 대학별 전형 정보를 저장하는 구조체 */
    typedef struct University {
        char name[50];          // 대학 이름
        char major[50];         // 학과 이름
        char type[30];          // 전형 이름
        double cutline;         // 기준 내신 등급
        char essayType[30];     // 논술 유형
        char practicalItem[50]; // 실기 항목
        int practicalScore;     // 합격자 평균 실기 점수
    } University;

    /* 전형별 대학 입시 예상 및 지원 */
    void is_verse(Member* member);

    /* 대학 후기 / 모의 면접 선택 기능 */
    void is_review(void);

    /* 대학 및 입시 관련 소식 */
    void is_date(void);

#ifdef __cplusplus
}
#endif

#endif
