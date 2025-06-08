class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> result(n);

        for(int i=1; i<=n; i++) {
            result[i-1]=to_string(i);
        }

        sort(result.begin(), result.end());

        vector<int> ans(n);
        for(int i=0; i<n; i++) {
            ans[i]=stoi(result[i]);
        }
        
        return ans;
    }
};
