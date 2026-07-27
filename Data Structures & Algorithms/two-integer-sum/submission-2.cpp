#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map to store: <number_value, original_index>
        unordered_map<int, int> numMap; 
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Step 1: Check if the complement already exists in our map
            if (numMap.find(complement) != numMap.end()) {
                // We found a match! Return the stored index and current index
                return {numMap[complement], i};
            }
            
            // Step 2: Otherwise, store the current number and its index
            numMap[nums[i]] = i;
        }
        
        return {}; // Return empty vector if no solution is found
    }
};