class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());

        vector<vector<string>> ans;
        string prefix = "";

        for(char c : searchWord) {
            prefix += c;
            vector<string> temp;

            for(string &product : products) {
                if(product.find(prefix) == 0) {
                    temp.push_back(product);
                    if(temp.size() == 3) {
                        break;
                    }
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};