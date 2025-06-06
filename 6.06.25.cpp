LeetCode problem 2434
    
    string robotWithString(string s) {
        //st is here t
        stack<char> st;
        string res;

        //this vector is to store min character at every point 
        // example for [bbaghe] => [aaaeee]
        vector<char> minSuffix(s.size());
        minSuffix[s.size() - 1] = s.back();
        for(int i = s.size() - 2; i >= 0; i--) {
            minSuffix[i] = min(s[i], minSuffix[i + 1]);
        }

        //running the loop
        for(int i=0; i<s.size(); i++) {
            st.push(s[i]);

            //if character that is recently inserted is less than or equal to min char for that portion
            while(!st.empty() && (i == s.size()-1 || st.top() <= minSuffix[i+1])) {
                res += st.top();
                st.pop();
            }
        }
        return res;
    }
