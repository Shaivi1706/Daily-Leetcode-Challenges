//Leetcode ques 3170

//optimized and accepted soln
class Solution {
public:
    string clearStars(string s) {
        //using min-heap, map and vector to track
        //min heap will automatically store smallest element on left side
        priority_queue<int, vector<int>, greater<int>> pq;
        //map is used to store the index at which a character is stored
        unordered_map<int, vector<int>> mp;
        //if the character is to be not included in final ans, then it's index will be marked false
        vector<bool> visit(s.size(), true);

        for(int i=0; i<s.size(); i++) {
            if(s[i]=='*') {
                char temp = pq.top(); //getting the smallest element
                pq.pop();

                //getting the index at which smallest element is present
                int last = mp[temp].back();

                //removing that index
                mp[temp].pop_back();

                //updating the vector
                visit[last] = false;
                visit[i]=false;
            }
            else {
                //pushing the character in min heap/priority queue and then pushing back the index in map
                pq.push(s[i]);
                mp[s[i]].push_back(i);
            }
        }

        string result="";
        for(int i=0; i<s.size(); i++) {
            if(visit[i]) result+=s[i];
        }

        return result;
    }
};

_____________________________________________

//soln tried but not accepted (brute)

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
