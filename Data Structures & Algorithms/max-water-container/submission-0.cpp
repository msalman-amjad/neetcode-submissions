class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea=INT_MIN;
        int l=0,r=heights.size()-1;
        while(l<r)
        {
            int curr_width=r-l;
            int curr_height=min(heights[l],heights[r]);
            int curr_area=curr_height*curr_width;
            maxArea=max(maxArea,curr_area);
            if (heights[l]<heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxArea;
        
    }
};
