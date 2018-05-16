/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        auto Cmp = [](Interval a, Interval b){return a.start < b.start;};
        auto it = lower_bound(res.begin(), res.end(), Interval(val, val), Cmp);
        int start = val, end = val;
        if(it != res.begin() && (it - 1)->end + 1 >= val)
            it--;
        while(it != res.end() && val + 1 >= it->start && val - 1 <= it->end)
        {
            start = min(start, it->start);
            end = max(end, it->end);
            it = res.erase(it);
        }
        res.insert(it, Interval(start, end));
    }
    
    vector<Interval> getIntervals() {
        return res;
    }
private:
    vector<Interval> res;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
