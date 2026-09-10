class ATM {
public:
    vector<int> banknotes;

    ATM() {
        banknotes.resize(5, 0);
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++) {
            banknotes[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ans(5, 0), val = {20, 50, 100, 200, 500};

        for (int i = 4; i >= 0 && amount > 0; i--) {
            ans[i] = min(banknotes[i], amount / val[i]);
            amount -= ans[i] * val[i];
        }


        if (amount) {
            return {-1};
        }

        for (int i = 0; i < 5; i++) {
            banknotes[i] -= ans[i];
        }

        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */