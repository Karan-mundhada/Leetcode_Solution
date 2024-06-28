class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low;     
        int right = mid + 1;  

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    int countpair(vector<int>& nums, int low, int mid, int hi)
    {
        int right = mid + 1;
        int cunt = 0;
        for(int i=low; i<=mid; i++)
        {
            while(right <= hi && nums[i] > (long long) 2*(long long)nums[right])
                right++;

            cunt += (right - (mid + 1));
        }
        return cunt;
    }

    int mergesort(vector<int>& nums, int low, int hi)
    {
        int cunt = 0;
        if(low >= hi) return 0;
        int mid = (low + hi) / 2;
        cunt += mergesort(nums, low, mid);
        cunt += mergesort(nums, mid+1, hi);
        cunt += countpair(nums, low, mid, hi);
        merge(nums, low, mid, hi);
        return cunt;
    }

    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size()-1);
    }
};

// for(int i=n-1; i>0; i--)
// {
//     long long t = (long long) 2 * nums[i];
//     for(int j=0; j<i; j++)
//     {
//         if(nums[j] > t)
//             cunt++;
//     }
// }

// return cunt;