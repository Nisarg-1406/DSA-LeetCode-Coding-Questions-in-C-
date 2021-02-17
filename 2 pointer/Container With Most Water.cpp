    int maxArea(vector<int>& height) {
        int area = 0, lo = 0, hi = height.size() - 1;
        while(lo < hi) {
            area = max(area, min(height[lo], height[hi]) * (hi - lo));
            if(height[lo] <= height[hi]) lo++;
            else hi--;
        }
        return area;
    }
