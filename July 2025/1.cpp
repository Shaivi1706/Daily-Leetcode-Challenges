// Leetcode : 3330. Find the Original Typed String I
// Easy

// Alice typed a word but may have accidentally held down a key once, causing one character group to have extra repeated letters.
// You’re given the final word string (with possible repetition).
// Return how many valid original strings she might have intended — assuming at most one key was held too long.

class Solution {
public:
    int possibleStringCount(string word) {
        int count=0;

        for(int i=0; i<word.size()-1; i++) {
            if(word[i]==word[i+1]) {
                count++;
            }
        }

        return count+1;
    }
};

TC = O(n)
SC = O(1)
