// Leetcode 3333
//hard

class Solution {
    static const int MOD = 1e9 + 7;

public:
    int possibleStringCount(std::string word, int k) {
        if (word.empty()) return 0;

        // Step 1: Compressing into character groups
        std::vector<int> groups;
        int count = 1;

        for (size_t i = 1; i < word.size(); ++i) {
            if (word[i] == word[i - 1]) {
                count++;
            } else {
                groups.push_back(count);
                count = 1;
            }
        }
        groups.push_back(count); // Adding the last group

        // Step 2: Calculating total possible original strings
        long long total = 1;
        for (int len : groups) {
            total = (total * len) % MOD;
        }

        // If we already have enough groups to form length >= k, return total
        if (k <= (int)groups.size()) return total;

        // Step 3: Dynamic Programming to count invalid strings of length < k
        std::vector<int> dp(k, 0);  // dp[s] = # of ways to reach length s
        dp[0] = 1;

        for (int groupLen : groups) {
            std::vector<int> newDp(k, 0);
            long long windowSum = 0;

            for (int s = 0; s < k; ++s) {
                if (s > 0) windowSum = (windowSum + dp[s - 1]) % MOD;
                if (s > groupLen) windowSum = (windowSum - dp[s - groupLen - 1] + MOD) % MOD;
                newDp[s] = windowSum;
            }

            dp = newDp;
        }

        // Step 4: Counting all invalid strings (length < k)
        long long invalid = 0;
        for (int s = groups.size(); s < k; ++s) {
            invalid = (invalid + dp[s]) % MOD;
        }

        // Step 5: Subtracting invalid from total
        return (total - invalid + MOD) % MOD;
    }
};
