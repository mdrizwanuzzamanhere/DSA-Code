#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countDigits(int n) {
        int cnt = 0;

        while (n) {
            int digit = n % 10;
            cnt++;
            n = n / 10;
        }

        return cnt;
    }

    int reverseNumber(int n) {
        int rev = 0;
        while (n) {
            int digit = n % 10;
            rev = rev * 10 + digit;
            n = n / 10;
        }

        return rev;
    }

    bool checkPalindrome(int n) {
        int temp = n;
        int rev = 0;
        while (n) {
            int digit = n % 10;
            rev = rev * 10 + digit;
            n = n / 10;
        }

        return rev == temp;
    }

    int findGcd(int a, int b) {
        int gcd;
        for (int i = 1; i <= a && i <= b; i++) {
            if (a % i == 0 && b % i == 0) {
                gcd = i;
            }
        }

        return gcd;
    }

    int armstrong(int n) {
        int temp = n;
        int sum = 0;
        while (n != 0) {
            int digit = n % 10;
            sum += digit * digit * digit;
            n = n / 10;
        }

        return sum == temp;
    }

    vector<int> printDivisors(int arr[], int n) {
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (n % i == 0) {
                ans.push_back(i);
                if (i != n / i) {
                    ans.push_back(n / i);
                }
            }
        }

        return ans;
    }

    bool isPrime(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

    
};