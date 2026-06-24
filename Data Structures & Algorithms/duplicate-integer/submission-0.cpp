class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> unique_elements(nums.begin(), nums.end());
        return unique_elements.size() < nums.size();

        
    }
};