#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() <= 1) return nums;
        vector<int> sortedArray = mergeSort(nums);
        return sortedArray;
    }

private:
    vector<int> mergeSort(const vector<int>& nums) {
        if (nums.size() <= 1) return nums;

        // Divide
        int mid = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());

        // Conquer
        left = mergeSort(left);
        right = mergeSort(right);

        // Merge
        return merge(left, right);
    }

    vector<int> merge(const vector<int>& left, const vector<int>& right) {
        vector<int> result;
        int i = 0, j = 0;

        // Merge the two sorted halves
        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                result.push_back(left[i++]);
            } else {
                result.push_back(right[j++]);
            }
        }

        // Add remaining elements
        while (i < left.size()) {
            result.push_back(left[i++]);
        }
        while (j < right.size()) {
            result.push_back(right[j++]);
        }

        return result;
    }
};
