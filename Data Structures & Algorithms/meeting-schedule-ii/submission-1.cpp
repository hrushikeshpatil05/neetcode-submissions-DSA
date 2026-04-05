/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        priority_queue<int,vector<int>,greater<int>>pq;
        int ans = 0;

        for(int i=0;i<n;i++) {
            int startTime = intervals[i].start;
            int endTime = intervals[i].end;

            if(pq.empty() || startTime < pq.top()) {
                pq.push(endTime);
                ans++;
            }
            else {
                pq.pop();
                pq.push(endTime);
            }
        }
        return ans;
    }
};
