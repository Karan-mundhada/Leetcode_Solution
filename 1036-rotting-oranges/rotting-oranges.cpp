class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int tot = 0, cnt = 0, days = 0;
        queue<pair<int, int>> qq;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2) qq.push({i, j});
            }
        }

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while(!qq.empty())
        {
            int s = qq.size();
            cnt += s;
            while(s--)
            {
                int x = qq.front().first, y = qq.front().second, nx, ny;
                qq.pop();
                for(int h=0; h<4; h++)
                {
                    nx = x + dx[h];
                    ny = y + dy[h];
                    if(nx < 0 || ny < 0 || ny >= m || nx >= n || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    qq.push({nx, ny});
                }
            }
            if(!qq.empty()) days++;
        }

        return (tot == cnt) ? days : -1; 
    }
};