#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findLargest(int arr[], int n) {
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (maxi < arr[i]) {
                maxi = arr[i];
            }
        }
        return maxi;
    }

    int findSecondLargest(int arr[], int n) {
        int maxi = INT_MIN;
        int smaxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (maxi < arr[i]) {
                maxi = arr[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (maxi != arr[i] && arr[i] > smaxi) {
                smaxi = arr[i];
            }
        }

        return smaxi;
    }

    bool checkForRotatedSortedArray(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;

        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                cnt++;  // cnt=1
            }
        }

        // rotation condition
        if (arr[n - 1] > arr[0]) cnt++;

        if (cnt <= 1) {
            return true;
        }

        return false;
    }

    int removeDuplicates(vector<int>& arr) {
        int j = 0;  // size of new array
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] != arr[j]) {
                arr[j + 1] = arr[i];
                j++;
            }
        }

        return j + 1;
    }

    void reverseArray(vector<int>& nums, int start, int end) {
        int n = nums.size();

        while (start <= end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverseArray(nums, 0, n - 1);
        reverseArray(nums, 0, k - 1);
        reverseArray(nums, k, n - 1);
    }

    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }

    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int s = (n * n + n) / 2;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        return s - sum;
    }

    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                cnt++;
            else
                cnt = 0;

            maxi = max(maxi, cnt);
        }

        return maxi;
    }

    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = ans ^ nums[i];
        }

        return ans;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            int more = target - nums[i];
            if (m.find(more) != m.end()) {
                return {m[more], i};
            }

            m[nums[i]] = i;
        }

        return {-1, -1};
    }

    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int low = 0;
        int mid = 0;
        int high = n - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }

            else if (nums[mid] == 1)
                mid++;

            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }

    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int el = 0;
        for (int num : nums) {
            if (cnt == 0) el = num;
            if (num == el)
                cnt++;
            else
                cnt--;
        }

        return el;
    }

    int kadanesAlgorithm(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (maxi < sum) maxi = sum;
            if (sum < 0) sum = 0;
        }

        return maxi;
    }

    int bestTimetoBuyAndSellStock(vector<int>& arr) {
        int maxi = 0;
        int mini = INT_MAX;

        for (int i = 0; i < arr.size(); i++) {
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i] - mini);
        }

        return maxi;
    }

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        if (ind == -1) {
            reverse(nums.begin(), nums.end());
        }

        else {
            for (int i = n - 1; i > ind; i--) {
                if (nums[i] > nums[ind]) {
                    swap(nums[i], nums[ind]);
                    break;
                }
            }

            reverse(nums.begin() + ind + 1, nums.end());
        }
    }

    int longestConsecutive(vector<int>& a) {
        int n = a.size();
        if (n == 0) return 0;

        int longest = 1;
        unordered_set<int> st;
        // put all the array elements into set:
        for (int i = 0; i < n; i++) {
            st.insert(a[i]);
        }

        // Find the longest sequence:
        for (auto it : st) {
            // if 'it' is a starting number:
            if (st.find(it - 1) == st.end()) {
                // find consecutive numbers:
                int cnt = 1;
                int x = it;
                while (st.find(x + 1) != st.end()) {
                    x = x + 1;
                    cnt = cnt + 1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int col = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if (j != 0)
                        matrix[0][j] = 0;
                    else
                        col = 0;
                }
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] != 0) {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        if (col == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }

    void rotateImage(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res(m * n);
        int j = 0;
        int l = 0, u = 0, d = m - 1, r = n - 1;

        while (l <= r && u <= d) {
            // Traverse from left to right
            if (l <= r && u <= d) {
                for (int i = l; i <= r; i++) {
                    res[j++] = matrix[u][i];
                }
                u++;
            }

            // Traverse from top to bottom
            if (l <= r && u <= d) {
                for (int i = u; i <= d; i++) {
                    res[j++] = matrix[i][r];
                }
                r--;
            }

            // Traverse from right to left
            if (l <= r && u <= d) {
                for (int i = r; i >= l; i--) {
                    res[j++] = matrix[d][i];
                }
                d--;
            }

            // Traverse from bottom to top
            if (l <= r && u <= d) {
                for (int i = d; i >= u; i--) {
                    res[j++] = matrix[i][l];
                }
                l++;
            }
        }

        return res;
    }

    int nCr(int n, int r) {
        long long res = 1;

        // calculating nCr:
        for (int i = 0; i < r; i++) {
            res = res * (n - i);
            res = res / (i + 1);
        }
        return (int)(res);
    }

    vector<vector<int>> pascalTriangle(int n) {
        vector<vector<int>> ans;

        // Store the entire pascal's triangle:
        for (int row = 1; row <= n; row++) {
            vector<int> tempLst;  // temporary list
            for (int col = 1; col <= row; col++) {
                tempLst.push_back(nCr(row - 1, col - 1));
            }
            ans.push_back(tempLst);
        }
        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) {
            // remove duplicates:
            if (i != 0 && arr[i] == arr[i - 1])
                continue;

            // moving 2 pointers:
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    // skip the duplicates:
                    while (j < k && arr[j] == arr[j - 1])
                        j++;
                    while (j < k && arr[k] == arr[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }

    vector<vector<int>> mergeIntervals(vector<vector<int>>& arr) {
        int n = arr.size();  // size of the array

        // sort the given intervals:
        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            // if the current interval does not
            // lie in the last interval:
            if (ans.empty() || arr[i][0] > ans.back()[1]) {
                ans.push_back(arr[i]);
            }
            // if the current interval
            // lies in the last interval:
            else {
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
        }
        return ans;
    }

    void mergeSortedArray(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }

    int maxProductSubarray(vector<int>& arr) {
        int n = arr.size();  // size of array.

        int pre = 1, suff = 1;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (pre == 0)
                pre = 1;
            if (suff == 0)
                suff = 1;
            pre *= arr[i];
            suff *= arr[n - i - 1];
            ans = max(ans, max(pre, suff));
        }
        return ans;
    }
};