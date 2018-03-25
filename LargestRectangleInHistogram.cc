class Solution {
public:
    int getArea(vector<int>& heights, int xIndex)
    {
        int count = 1;
        
        
        if(xIndex != 0 && xIndex != heights.size() - 1)
        {        
            for(int i = xIndex - 1; i >= 0; i--)
            {
                if(heights[i] >= heights[xIndex])
                    count++;
                else
                    break;
            }
            
            
            for(int i = xIndex + 1; i < heights.size(); i++)
            {
                if(heights[i] >= heights[xIndex])
                    count++;
                else
                    break;
            }
        }
        
        else if(xIndex == 0)
        {
            for(int i = 1; i < heights.size(); i++)
            {
                if(heights[i] >= heights[xIndex])
                    count++;
                else
                    break;
            }
        }
        
        else if(xIndex == heights.size() - 1)
        {
            for(int i = heights.size() - 2; i >= 0; i--)
            {
                if(heights[i] >= heights[xIndex])
                    count++;
                else
                    break;
            }
        }
        
        return count;
        
    }
    int largestRectangleArea(vector<int>& heights) {
        
        if(heights.size() <= 0)
            return 0;
        
        if(heights.size() == 1)
            return heights[0];
        
        
        int maxArea = heights[0] * getArea(heights, 0);
        
        for(int i = 1; i < heights.size(); i++)
        {
            if(maxArea < heights[i] * getArea(heights, i))
                maxArea = heights[i] * getArea(heights, i);
        }
            // cout << heights[i] * getArea(heights, i) << "\n";
        
        return maxArea;
    }
};
 
