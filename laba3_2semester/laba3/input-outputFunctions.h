#pragma once
#include "Student.h"
#include "Teacher.h"
#include <vector>

void inputStud(const char* fileOfStud, std::vector<Student> students);
void inputTeach(const char* fileOfTeach, std::vector<Teacher> teachers);
void outputStud(const char* fileOfStud);
void outputTeach(const char* fileOfTeach);