#ifndef STUDENT_H
#define STUDENT_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct Student {
        int id;
        char name[30];

        int korean;
        int english;
        int math;
        int science;

        double average;
        double grade;

        struct Student* left;
        struct Student* right;
    } Student;

    double calculateAverage(int korean, int english, int math, int science);
    double calculateGrade(double average);

    Student* createStudent(int id, char name[], int korean, int english, int math, int science);
    Student* insertStudent(Student* root, Student* newStudent);
    Student* searchStudent(Student* root, int id);
    Student* deleteStudent(Student* root, int id);

    Student* is_login(void);          // 학생 정보 입력 함수
    void is_remake(Student* student); // 학생 정보 최신화 함수
    void is_weak(Student* student);   // 약점 탐색 함수

    void printStudent(Student* student);
    void freeTree(Student* root);

#ifdef __cplusplus
}
#endif

#endif
