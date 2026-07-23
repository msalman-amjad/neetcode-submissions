class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) {
            return 0;
        }

        // Step 2: Insert all elements into a hash set
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        // Iterate through the unique numbers in the set
        for (int num : numSet) {
            // Step 3: Only start counting if 'num' is the start of a sequence
            // (meaning 'num - 1' is not in the set)
            if (numSet.find(num - 1) == numSet.end()) {
                
                int currentNum = num;
                int currentStreak = 1;

                // Step 4: Keep checking for the next consecutive numbers
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                // Step 5: Update the longest streak found so far
                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    
    
    }
};
