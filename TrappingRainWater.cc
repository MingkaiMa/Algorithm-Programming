class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2)
            return 0;

        int leftMax;
        int rightMax;




        int countCube = 0;

        for(int i = 1; i < height.size() - 1; i++)
        {

            leftMax = i - 1;
            rightMax = i + 1;

            for(int j = i - 1; j >= 0; j--)
            {
                if(height[j] > height[leftMax])
                {
                    leftMax = j;
                }
            }


            for(int j = i + 1; j < height.size(); j++)
            {
                if(height[j] > height[rightMax])
                {
                    rightMax = j;
                }

            }

            if(height[i] < height[leftMax] && height[i] < height[rightMax])
            {
                // cout << "i is: " << i << "height is: " << min(height[left], height[right]) - height[i] << "\n";
                // cout << "left is: " << left << " right is: " << right << "\n";
                countCube += min(height[leftMax], height[rightMax]) - height[i];

            }

        }

        return countCube;

    }
};