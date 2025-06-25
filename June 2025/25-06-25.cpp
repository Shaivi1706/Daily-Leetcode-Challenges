// BRUTE FORCE APPROACH

//LEETCODE POTD 2040. (could not optimize)

class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        vector<long long> ans;


        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++) {
                long long in=(long long) nums1[i]*nums2[j];
                ans.push_back(in);
            }
        }

        sort(ans.begin(), ans.end());
        return ans[k-1];
    }
};
