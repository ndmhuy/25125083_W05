// 25125083
// Nguyen Dinh Minh Huy
// 25A01

#include "Fraction.hpp"
#include "Functions.hpp"

#include <iostream>
#include <fstream>

void P02();
void P20();
void P23();
void P400();

int main()
{
    int choice;
    do {
        std::cout << "In-class assignments\n";
        std::cout << "1. P02 (Sum of squared)\n";
        std::cout << "2. P20 (List all divisors)\n";
        std::cout << "3. P23 (Count divisors)\n";
        std::cout << "4. P400 (Fraction handling)\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1: P02(); break;
            case 2: P20(); break;
            case 3: P23(); break;
            case 4: P400(); break;
            case 0:
                std::cout << "Exitting the program...\n";
                break;
            default:
                std::cout << "Invalid command!\n";
                break;
        }
    } while (choice != 0);
    
    return EXIT_SUCCESS;
}

void P02()
{
    std::cout << "--- P02: Sum of squared ---\n";
    int n;
    std::cin >> n;
    std::cout << sumOfSquared(n) << '\n';
}

void P20()
{
    std::cout << "--- P20: List all divisors ---\n";
    int n;
    std::cin >> n;
    listAllDivisors(n);
}

void P23()
{
    std::cout << "--- P04: Count divisors ---\n";
    int n;
    std::cin >> n;
    std::cout << divisorsCount(n) << '\n';
}

void P400()
{
    std::cout << "--- P400: Fraction handling ---\n";
    std::cout << "1. Input a fraction (from console) (Format: numerator/denominator) then output\n";
    std::cout << "2. Add two fractions\n";
    std::cout << "3. Subtract two fractions\n";
    std::cout << "4. Input a fraction (from text file)\n";
    std::cout << "5. Output a fraction (to text file)\n";
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    
    Fraction f, a, b;
    std::string inputPath = "input.txt";
    std::string outputPath = "output.txt";
    std::ifstream fin;
    std::ofstream fout;
    switch (choice) {
        case 1:
            std::cout << "Enter a fraction:\n";
            std::cin >> f;
            std::cout << "You have entered: " << f << '\n';
            break;
        case 2:
            std::cout << "Enter two fractions consecutively:\n";
            std::cin >> a >> b;
            std::cout << a << " + " << b << " = " << add(a, b) << '\n';
            break;
        case 3:
            std::cout << "Enter two fractions consecutively:\n";
            std::cin >> a >> b;
            std::cout << a << " - " << b << " = " << subtract(a, b) << '\n';
            break;
        case 4:
            fin.open(inputPath);
            fin >> f;
            fin.close();
            std::cout << "Having read from " << inputPath << ": " << f << '\n';
            break;
        case 5:
            std::cout << "Enter a fraction:\n";
            std::cin >> f;
            fout.open(outputPath);
            fout << f;
            fout.close();
            std::cout << "Fraction have been written into " << outputPath << '\n';
            break;
        default:
            std::cout << "Unknown command!\n";
            std::cin.ignore(1000);
            break;
    }
}
