#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void selectionSort(vector<int>& arr) {
        int n = arr.size();

        for (int i = 0; i < n - 1; ++i) {
            // Assume the current position holds
            // the minimum element
            int min_idx = i;

            // Iterate through the unsorted portion
            // to find the actual minimum
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] < arr[min_idx]) {
                    // Update min_idx if a smaller
                    // element is found
                    min_idx = j;
                }
            }

            // Move minimum element to its
            // correct position
            swap(arr[i], arr[min_idx]);
        }
    }

    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        bool swapped;

        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }

            // If no two elements were swapped, then break
            if (!swapped)
                break;
        }
    }

    void insertionSort(int arr[], int n) {
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;

            /* Move elements of arr[0..i-1], that are
               greater than key, to one position ahead
               of their current position */
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
};