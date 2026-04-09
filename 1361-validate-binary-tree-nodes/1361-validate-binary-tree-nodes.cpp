class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0);

        for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1)     indegree[leftChild[i]]++;
            if(rightChild[i] != -1)    indegree[rightChild[i]]++;
        }

        int root = -1;

        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                if(root != -1)  return false;
                root = i;
            }

            if(indegree[i] > 1)  return false;
        }

        if(root == -1)  return false;

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(root);

        visited[root] = true;

        int ans = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            ans++;

            int left = leftChild[node];
            int right = rightChild[node];

            if(left != -1) {
                if(visited[left])   return false;

                q.push(left);
                visited[left] = true;
            }

            if(right != -1) {
                if(visited[right])  return false;

                q.push(right);
                visited[right] = true;
            }
        }

        return ans == n;
    }
};