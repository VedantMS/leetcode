class TimeMap {
public:
    map<string, map<int, string>> data;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        data[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto &a = data[key];
        auto it = a.upper_bound(timestamp);

        if (it == a.begin()) {
            return "";
        }

        it--;

        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */