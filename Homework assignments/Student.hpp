//
//  Student.hpp
//  Learning
//
//  Created by Huy Nguyen on 16/11/25.
//

#ifndef Student_hpp
#define Student_hpp

#include "Date.hpp"

#include <iostream>

struct Student
{
    std::string id;
    std::string fullName;
    double gpa;
    std::string address;
    Date dob;
};

void inputStudent(Student& s);
void outputStudent(const Student& s);
bool inputStudentFromFile(Student& s, const std::string& filename);
bool outputStudentToFile(const Student& s, const std::string& filename);
bool outputStudentWithAgeToFile(const Student& s, const std::string& filename);
std::string extractClass(const Student& s);
int compareByID(const Student& s1, const Student& s2);
int compareByGPA_ID(const Student& s1, const Student& s2);
int compareByName_ID(const Student& s1, const Student& s2);
int compareByFirstName_ID(const Student& s1, const Student& s2);
int compareByLastName_ID(const Student& s1, const Student& s2);
int compareByDOB_ID(const Student& s1, const Student& s2);

#endif /* Student_hpp */
