class MyCalendar {
public:
    map<int, int> mp;

    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        auto next = mp.upper_bound(startTime);

        if (next != mp.end() && next->second < endTime) {
            return false;
        }

        mp[endTime] = startTime;

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */