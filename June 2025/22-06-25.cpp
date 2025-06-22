//LEETCODE POTD 2138

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;

        int i=0;
        int a=0;

        string st="";

        while(i<s.size()) {
            st+=s[i];
            i++;
            a++;
            if(a==k) {
                ans.push_back(st);
                st="";
                a=0;
            }
        }

        if(st.size()<k && st.size()!=0) {
            while(st.size()!=k) {
                st+=fill;
            }
            ans.push_back(st);
        }
        return ans;
    }
};
