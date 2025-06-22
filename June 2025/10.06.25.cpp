// Leetcode ques 3442

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;

        for(int i=0; i<s.size(); i++) {
            char c=s[i];
            mp[c]++;
        }

        int maxOdd=0;
        int minEven=INT_MAX;

        for(auto i:mp) {
            if(i.second%2==0 && i.second<minEven) {
                //even 
                minEven=i.second;
            }
            else if(i.second%2!=0 && i.second>maxOdd) {
                //odd
                maxOdd=i.second;
            }
        }

        return maxOdd-minEven;
    }
};
