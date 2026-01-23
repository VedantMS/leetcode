class Solution {
public:
    vector<vector<int>> result;
    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int r, int c) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        if(r < 0 || r >= rows || c < 0 || c >= cols || visited[r][c])    return;
        
        visited[r][c] = true;
        
        if(c - 1 >= 0 && heights[r][c] <= heights[r][c - 1])        dfs(heights, visited, r, c - 1);    // Left
        if(c + 1 < cols && heights[r][c] <= heights[r][c + 1])      dfs(heights, visited, r, c + 1);    // Right
        if(r - 1 >= 0 && heights[r][c] <= heights[r - 1][c])        dfs(heights, visited, r - 1, c);    // Up
        if(r + 1 < rows && heights[r][c] <= heights[r + 1][c])      dfs(heights, visited, r + 1, c);    // Down
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        
        for(int i = 0; i < cols; i++)   dfs(heights, pacific, 0, i), dfs(heights, atlantic, rows - 1, i);
        for(int i = 0; i < rows; i++)   dfs(heights, pacific, i, 0), dfs(heights, atlantic, i, cols - 1);

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};