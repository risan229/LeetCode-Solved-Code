//Copy From ChatGPT//
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        // Create a table to store palindrome information
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int maxLength = 1;  // Initialize the maximum length of a palindrome substring
        int startIdx = 0;   // Initialize the starting index of the longest palindrome substring

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Check for palindromes of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                maxLength = 2;
                startIdx = i;
            }
        }

        // Check for palindromes of length 3 or more
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1; // Ending index of current substring

                // Check if the current substring is a palindrome
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    if (len > maxLength) {
                        maxLength = len;
                        startIdx = i;
                    }
                }
            }
        }

        // Extract and return the longest palindrome substring
        return s.substr(startIdx, maxLength);
    }
};
