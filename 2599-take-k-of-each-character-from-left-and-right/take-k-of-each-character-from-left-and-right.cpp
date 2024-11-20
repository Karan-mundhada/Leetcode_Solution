class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        if (k == 0) return 0; // No need to take any characters

        // Count total occurrences of 'a', 'b', 'c'
        int totalA = 0, totalB = 0, totalC = 0;
        for (char ch : s) {
            if (ch == 'a') totalA++;
            else if (ch == 'b') totalB++;
            else totalC++;
        }

        // If any character count is less than k, it's impossible to satisfy the condition
        if (totalA < k || totalB < k || totalC < k) return -1;

        // Sliding window to find the maximum segment that can remain in the middle
        int requiredA = totalA - k, requiredB = totalB - k, requiredC = totalC - k;
        int currA = 0, currB = 0, currC = 0;
        int maxWindow = 0; // Maximum size of the valid window

        int left = 0;
        for (int right = 0; right < n; right++) {
            // Add the current character to the window
            if (s[right] == 'a') currA++;
            else if (s[right] == 'b') currB++;
            else currC++;

            // Shrink the window from the left if it exceeds the requirements
            while (currA > requiredA || currB > requiredB || currC > requiredC) {
                if (s[left] == 'a') currA--;
                else if (s[left] == 'b') currB--;
                else currC--;
                left++;
            }

            // Update the maximum valid window size
            maxWindow = max(maxWindow, right - left + 1);
        }

        // Total minutes = total characters - size of the largest valid window
        return n - maxWindow;
    }
};
