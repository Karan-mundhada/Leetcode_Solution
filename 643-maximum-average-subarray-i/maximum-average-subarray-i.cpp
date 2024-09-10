class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0;
        double sum = 0;
        for(int h = 0; h<k; h++)
            sum += nums[h];
        
        double avg = sum / (double) k; 
        for(int h=k; h<nums.size(); h++)
        {
            sum -= nums[i++];
            sum += nums[h];
            avg = max(avg, sum / (double) k);
        }

        return avg;
    }
};