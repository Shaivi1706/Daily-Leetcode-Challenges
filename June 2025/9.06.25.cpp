//Leetcode ques 440

class Solution {
//this function is crucial as to count lexigraphical numbers between two consecutive numbers
//long here is used to avoid memory limit error
    long countSteps(long n, long num, long next) {
        long steps=0;

      // if we have n=15 and num=1 and next=2 => steps = 1+5 = 6
        while(num<=n) {
            steps+=min(n+1, next)-num;
            num=num*10;
            next=next*10;
        }
        return steps;
    }
public:
    int findKthNumber(int n, int k) {
        long num=1;
        k--;
      //we have already considered 1, so k--
        while(k>0) {
            long steps=countSteps(n, num, num+1);
      // if there are enough steps to cover 1 then we will not got under that list
            if(steps<=k) {
                //skip this
                num+=1;
                k-=steps;
            }
              //if steps are not sufficient, then we will search under that list
            else {
                //go deep
                num=num*10;
                k-=1;
            }
        }
        return num;
    }
};


In this question, if we will use any data structure to store, we will get memory limit error. So we have used trie implication. Here we ge into
lexicographical list of that number only if k will be inside that list, otherwise we ignore it.
