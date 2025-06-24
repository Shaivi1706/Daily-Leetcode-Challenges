class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> j;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==key) j.push_back(i);
        }

        vector<int> ans;

        for(int i=0; i<nums.size(); i++) {
            for(int a=0; a<j.size(); a++) {
                if(k>=abs(i-j[a])) {
                    ans.push_back(i);
                    break;
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
