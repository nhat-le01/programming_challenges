/**
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.**/
class Solution {
public:
    void bfs(vector<vector<char>>& board, int r, int c) {
        int rows = board.size();
        int cols = board[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(r, c));
        board[r][c] = 'B';
        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            pair<int, int> adjacents[4] = {{current.first - 1, current.second}, {current.first + 1, current.second}, {current.first, current.second + 1}, {current.first, current.second - 1}};
            for (int i = 0; i < 4; i++) {
                int row = adjacents[i].first;
                int col = adjacents[i].second;
                if (row >= 0 && col >= 0 && row < rows && col < cols && board[row][col] == 'O') {
                    q.push(make_pair(row, col));
                    board[row][col] = 'B';
                }         
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) {
            return;
        }
        int height = board.size();
        int width = board[0].size();
        if (width == 0) {
            return;
        }
        //Check from the boundary
        for (int i = 0; i < height; i++) {
            if (board[i][0] == 'O') {
                bfs(board, i, 0);
            }
            if (board[i][width - 1] == 'O') {
                bfs(board, i, width - 1);
            }
        }
        for (int i = 0; i < width; i++) {
            if (board[0][i] == 'O') {
                bfs(board, 0, i);
            }
            if (board[height - 1][i] == 'O') {
                bfs(board, height - 1, i);
            }
        }
        
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'B') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
