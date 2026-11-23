class ProductOfNumbers {
public:
    vector<int> a{1};

    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num == 0) {
            a = {1};
        }

        else {
            a.push_back(a.back() * num);
        }
    }
    
    int getProduct(int k) {
        return k >= a.size() ? 0 : a[a.size() - 1] / a[a.size() - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */