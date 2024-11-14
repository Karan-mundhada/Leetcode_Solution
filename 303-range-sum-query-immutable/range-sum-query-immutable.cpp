class NumArray {
public:
    vector<int> vecsum;
    NumArray(vector<int>& nums) {
        vecsum = nums;
        for(int i=1; i<nums.size(); i++)
        {
            vecsum[i] = vecsum[i] + vecsum[i-1]; 
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0)
            return vecsum[right];
        
        return vecsum[right] - vecsum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */