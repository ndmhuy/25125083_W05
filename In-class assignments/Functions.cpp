//
//  Functions.cpp
//  Learning
//
//  Created by Huy Nguyen on 10/11/25.
//

#include <iostream>

int gcd(int a, int b)
{
    a = std::abs(a);
    b = std::abs(b);
    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    return a;
}

long long sumOfSquared(int n)
{
    long long sum = 0LL;
    for (int i = 1; i <= n; ++i) sum += i * i;
    
    return sum;
}

void listAllDivisors(int n)
{
    std::vector<int> largeDivs;
    
    // Loop to sqrt(n) since if i is divisor then n / i is an another divisor.
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            std::cout << i << ' ';
            if (i != n / i) largeDivs.push_back(n / i); // Store to print every divisors in ascending order.
        }
    }
    
    // Print in ascending order the n / i divisors.
    for (int i = (int)largeDivs.size() - 1; i >= 0; i--) {
        std::cout << largeDivs[i] << ' ';
    }
    std::cout << '\n';
}

int divisorsCount(int n)
{
    int div = 1, i = 2, current = 0;
    // if n = p1^n1 * p2^n2 * ... (p is prime) then its number of divisors = (n1 + 1)(n2 + 1)...
    while (n > 1) {
        if (n % i == 0) {
            ++current;
            n /= i;
        }
        else {
            if (i == 2) ++i; else i += 2;
            if (current > 0) {
                div *= current + 1;
                current = 0;
            }
            if (1LL * i * i > n) i = n; // then current n is a prime
        }
    }
    div *= current + 1;
    
    return div;
}
