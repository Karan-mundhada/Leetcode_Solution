class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        int win = 0;
        vector<int> ans(n, 0);
        if(k == 0)
        {
            return code = vector<int> (n, 0);
        }
        else if(k > 0)
        {
            for(int i=1; i<=k; i++)
            {
                win += code[(i%n)];
            }
            for(int i=0; i<n; i++)
            {
                ans[i] = win;
                win += code[(i+k+1)%n] - code[(i+1)%n];
            }
        }
        else
        {
            k = -k;
            // for(int i=n-1; i>=n-k; i--)
            // {
            //     win += code[(i%n)];
            // }
            // for(int i=0; i<n; i++)
            // {
            //     ans[i] = win;
            //     win += code[(i)%n] ;
            // }
            int wsum=accumulate(code.end()-k , code.end(), 0);
        ans[0]=wsum;
        for(int r=0, l=n-k; r<n-1; r++, l++){
            wsum+=-code[l%n]+code[r];
            ans[r+1]=wsum;
        }
        }

        return ans;
    }
};