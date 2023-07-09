#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        queue<int> kthQueue;

        kthQueue.push(nums[0]);
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] > kthQueue.front()) kthQueue.push(nums[i]);
            if(kthQueue.size() > k) kthQueue.pop();
        }

        return kthQueue.front();
    }
};


int main() {

    Solution sol;
    vector<int> nums = {2,1};
    cout << sol.findKthLargest(nums, 2);
    return 0;
}