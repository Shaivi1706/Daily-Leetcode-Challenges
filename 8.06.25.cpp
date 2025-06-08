//Leetcode ques 386

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;

        //to iterate in n
        int temp=1;

        for(int i=0; i<n; i++) {
            result.push_back(temp);

            if(temp*10<=n) {
                //this brings 10,11,12...
                temp=temp*10;
            }
            else {
                if(temp>=n) {
                    //this resets the value to 1 
                    temp=temp/10;
                }
                //this will either make 12->13 or 1->2 based on above condition
                temp++;

                //using while and not if here for 3 or more digit numbers. 
                //used for cases like n=34
                while(temp%10==0) {
                    temp=temp/10;
                }
            }
        }
        return result;
    }
};

________________________________________________________________________________________________

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
