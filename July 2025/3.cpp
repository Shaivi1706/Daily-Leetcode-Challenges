//Leetcode 3304
class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while (s.length() < k) {
            int size = s.length();
            for (int i = 0; i < size; ++i) {
                char nextChar = 'a' + ((s[i] - 'a' + 1) % 26);
                s += nextChar;
            }
        }
        return s[k - 1];
    }
};
