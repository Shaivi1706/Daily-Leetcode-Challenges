// Leetcode problem 3445

//wasn't able to optimize the solution to remove tle

//this solution is without tle from solutions of other people
class Solution 
{
public:
    int maxDifference(string s, int k) 
    {
        int n = s.size();
        int ans = INT_MIN;

        // Step 1: Try all (a, b) pairs
        for (int a = 0; a <= 4; ++a) 
        {
            for (int b = 0; b <= 4; ++b) 
            {
                if (a == b)
                {
                    continue;
                } 

                vector<int> s1(n + 1);
                vector<int> s2(n + 1);
                
                // Step 2: Prefix counts
                for (int i = 1; i <= n; ++i) 
                {
                    s1[i] = s1[i - 1] + (s[i - 1] - '0' == a);
                    s2[i] = s2[i - 1] + (s[i - 1] - '0' == b);
                }

                // Step 3: Matrix for best difference at each parity
                int g[2][2] = {{INT_MIN, INT_MIN}, {INT_MIN, INT_MIN}};
                int j = 0;

                // Step 4: Sliding window
                for (int i = k; i <= n; ++i) 
                {
                    while (i - j >= k && s1[i] > s1[j] && s2[i] > s2[j]) 
                    {
                        int pa = s1[j] % 2;
                        int pb = s2[j] % 2;
                        g[pa][pb] = max(g[pa][pb], s2[j] - s1[j]);
                        ++j;
                    }

                    // Step 5: Check if valid
                    int pa = s1[i] % 2;
                    int pb = s2[i] % 2;
                    int need = g[1 - pa][pb];
                    
                    if (need != INT_MIN) 
                    {
                        ans = max(ans, (s1[i] - s2[i]) + need);
                    }
                }
            }
        }

        if(ans==INT_MIN) return -1;
        return ans;
    }
};

____________________________________________________________________________

//tle solution 

class Solution {
    vector<string> substring(string s) {
        vector<string> substrings;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 1; j <= s.size() - i; ++j) {
                substrings.push_back(s.substr(i, j));
            }
        }
        return substrings;
    }

    int mapping(string s) {
        unordered_map<char, int> mp;

        for(int i=0; i<s.size(); i++) {
            mp[s[i]]++;
        }

        int maxOdd=0;
        int minEven=INT_MAX;

        for(auto &i:mp) {
            if(i.second%2!=0) {
                maxOdd=max(maxOdd, i.second);
            }
            else {
                minEven=min(minEven, i.second);
            }
            
        }

        return maxOdd-minEven;
    }
public:
    int maxDifference(string s, int k) {
        if(k>s.size()) return -1;

        vector<string> sub=substring(s);

        int ans=INT_MIN;

        for(int i=0; i<sub.size(); i++) {
            if(sub[i].size()<k) continue;

            int diff=mapping(sub[i]);
            ans=max(ans, diff);
        }

        if(ans==INT_MIN) return -1;
        return ans;
    }
};

