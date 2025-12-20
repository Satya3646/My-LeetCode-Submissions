const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    void solve(vector <vector <char>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        vector <vector <bool>> visited(m, vector <bool> (n, false));
        queue <pair <int, int>> q;

        for(int i = 0; i < m; i++)
        {
            if(board[i][0] == 'O')
                q.push({i, 0});
            if(board[i][n-1] == 'O')
                q.push({i, n-1});
        }

        for(int i = 0; i < n; i++)
        {
            if(board[0][i] == 'O')  
                q.push({0, i});
            if(board[m-1][i] == 'O')
                q.push({m-1, i});
        }

        while(!q.empty())
        {
            int qs = q.size();
            for(int i = 0; i < qs; i++)
            {
                auto [x, y] = q.front();
                q.pop();
                visited[x][y] = true;
                for(int j = 0; j < 4; j++)
                {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if(0 <= nx && nx < m && 0 <= ny && ny < n && board[nx][ny] == 'O' && !visited[nx][ny])
                        q.push({nx, ny});
                }
            }
        }

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(!visited[i][j])
                    board[i][j] = 'X';
    }
};