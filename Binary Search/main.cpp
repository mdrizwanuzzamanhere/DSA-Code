#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int binarySearch(vector<int>& nums, int target) {
        int n = nums.size();  // size of the array
        int low = 0, high = n - 1;

        // Perform the steps:
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;
            else if (target > nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    int searchInsertPosition(vector<int>& arr, int x) {
        int n = arr.size();  // size of the array
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] >= x) {
                ans = mid;
                // look for smaller index on the left
                high = mid - 1;
            } else {
                low = mid + 1;  // look on the right
            }
        }
        return ans;
    }

    int findFloor(int arr[], int n, int x) {
        int low = 0, high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] <= x) {
                ans = arr[mid];
                // look for smaller index on the left
                low = mid + 1;
            } else {
                high = mid - 1;  // look on the right
            }
        }
        return ans;
    }

    int findCeil(int arr[], int n, int x) {
        int low = 0, high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] >= x) {
                ans = arr[mid];
                // look for smaller index on the left
                high = mid - 1;
            } else {
                low = mid + 1;  // look on the right
            }
        }
        return ans;
    }

    int firstOccurrence(vector<int>& arr, int n, int k) {
        int low = 0, high = n - 1;
        int first = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] == k) {
                first = mid;
                // look for smaller index on the left
                high = mid - 1;
            } else if (arr[mid] < k) {
                low = mid + 1;  // look on the right
            } else {
                high = mid - 1;  // look on the left
            }
        }
        return first;
    }

    int lastOccurrence(vector<int>& arr, int n, int k) {
        int low = 0, high = n - 1;
        int last = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] == k) {
                last = mid;
                // look for larger index on the right
                low = mid + 1;
            } else if (arr[mid] < k) {
                low = mid + 1;  // look on the right
            } else {
                high = mid - 1;  // look on the left
            }
        }
        return last;
    }

    bool searchInRotatedSortedArray(vector<int>& arr, int k) {
        int n = arr.size();  // size of the array.
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;

            // if mid points the target
            if (arr[mid] == k)
                return true;

            // Edge case:
            if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
                low = low + 1;
                high = high - 1;
                continue;
            }

            // if left part is sorted:
            if (arr[low] <= arr[mid]) {
                if (arr[low] <= k && k <= arr[mid]) {
                    // element exists:
                    high = mid - 1;
                } else {
                    // element does not exist:
                    low = mid + 1;
                }
            } else {  // if right part is sorted:
                if (arr[mid] <= k && k <= arr[high]) {
                    // element exists:
                    low = mid + 1;
                } else {
                    // element does not exist:
                    high = mid - 1;
                }
            }
        }
        return false;
    }

    int findMinimumInRotatedSortedArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        int ans = INT_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;
            // search space is already sorted
            // then arr[low] will always be
            // the minimum in that search space:
            if (arr[low] <= arr[high]) {
                ans = min(ans, arr[low]);
                break;
            }

            // if left part is sorted:
            if (arr[low] <= arr[mid]) {
                // keep the minimum:
                ans = min(ans, arr[low]);

                // Eliminate left half:
                low = mid + 1;
            } else {  // if right part is sorted:

                // keep the minimum:
                ans = min(ans, arr[mid]);

                // Eliminate right half:
                high = mid - 1;
            }
        }
        return ans;
    }

    int singleElement(vector<int>& arr) {
        int n = arr.size();  // size of the array.

        // Edge cases:
        if (n == 1)
            return arr[0];
        if (arr[0] != arr[1])
            return arr[0];
        if (arr[n - 1] != arr[n - 2])
            return arr[n - 1];

        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = (low + high) / 2;

            // if arr[mid] is the single element:
            if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
                return arr[mid];
            }

            // we are in the left:
            if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) ||
                (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
                // eliminate the left half:
                low = mid + 1;
            }
            // we are in the right:
            else {
                // eliminate the right half:
                high = mid - 1;
            }
        }

        // dummy return statement:
        return -1;
    }

    int findPeakElement(vector<int>& arr) {
        int n = arr.size();  // Size of array.

        // Edge cases:
        if (n == 1)
            return 0;
        if (arr[0] > arr[1])
            return 0;
        if (arr[n - 1] > arr[n - 2])
            return n - 1;

        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = (low + high) / 2;

            // If arr[mid] is the peak:
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
                return mid;

            // If we are in the left:
            if (arr[mid] > arr[mid - 1])
                low = mid + 1;

            // If we are in the right:
            // Or, arr[mid] is a common point:
            else
                high = mid - 1;
        }
        // Dummy return statement
        return -1;
    }

    int squareRoot(int n) {
        int low = 1;
        int high = n;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long val = mid * mid;

            if (val <= (long long)n) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return high;
    }

    int sumByDivision(vector<int>& arr, int div) {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ceil((double)(arr[i]) / (double)(div));
        }

        return sum;
    }

    int findSmallestDivisor(vector<int>& arr, int limit) {
        int low = 1, high = *max_element(arr.begin(), arr.end());
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (sumByDivision(arr, mid) <= limit) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    bool searchIn2DMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        // apply binary search:
        int low = 0, high = n * m - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int row = mid / m, col = mid % m;
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};