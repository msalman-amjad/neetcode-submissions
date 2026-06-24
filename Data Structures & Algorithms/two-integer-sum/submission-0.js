class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number[]}
     */
    twoSum(nums, target) {
        // 1. Initialize your empty Hash Map
        let mymap = {};
        
        // 2. Set up the loop to go through the array one by one
        for (let i = 0; i < nums.length; i++) {
            
            // 3. Calculate what number we need to reach the target
            let diff = target - nums[i];
            
            // 4. Check if we have already seen the needed number
            if (diff in mymap) {
                // Match found! Return the index from the map AND the current index 'i'
                return [mymap[diff], i];
            }
            
            // 5. If not found, push the CURRENT number and its index into the map
            mymap[nums[i]] = i;
        }

        // If the loop finishes without finding anything, return an empty array.
        // (Though the problem guarantees there will always be exactly one solution!)
        return [];
    }
        
}
