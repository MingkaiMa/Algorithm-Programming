class NumArray {
public:
    NumArray(vector<int> nums) {
        lastChange = -1;
        
        array = nums;
        for(int i = 1; i < nums.size(); i++)
            array[i] += array[i - 1];
    }
    
    void update(int i, int val) {
        
        if(i == 0)
        {
            int original = array[0];
            int diff = val - original;
            array[i] = val;
            for(int j = 1; j < array.size(); j++)
                array[j] += diff;
        }
        
        else
        {
            int original = array[i] - array[i - 1];
            int diff = val - original;
            
            for(int j = i; j < array.size(); j++)
                array[j] += diff;
        }

    }
    
    int sumRange(int i, int j) {
        if(i == 0)
            return array[j];
        
        return array[j] - array[i - 1];
    }
private:
    vector<int> array;
    int lastChange;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
