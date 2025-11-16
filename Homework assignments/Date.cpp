//
//  Date.cpp
//  Learning
//
//  Created by Huy Nguyen on 15/11/25.
//

#include "Date.hpp"
#include "Functions.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

void inputDate(Date& d)
{
    std::cout << "Enter day: ";
    std::cin >> d.day;
    std::cout << "Enter month: ";
    std::cin >> d.month;
    std::cout << "Enter year: ";
    std::cin >> d.year;
}

void outputDate(const Date& d)
{
    std::cout << getFormattedDate(d, "dd//MM/yyyy") << '\n';
}

bool inputDateFromFile(Date& d, const std::string& filename)
{
    std::ifstream fin;
    fin.open(filename);
    if (!fin) {
        std::cout << "File cannot be opened.\n";
        return false;
    }
    
    // Suppose format: dd MM yyyy
    fin >> d.day >> d.month >> d.year;
    fin.close();
    return true;
}

bool outputDateToFile(const Date& d, const std::string& filename)
{
    std::ofstream fout;
    fout.open(filename);
    if (!fout) {
        std::cout << "File cannot be opened.\n";
        return false;
    }
    
    // Format: yyyy-MM-dd
    fout << std::setfill('0');
    fout << std::setw(4) << d.year << "-";
    fout << std::setw(2) << d.month << "-";
    fout << std::setw(2) << d.day << '\n';
    fout.close();
    return true;
}

std::string getFormattedDate(const Date& d, std::string format)
{
    std::string monthNames[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    std::stringstream ss_yy, ss_MM, ss_dd;
    
    ss_yy << std::setfill('0') << std::setw(2) << (d.year % 100);
    ss_MM << std::setfill('0') << std::setw(2) << d.month;
    ss_dd << std::setfill('0') << std::setw(2) << d.day;


    replaceSubString(format, "yyyy", std::to_string(d.year));
    replaceSubString(format, "yy", ss_yy.str());

    replaceSubString(format, "MMM", monthNames[d.month - 1]);
    replaceSubString(format, "MM", ss_MM.str());
    replaceSubString(format, "M", std::to_string(d.month));

    replaceSubString(format, "dd", ss_dd.str());
    replaceSubString(format, "d", std::to_string(d.day));
    
    return format;
}

bool outputDateWithFormat(const Date& d, std::string format, const std::string& filename)
{
    std::string formatted = getFormattedDate(d, format);
    
    std::ofstream fout;
    fout.open(filename);
    if (!fout) {
        std::cout << "File cannot be opened.\n";
        return false;
    }
    
    fout << formatted << '\n';
    fout.close();
    return true;
}

// return: -1 (d1 < d2) 0 (d1 = d2) 1 (d1 > d2)
int compareDate(const Date& d1, const Date& d2)
{
    if (d1.year < d2.year) return -1;
    if (d1.year > d2.year) return 1;
    
    if (d1.month < d2.month) return -1;
    if (d1.month > d2.month) return 1;
    
    if (d1.day < d2.day) return -1;
    if (d1.day > d2.day) return 1;
    
    return 0;
}

Date findTomorrow(Date d)
{
    int maxDays = daysInMonth(d.month, d.year);
    if (d.day < maxDays) ++d.day;
    else {
        d.day = 1;
        if (d.month < 12) ++d.month;
        else {
            d.month = 1;
            ++d.year;
        }
    }
    return d;
}

Date findYesterday(Date d)
{
    if (d.day > 1) --d.day;
    else {
        if (d.month < 1) --d.month;
        else {
            d.month = 12;
            --d.year;
        }
        d.day = daysInMonth(d.month, d.year);
    }
    return d;
}

void increaseDate(Date& d, int k)
{
    for (int i = 0; i < k; ++i)
        d = findTomorrow(d);
}

void decreaseDate(Date& d, int k)
{
    for (int i = 0; i < k; ++i) {
        d = findYesterday(d);
    }
}

long long countTotalDaysSince1970(const Date& d)
{
    long long totalDays = 0LL;
    for (int y = 1970; y < d.year; ++y) {
        totalDays += (isLeapYear(y)) ? 366 : 365;
    }
    
    for (int m = 1; m < d.month; ++m) {
        totalDays += daysInMonth(m, d.year);
    }
    
    totalDays += d.day - 1;
    return totalDays;
}

int distanceToStartOfYear(const Date& d)
{
    int days = 0;
    for (int m = 1; m < d.month; ++m) {
        days += daysInMonth(m, d.year);
    }
    days += d.day - 1;
    return days;
}

long long distanceTo1970(const Date& d)
{
    return countTotalDaysSince1970(d);
}

long long distanceBetweenDates(const Date& d1, const Date& d2)
{
    return abs(countTotalDaysSince1970(d2) - countTotalDaysSince1970(d1));
}

// 1/1/1970 Thursday
std::string getDayOfWeek(const Date& d)
{
    std::string weekDay[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    long long days = countTotalDaysSince1970(d);
    int offset = (days + 3) % 7;
    return weekDay[offset];
}

Date getTodayDate()
{
    time_t now = time(0);
    tm ltm;
    
#ifdef _WIN32
    localtime_s(&ltm, &now);
#else
    localtime_r(&now, &ltm);
#endif
    
    Date today;
    today.year = 1900 + ltm.tm_year;
    today.month = 1 + ltm.tm_mon;
    today.day = ltm.tm_mday;
    return today;
}

Date calculateAge(const Date& dob)
{
    Date age;
    Date today = getTodayDate();
    
    age.day = today.day - dob.day;
    age.month = today.month - dob.month;
    age.year = today.year - dob.year;
    
    if (age.day < 0) {
        --age.month;
        int prevMonth, prevMonthYear;
        
        if (today.month == 1) {
            prevMonth = 12;
            prevMonthYear = today.year - 1;
        } else {
            prevMonth = today.month - 1;
            prevMonthYear = today.year;
        }
        
        age.day += daysInMonth(prevMonth, prevMonthYear);
    }
    if (age.month < 0) {
        --age.year;
        age.month += 12;
    }
    
    return age;
}
