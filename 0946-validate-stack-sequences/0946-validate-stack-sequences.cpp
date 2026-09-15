class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int index = 0;

        for (int &num : pushed) {
            st.push(num);
            
            while (st.size() > 0 && st.top() == popped[index]) {
                st.pop();
                index++;
            }
        }

        return st.empty();
    }
};