//
//  Functions.cpp
//  Learning
//
//  Created by Huy Nguyen on 10/11/25.
//

#include "Functions.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>

void replaceSubString(std::string& str, const std::string& from, const std::string& to)
{
    if (from.empty()) return;
    size_t start = 0;
    while ((start = str.find(from, start)) != std::string::npos) {
        str.replace(start, from.length(), to);
        start += to.length();
    }
}

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year)
{
    if (month == 2)
        return (isLeapYear(year)) ? 29 : 28;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else return 31;
}

std::string getFirstName(const std::string& fullName)
{
    std::stringstream ss(fullName);
    std::string firstName;
    ss >> firstName;
    return firstName;
}

std::string getLastName(const std::string& fullName)
{
    size_t firstSpace = fullName.find(' ');
    if (firstSpace == std::string::npos) return "";
    return fullName.substr(firstSpace + 1);
}

int reverse(int x) {
    int result = 0;
    while (x != 0) {
        if (result > INT_MAX / 10 || result < INT_MIN / 10) return 0;
        result = result * 10 + x % 10;
        x /= 10;
    }
    return result;
}

void inputList(std::vector<int>& nums)
{
    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;
    
    std::cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        int x; std::cin >> x;
        nums.push_back(x);
    }
}

void outputTriplets(const std::vector<std::vector<int>>& triplets)
{
    for (const auto& triplet : triplets) {
        std::cout << "[ ";
        for (auto x : triplet)
            std::cout << x << " ";
        std::cout << "]\n";
    }
}

std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> result;

    auto n = nums.size();
    for (int i = 0; i < n - 2; ++i)
    {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        auto left = i + 1;
        auto right = n - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum < 0) ++left;
            else if (sum > 0) --right;
            else
            {
                result.push_back({nums[i], nums[left], nums[right]});

                while (left < right && nums[left] == nums[left + 1]) ++left;
                while (left < right && nums[right] == nums[right - 1]) --right;

                ++left;
                --right;
            }
        }
    }
    return result;
}

int mySqrt(int x)
{
    if (x < 2) return x;

    int left = 1, right = x, answer = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if ((long long)mid * mid <= x) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return answer;
}
