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
        if (s >= e) return true ;
        if(arr[s]!=arr[e]) return false ;

        
    }
};
