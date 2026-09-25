class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0); // Stores frequency of characters in the current window
        int left = 0;
        int max_freq = 0; // Tracks the highest frequency of any single character in the window
        int max_len = 0;
        
        for (int right = 0; right < s.length(); right++) {
            // Add the new character to our window count
            count[s[right] - 'A']++;
            
            // Update the maximum frequency seen so far
            max_freq = max(max_freq, count[s[right] - 'A']);
            
            // Current window size
            int window_size = right - left + 1;
            
            // If replacements needed exceed k, the window is invalid. Shrink it from the left.
            if (window_size - max_freq > k) {
                count[s[left] - 'A']--;
                left++;
            }
            
            // Calculate the maximum valid window length found so far
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;  
    }
};
