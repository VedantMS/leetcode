class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        if(st.find(endGene) == st.end()) {
            return -1;
        }
        
        string str = "ACGT";
        int count = 0;

        queue<string> q;
        q.push(startGene);

        while(!q.empty()) {
            int level = q.size();

            for(int i = 0; i < level; i++) {
                string gene = q.front();
                q.pop();

                if(gene == endGene) {
                    return count;
                }
                
                for(int j = 0; j < 8; j++) {
                    char original = gene[j];

                    for(char ch : str) {
                        gene[j] = ch;

                        if(st.count(gene)) {
                            q.push(gene);
                            st.erase(gene);
                        }
                    }
                    gene[j] = original;
                }
            }
            count++;
        }
        return -1;
    }
};