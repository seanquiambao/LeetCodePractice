#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int m = 0;

        while(left <= right) {
            m  = (left + right) / 2;

            if(nums[m] < target) left = m + 1;
            else if (nums[m] > target) right = m - 1;
            else return m;
        }
        return (nums[m] < target) ? m + 1 : m;
    }
};

int main() {

    Solution sol;
    vector<int> nums = {1,2,7,9,10,14};

    cout << "Case #0: "<< sol.searchInsert(nums, 1) << endl;
    cout << "Case #2: "<< sol.searchInsert(nums, 3) << endl;
    cout << "Case #4: "<< sol.searchInsert(nums, 4) << endl;
    cout << "Case #6: "<< sol.searchInsert(nums, 6) << endl;
    cout << "Case #8: "<< sol.searchInsert(nums, 8) << endl;
    cout << "Case #10: "<< sol.searchInsert(nums, 10) << endl;
    cout << "Case #12: "<< sol.searchInsert(nums, 14) << endl;

    
    return 0;
}