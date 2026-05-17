#include <stdio.h>
#include "university.h"

University uniList[] = {
    {"서울대학교", "컴퓨터공학부", 1.3},
    {"연세대학교", "컴퓨터과학과", 1.5},
    {"고려대학교", "컴퓨터학과", 1.6},
    {"한양대학교", "컴퓨터소프트웨어학부", 2.0},
    {"중앙대학교", "소프트웨어학부", 2.3},
    {"건국대학교", "컴퓨터공학부", 2.8},
    {"동국대학교", "AI소프트웨어융합학부", 3.0},
    {"국민대학교", "소프트웨어학부", 3.5},
    {"숭실대학교", "컴퓨터학부", 3.6},
    {"세종대학교", "컴퓨터공학과", 3.8}
};

int uniCount = sizeof(uniList) / sizeof(uniList[0]);

void compareUniversity(Student* student) {
    if (student == NULL) {
        printf("학생 정보가 없습니다.\n");
        return;
    }

    printf("\n========== 대학교 입시 비교 결과 ==========\n");
    printf("학생 이름: %s\n", student->name);
    printf("학생 평균: %.2lf\n", student->average);
    printf("학생 내신 등급: %.1lf\n", student->grade);
    printf("==========================================\n");

    for (int i = 0; i < uniCount; i++) {
        double diff = uniList[i].cutline - student->grade;

        printf("\n대학교: %s\n", uniList[i].name);
        printf("학과: %s\n", uniList[i].major);
        printf("기준 등급: %.1lf\n", uniList[i].cutline);

        if (diff >= 0.5) {
            printf("결과: 안정 지원\n");
        }
        else if (diff >= 0.0) {
            printf("결과: 적정 지원\n");
        }
        else if (diff >= -0.5) {
            printf("결과: 상향 지원\n");
        }
        else {
            printf("결과: 지원 어려움\n");
        }
    }
}