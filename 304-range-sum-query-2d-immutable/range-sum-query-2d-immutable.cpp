class NumMatrix {
public:
    vector<vector<int>> matrix;
    NumMatrix(vector<vector<int>>& matrix1) {
        matrix = matrix1;
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=1; j<matrix[i].size(); j++)
            {
                matrix[i][j] = matrix[i][j] + matrix[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int s = 0;
        for(int i=row1; i<=row2; i++)
        {
            if(col1 == 0)
                s += matrix[i][col2];
            else
                s += matrix[i][col2] - matrix[i][col1-1];
        }

        return s;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */