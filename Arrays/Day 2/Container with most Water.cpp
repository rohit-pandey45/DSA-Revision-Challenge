/**
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int max_water = 0;
        while(left<right){
            int heights = min(height[left],height[right]);
            int width = right - left;
            int area = heights*width;
            max_water = max(max_water, area);
            if(height[left]<=height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return max_water;
    }
};
 */