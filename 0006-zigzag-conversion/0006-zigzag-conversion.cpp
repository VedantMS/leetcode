class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.size())     return s;

        int index = 0, dir = 1;
        vector<vector<char>> rows(numRows);

        for(char ch : s) {
            rows[index].push_back(ch);
            
            if(index == 0)                      dir = 1;

            else if(index == numRows - 1)       dir = -1;

            index += dir;
        }

        string ans;

        for(auto &row : rows) {
            for(char ch : row)      ans += ch;
        }

        return ans;
    }
};