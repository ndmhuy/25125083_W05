//
//  Student.cpp
//  Learning
//
//  Created by Huy Nguyen on 16/11/25.
//

#include "Student.hpp"
#include "Date.hpp"
#include "Functions.hpp"

#include <iostream>
#include <fstream>

void inputStudent(Student& s)
{
    std::cout << "Enter ID: ";
    getline(std::cin, s.id);
    std::cout << "Enter full name: ";
    getline(std::cin, s.fullName);
    std::cout << "Enter GPA: ";
    std::cin >> s.gpa;
    std::cin.ignore();
    std::cout << "Enter address: ";
    getline(std::cin, s.address);
    std::cout << "Enter date of birth (dd MM yyyy) ";
    std::cin >> s.dob.day >> s.dob.month >> s.dob.year;
    std::cin.ignore();
}

void outputStudent(const Student& s)
{
    std::cout << "ID: " << s.id << '\n';
    std::cout << "Full name: " << s.fullName << '\n';
    std::cout << "GPA: " << std::fixed << std::setprecision(2) << s.gpa << '\n';
    std::cout << "Address: " << s.address << '\n';
    std::cout << "Date of birth: " << getFormattedDate(s.dob, "dd/MM/yyyy");
}

bool inputStudentFromFile(Student& s, const std::string& filename)
{
    std::ifstream fin;
    fin.open(filename);
    if (!fin) {
        std::cout << "File cannot be opened.\n";
        return false;
    }
    
    // Suppose each info in each line
    getline(fin, s.id);
    getline(fin, s.fullName);
    fin >> s.gpa;
    fin.ignore();
    getline(fin, s.address);
    fin >> s.dob.day >> s.dob.month >> s.dob.year;
    
    fin.close();
    return true;
}

bool outputStudentToFile(const Student& s, const std::string& filename)
{
    std::ofstream fout;
    fout.open(filename);
    if (!fout) {
        std::cout << "File cannot be opened.\n";
        return false;
    }
    
    // for writing
    fout << s.id << '\n';
    fout << s.fullName << '\n';
    fout << std::fixed << std::setprecision(2) << s.gpa << '\n';
    fout << s.address << '\n';
    fout << getFormattedDate(s.dob, "dd/MM/yyyy") << '\n';
    
    fout.close();
    return true;
}

bool outputStudentWithAgeToFile(const Student& s, const std::string& filename)
{
    std::ofstream fout;
    fout.open(filename);
    if (!fout) {
        std::cout << "File cannot be opened.\n";
        return false;
    }
    
    std::string firstName = getFirstName(s.fullName);
    std::string lastName = getLastName(s.fullName);
    Date age = calculateAge(s.dob);
    
    // for observing
    fout << "ID: " << s.id << '\n';
    fout << "First name:" << firstName << '\n';
    fout << "Last name: " << lastName << '\n';
    fout << "GPA: " << std::fixed << std::setprecision(2) << s.gpa << '\n';
    fout << "Address: " << s.address << '\n';
    fout << "Date of birth: " << getFormattedDate(s.dob, "dd/MM/yyyy") << '\n';
    
    std::string yearManip = (age.year > 1) ? " years " : " year ";
    std::string monthManip = (age.month > 1) ? " months " : " month ";
    std::string ageManip = (age.day > 1) ? " days " : " day";
    fout << "Age: " << age.year << yearManip << age.month << monthManip << age.day << ageManip << '\n';
    
    fout.close();
    return true;
}

std::string extractClass(const Student& s)
{
    if (s.id.length() < 2) return "K_Invalid";
    std::string classYear = s.id.substr(0, 2);
    return "K" + classYear;
}

int compareByID(const Student& s1, const Student& s2)
{
    if (s1.id < s2.id) return -1;
    if (s1.id > s2.id) return 1;
    return 0;
}

int compareByGPA_ID(const Student& s1, const Student& s2)
{
    if (s1.gpa < s2.gpa) return -1;
    if (s1.gpa > s2.gpa) return 1;
    return compareByID(s1, s2);
}
int compareByName_ID(const Student& s1, const Student& s2)
{
    if (s1.fullName < s2.fullName) return -1;
    if (s1.fullName > s2.fullName) return 1;
    return compareByID(s1, s2);
}

int compareByFirstName_ID(const Student& s1, const Student& s2)
{
    std::string fn1 = getFirstName(s1.fullName);
    std::string fn2 = getFirstName(s2.fullName);
    
    if (fn1 < fn2) return -1;
    if (fn1 > fn2) return 1;
    return compareByID(s1, s2);
}

int compareByLastName_ID(const Student& s1, const Student& s2)
{
    std::string ln1 = getLastName(s1.fullName);
    std::string ln2 = getLastName(s2.fullName);
    
    if (ln1 < ln2) return -1;
    if (ln1 > ln2) return 1;
    return compareByID(s1, s2);
}

int compareByDOB_ID(const Student& s1, const Student& s2)
{
    int dobCompare = compareDate(s1.dob, s2.dob);
    if (dobCompare != 0) return dobCompare;
    return compareByID(s1, s2);
}
