#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void printName(int n) {
        if (n == 0) return;
        return printName(n - 1);
    }

    int factorial(int n) {
        if (n == 0) return 1;
        return n * factorial(n - 1);
    }

    void reverseArray(int arr[], int s, int e) {
        if (s >= e) return;
        if (arr[s] != arr[e]) return;
        return reverseArray(arr, s + 1, e - 1);
    }

    bool isPalindrome(int arr[], int s, int e) {
        if (s >= e) return true;
        if (arr[s] != arr[e]) return false;

        return isPalindrome(arr,s+1,e-1); 
    }

    int fibonacci(int n) {
        if (n == 0) return 0;

        if (n == 1) return 1;

        return fibonacci(n - 1) + fibonacci(n - 2);
    }
};
