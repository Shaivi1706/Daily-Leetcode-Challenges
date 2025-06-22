// Leetcode 3423. Maximum Difference Between Adjacent Elements in a Circular Array

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int diff=0;

        for(int i=0; i<nums.size()-1; i++) {
            diff=max(diff, abs(nums[i]-nums[i+1]));
        }

        diff = max(diff, abs(nums[0]-nums[nums.size()-1]));

        return diff;
    }
};
