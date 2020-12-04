class Solution {
public:
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };

    bool dfs(int x, int y, int idx, string word, vector<vector<char>>& board, int m, int n)
    {
        if (board[x][y] != word[idx])
            return false;
        if (idx == word.size() - 1)
            return true;
        char c = board[x][y];
        board[x][y] = '*';
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || board[nx][ny] == '*')
                continue;
            if (dfs(nx, ny, idx + 1, word, board, m, n))
                return true;
        }
        board[x][y] = c;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word)
    {

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0, word, board, m, n))
                    return true;
            }
        }
        return false;
    }
};