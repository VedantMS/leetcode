class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        vector<int> visited(n, false);
        
        q.push(start);
    
        while(!q.empty()) {
            int pos = q.front();
            q.pop();

            if(pos + arr[pos] < n && !visited[pos + arr[pos]]) {
                if(arr[pos + arr[pos]] == 0) {
                    return true;
                }
                q.push(pos + arr[pos]);
                visited[pos + arr[pos]] = true;
            }

            if(pos - arr[pos] >= 0 && !visited[pos - arr[pos]]) {
                if(arr[pos - arr[pos]] == 0) {
                    return true;
                }
                q.push(pos - arr[pos]);
                visited[pos - arr[pos]] = true;
            }
        }
        return false;
    }
};