#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void countFreq(int arr[], int n) {
        int cnt = 0;

        unordered_map<int, int> m;

        for (int i = 0; i < n; i++) {
            m[arr[i]]++;
        }

        for (auto it : m) {
            cout << it.first << " " << it.second << endl;
        }
    }

    void indexElementMapping(int arr[], int n) {
        unordered_map<int, int> m;

        for (int i = 0; i < n; i++) {
            m[arr[i]] = i;
        }

        for (auto it : m) {
            cout << it.first << " " << it.second << endl;
        }
    }
};