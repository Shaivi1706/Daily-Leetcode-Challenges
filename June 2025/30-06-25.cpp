//Leetcode prob 594

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> mp;

        for(auto i:nums) {
            mp[i]++;
        }

        int count=0;

        for(auto i:mp) {
            if(mp.count(i.first+1)) {
                count=max(count, i.second+mp[i.first+1]);
            }
        }

        return count;
    }
};
