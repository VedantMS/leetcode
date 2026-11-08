class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;

        for (string email : emails) {
            string s = "";
            bool flag = false, plus = false;

            for (int i = 0; i < email.size(); i++) {
                if (email[i] == '@') {
                    flag = true;
                    plus = false;
                }

                if (email[i] == '+' && !flag) {
                    plus = true;
                }

                if ((isalnum(email[i]) || flag) && !plus) {
                    s += email[i];
                }
            }

            st.insert(s);
        }

        return st.size();
    }
};