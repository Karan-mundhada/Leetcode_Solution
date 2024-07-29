// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         vector<int> leftsmall(n); vector<int> rightsmall(n);
//         stack<int> s;
//         for(int i=0; i<n; i++)
//         {
//             if(!s.empty() && heights[s.top()] >= heights[i])
//                 s.pop();

//             leftsmall[i] = s.empty() ? 0 : s.top() + 1;
//             s.push(i);
//         }
//         while(!s.empty()) 
//             s.pop();

//         for(int i=n-1; i>=0; i--)
//         {
//             if(!s.empty() && heights[s.top()] >= heights[i])
//                 s.pop();

//             rightsmall[i] = s.empty() ? (n-1) : s.top() - 1;
//             s.push(i);
//         }
//         int mxh = 0;
//         for(int i=0; i<n; i++)
//         {
//             mxh = max(mxh, (rightsmall[i] - leftsmall[i] + 1)*heights[i]);
//         }

//         return mxh;
//     }
// };

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftsmall(n), rightsmall(n);
        stack<int> s;

        // Fill leftsmall array
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            leftsmall[i] = s.empty() ? 0 : s.top() + 1;
            s.push(i);
        }

        // Clear the stack to reuse it for rightsmall
        while (!s.empty())
            s.pop();

        // Fill rightsmall array
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            rightsmall[i] = s.empty() ? (n - 1) : s.top() - 1;
            s.push(i);
        }

        // Calculate the maximum area
        int mxh = 0;
        for (int i = 0; i < n; i++) {
            mxh = max(mxh, (rightsmall[i] - leftsmall[i] + 1) * heights[i]);
        }

        return mxh;
    }
};
