class Solution {
public:
    string robotWithString(string s) {
        stack<char> st;
        string res;

        vector<char> minSuffix(s.size());
        minSuffix[s.size() - 1] = s.back();
        for(int i = s.size() - 2; i >= 0; i--) {
            minSuffix[i] = min(s[i], minSuffix[i + 1]);
        }

        for(int i=0; i<s.size(); i++) {
            st.push(s[i]);

            while(!st.empty() && (i == s.size()-1 || st.top() <= minSuffix[i+1])) {
                res += st.top();
                st.pop();
            }
        }

        while(!st.empty()) {
            res+=st.top();
            st.pop();
        }
        return res;
    }
};
