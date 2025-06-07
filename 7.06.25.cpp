//Leetcode ques 3170

class Solution {
public:
    string clearStars(string s) {
      //using stack
        vector<char> st;

        for (char ch : s) {
            if (ch != '*') {
                st.push_back(ch);
            } else {
                if (!st.empty()) {
                    // Find smallest char in stack
                    int idx = 0;
                    for (int i = 1; i < st.size(); i++) {
                        if (st[i] <= st[idx]) {
                            idx = i;
                        }
                    }
                    // Remove the smallest
                    st.erase(st.begin() + idx);
                }
            }
        }

        // Build final string
        string res = "";
        for (char ch : st) {
            res += ch;
        }
        return res;
    }
};


TLE at 601/602
