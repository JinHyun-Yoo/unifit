#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "student.h"

typedef struct University {
    char name[50];
    char major[50];
    double cutline;
} University;

void compareUniversity(Student* student);

#endif