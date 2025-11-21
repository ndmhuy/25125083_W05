//
//  Functions.hpp
//  Learning
//
//  Created by Huy Nguyen on 10/11/25.
//

#ifndef Functions_hpp
#define Functions_hpp

#include <iostream>
#include <vector>
#include <string>

void replaceSubString(std::string& str, const std::string& from, const std::string& to);
bool isLeapYear(int year);
int daysInMonth(int month, int year);
std::string getFirstName(const std::string& fullName);
std::string getLastName(const std::string& fullName);
int reverse(int x);
void inputList(std::vector<int>& nums);
void outputTriplets(const std::vector<std::vector<int>>& triplets);
std::vector<std::vector<int>> threeSum(std::vector<int>& nums);
int mySqrt(int x);

#endif /* Functions_hpp */
