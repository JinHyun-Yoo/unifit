#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "student.h"

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct University {
        char name[50];
        char major[50];
        char type[30];
        double cutline;
    } University;

    void is_verse(Student* student); // 대학 입시 예상 및 지원
    void is_review(void);           // 모의 면접 & 대학 후기
    void is_date(void);             // 대학 및 입시 관련 소식

#ifdef __cplusplus
}
#endif

#endif
