/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    
    static bool comp(const Interval& a, const Interval& b)
    {
        return a.start < b.start;
    }
    
    bool isIntersect(const Interval& a, const Interval& b)
    {
        int max_start = max(a.start, b.start);
        int min_end = min(a.end, b.end);
        
        return max_start <= min_end;
    }
    
    
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        
        if(intervals.size() <= 0)
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        
        
        vector<Interval> R;
        
        
        intervals.push_back(newInterval);
        
        sort(intervals.begin(), intervals.end(), comp);
        
        
        Interval curr = intervals[0];
        
        for(int i = 1; i < intervals.size(); i++)
        {
            if(isIntersect(curr, intervals[i]))
            {
                curr.start = min(curr.start, intervals[i].start);
                curr.end = max(curr.end, intervals[i].end);
                continue;
            }
            else
            {
                R.push_back(curr);
                curr = intervals[i];
            }
        }
        
        R.push_back(curr);
            
        return R;
              
    }
};
