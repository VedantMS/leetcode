class RandomizedSet {

private:
    vector<int> values;
    unordered_map<int, int> valuesIdx;    

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (valuesIdx.find(val) != valuesIdx.end())     return false;

        valuesIdx[val] = values.size();
        values.push_back(val);

        return true;
    }

    bool remove(int val) {
        if (valuesIdx.find(val) == valuesIdx.end())     return false;

        int index = valuesIdx[val];
        valuesIdx[values.back()] = index;
        valuesIdx.erase(val);
        values[index] = values.back();
        values.pop_back();

        return true;
    }

    int getRandom() {
        int index = rand() % values.size();
        
        return values[index];
    }
};