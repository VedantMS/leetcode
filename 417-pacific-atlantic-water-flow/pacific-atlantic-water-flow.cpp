class Solution {
public:
    vector<vector<int>> result;
    vector<vector<bool>> pacific;
    vector<vector<bool>> atlantic;

    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int r, int c) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        if(r < 0 || r >= rows || c < 0 || c >= cols || visited[r][c])    return;
        
        visited[r][c] = true;
        
        if(pacific[r][c] && atlantic[r][c])     result.push_back({r, c});

        if(c - 1 >= 0 && heights[r][c] <= heights[r][c - 1])        dfs(heights, visited, r, c - 1);    // Left
        if(c + 1 < cols && heights[r][c] <= heights[r][c + 1])      dfs(heights, visited, r, c + 1);    // Right
        if(r - 1 >= 0 && heights[r][c] <= heights[r - 1][c])        dfs(heights, visited, r - 1, c);    // Up
        if(r + 1 < rows && heights[r][c] <= heights[r + 1][c])      dfs(heights, visited, r + 1, c);    // Down
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        pacific.assign(rows, vector<bool>(cols, false));
        atlantic.assign(rows, vector<bool>(cols, false));
        
        for(int i = 0; i < cols; i++)   dfs(heights, pacific, 0, i), dfs(heights, atlantic, rows - 1, i);
        for(int i = 0; i < rows; i++)   dfs(heights, pacific, i, 0), dfs(heights, atlantic, i, cols - 1);

        return result;
    }
};