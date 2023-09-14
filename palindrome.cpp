//Copy From ChatGPT//
class Solution {
public:
    bool isPalindrome(int x) {
        // If x is negative or ends with a zero (except when x is 0), it can't be a palindrome
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        // When the length of x is odd, we can ignore the middle digit
        return x == reversed || x == reversed / 10;
    }
};
