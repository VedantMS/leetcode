class FrontMiddleBackQueue {
public:
    vector<int> ans;

    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        ans.insert(ans.begin(), val);
    }
    
    void pushMiddle(int val) {
        ans.insert(ans.begin() + ans.size() / 2, val);
    }
    
    void pushBack(int val) {
        ans.push_back(val);
    }
    
    int popFront() {
        if (ans.empty()) {
            return -1;
        }

        int num = ans[0];
        ans.erase(ans.begin());


        return num;
    }
    
    int popMiddle() {
        if (ans.empty()) {
            return -1;
        }

        int num = ans[(ans.size() - 1) / 2];
        ans.erase(ans.begin() + (ans.size() - 1) / 2);

        return num;
    }
    
    int popBack() {
        if (ans.empty()) {
            return -1;
        }

        int num = ans.back();
        ans.pop_back();

        return num;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */