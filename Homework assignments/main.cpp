// 25125083
// Nguyen Dinh Minh Huy
// 25A01

#include "Date.hpp"
#include "Student.hpp"
#include "Functions.hpp"

#include <iostream>
#include <vector>
#include <string>

void P401();
void P402();
void P403();
void P404();
void P405();

int main()
{
    char choice;
        
    do {
        std::cout << "\n--- MAIN MENU ---\n";
        std::cout << "1. P401 (Date struct handling)\n";
        std::cout << "2. P402 (Student struct handling)\n";
        std::cout << "3. P403 (Reverse Integer)\n";
        std::cout << "4. P404 (3Sum)\n";
        std::cout << "5. P405 (Sqrt(x))\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        
        std::cin >> choice;
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case '1': P401(); break;
            case '2': P402(); break;
            case '3': P403(); break;
            case '4': P404(); break;
            case '5': P405(); break;
            case '0':
                std::cout << "Exitting the program...\n";
                break;
            default:
                std::cout << "Invalid command! Please try again.\n";
                break;
        }
    } while (choice != '0');
    
    return EXIT_SUCCESS;
}

// === P401 (Date) Menu ===
void P401()
{
    Date d1, d2;
    int compare, k;
    std::string inFilename = "date_input.txt";
    std::string outFilename = "date_output.txt";
    std::string format;
            
    char choice;
    do {
        std::cout << "\n--- P401: Date struct handling ---\n";
        std::cout << "1. Input a date (console)\n";
        std::cout << "2. Output a date (console)\n";
        std::cout << "3. Input a date (from file 'input.txt')\n";
        std::cout << "4. Output a date (yyyy-MM-dd to file)\n";
        std::cout << "5. Output a date with given format (to file)\n";
        std::cout << "6. Compare 2 dates\n";
        std::cout << "7. Find tomorrow\n";
        std::cout << "8. Find yesterday\n";
        std::cout << "9. Increase a date by k days\n";
        std::cout << "a. Decrease a date by k days\n";
        std::cout << "b. Compute distance to 1/1/same year\n";
        std::cout << "c. Compute distance to 1/1/1970\n";
        std::cout << "d. Compute distance between 2 dates\n";
        std::cout << "e. Compute day of week\n";
        std::cout << "0. Return to Main Menu\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case '1':
                std::cout << "Enter date d1\n";
                inputDate(d1);
                std::cout << "Date d1 stored.\n";
                break;
            case '2':
                std::cout << "Date d1: ";
                outputDate(d1);
                break;
            case '3':
                if (inputDateFromFile(d1, inFilename))
                    std::cout << "Date d1 loaded from file .\n";
                break;
            case '4':
                if (outputDateToFile(d1, outFilename))
                    std::cout << "Date d1 written to file.\n";
                break;
            case '5':
                std::cout << "Enter format (e.g., MMM dd yy): ";
                std::getline(std::cin, format);
                if (outputDateWithFormat(d1, format, outFilename))
                    std::cout << "Date d1 (formatted) written to file.\n";
                break;
            case '6':
                std::cout << "Enter date d2\n";
                inputDate(d2);
                compare = compareDate(d1, d2);
                if (compare == 0) std::cout << "Dates are equal.\n";
                else if (compare == 1) std::cout << "Date 1 is later.\n";
                else std::cout << "Date 1 is earlier.\n";
                break;
            case '7':
                d2 = findTomorrow(d1);
                std::cout << "Tomorrow is: ";
                outputDate(d2);
                break;
            case '8':
                d2 = findYesterday(d1);
                std::cout << "Yesterday was: ";
                outputDate(d2);
                break;
            case '9':
                std::cout << "Enter k: ";
                std::cin >> k;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                increaseDate(d1, k);
                std::cout << "New date is: ";
                outputDate(d1);
                break;
            case 'a':
                std::cout << "Enter k: ";
                std::cin >> k;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                decreaseDate(d1, k);
                std::cout << "New date is: ";
                outputDate(d1);
                break;
            case 'b':
                std::cout << "Distance of d1 to start of year: " << distanceToStartOfYear(d1) << " days.\n";
                break;
            case 'c':
                std::cout << "Distance of d1 to 1/1/1970: " << distanceTo1970(d1) << " days.\n";
                break;
            case 'd':
                std::cout << "Enter date d2\n";
                inputDate(d2);
                std::cout << "Distance between dates: " << distanceBetweenDates(d1, d2) << " days.\n";
                break;
            case 'e':
                std::cout << "Day of week of d1: " << getDayOfWeek(d1) << "\n";
                break;
            case '0':
                std::cout << "Returning to main menu...\n";
                break;
            default:
                std::cout << "Unknown command!\n";
                break;
        }
    } while (choice != '0');
}

// === P402 (Student) Menu ===
void P402()
{
    Student s1, s2;
    int compare = 0;
    std::string inFilename = "student_input.txt";
    std::string outFilename = "student_output.txt";
    
    char choice;
    do {
        std::cout << "\n--- P402: Student struct handling ---\n";
        std::cout << "1. Input a student (console)\n";
        std::cout << "2. Output a student (console)\n";
        std::cout << "3. Input a student (from file 'student.txt')\n";
        std::cout << "4. Output a student (id, full name... to file)\n";
        std::cout << "5. Output a student (with firstname, lastname, age... to file)\n";
        std::cout << "6. Extract class of input student\n";
        std::cout << "7. Compare 2 students by id\n";
        std::cout << "8. Compare 2 students by gpa, then by id\n";
        std::cout << "9. Compare 2 students by name, then by id\n";
        std::cout << "a. Compare 2 students by first name, then by id\n";
        std::cout << "b. Compare 2 students by last name, then by id\n";
        std::cout << "c. Compare 2 students by dob, then by id\n";
        std::cout << "0. Return to Main Menu\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case '1':
                std::cout << "Enter student 1 info:\n";
                inputStudent(s1);
                std::cout << "Student 1 stored.\n";
                break;
            case '2':
                std::cout << "Student 1 info:\n";
                outputStudent(s1);
                break;
            case '3':
                if (inputStudentFromFile(s1, inFilename))
                    std::cout << "Student s1 loaded from file.\n";
                break;
            case '4':
                if (outputStudentToFile(s1, outFilename))
                    std::cout << "Student s1 saved to file.\n";
                break;
            case '5':
                if (outputStudentWithAgeToFile(s1, outFilename))
                    std::cout << "Student s1 saved to file (other format).\n";
                break;
            case '6':
                std::cout << "Student 1's class is: " << extractClass(s1) << '\n';
                break;
            // Intentional fall-thru
            case '7':
            case '8':
            case '9':
            case 'a':
            case 'b':
            case 'c':
                std::cout << "Enter info for student 2:\n";
                inputStudent(s2);
                if (choice == '7') compare = compareByID(s1, s2);
                else if (choice == '8') compare = compareByGPA_ID(s1, s2);
                else if (choice == '9') compare = compareByName_ID(s1, s2);
                else if (choice == 'a') compare = compareByFirstName_ID(s1, s2);
                else if (choice == 'b') compare = compareByLastName_ID(s1, s2);
                else if (choice == 'c') compare = compareByDOB_ID(s1, s2);
                
                if (compare == 0) std::cout << "S1 is equivalent to S2.\n";
                else if (compare == 1) std::cout << "S1 is greater than S2.\n";
                else std::cout << "S1 is less than S2.\n";
                break;
            case '0':
                std::cout << "Returning to main menu...\n";
                break;
            default:
                std::cout << "Unknown command!\n";
                break;
        }
    } while (choice != '0');
}

void P403()
{
    int x;
    std::cout << "\n--- P403: Reverse Integer ---\n";
    std::cout << "Enter integer: ";
    std::cin >> x;
    std::cout << "Reversed integer: " << reverse(x) << '\n';
}

void P404()
{
    std::cout << "\n--- P404: 3Sum ---\n";
    std::vector<int> nums;
    inputList(nums);

    std::vector<std::vector<int>> triplets = threeSum(nums);
    std::cout << "Triplets that sum to 0:\n";
    if (triplets.empty()) {
        std::cout << "No triplets found.\n";
        return;
    }
    
    outputTriplets(triplets);
}

void P405()
{
    int x;
    std::cout << "\n--- P405: Sqrt(x) ---\n";
    std::cout << "Enter integer: ";
    std::cin >> x;
    std::cout << "Rounded down square root: " << mySqrt(x) << '\n';
}
