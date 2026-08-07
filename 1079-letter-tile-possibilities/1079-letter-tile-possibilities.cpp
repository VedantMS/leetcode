class Solution {
public:
    void tile(string &tiles, vector<bool> &visited, int &ans, string &s) {
        if (s.size() > 0) {
            ans++;
        }

        for (int i = 0; i < tiles.size(); i++) {
            if (visited[i] || i > 0 && tiles[i] == tiles[i - 1] && !visited[i - 1]) {
                continue;
            }

            visited[i] = true;
            s.push_back(tiles[i]);

            tile(tiles, visited, ans, s);

            visited[i] = false;
            s.pop_back();
        }
    }

    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());

        int ans = 0;
        string s = "";

        vector<bool> visited(tiles.size(), false);
        
        tile(tiles, visited, ans, s);

        return ans;
    }
};