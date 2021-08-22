class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.size() == 0) {
            return 0;
        }
        
        sort(intervals.begin(), intervals.end(), [](const Interval& i1, const Interval& i2) -> bool {
            return i1.start < i2.start;
        });
        
        priority_queue<int, vector<int>, greater<int>> heap;
        int rooms = 0;
        heap.push(intervals[0].end);
        rooms++;
        
        for (int i = 1; i < intervals.size(); i++) {
	    // Has prev meeting ended. i,e prev meeting time has passed from next meeting start time.
            // If no then increase meeting count.

            if (heap.top() > intervals[i].start) {
                rooms++;
            }
            // else room is free to vacaated and no ned to increment room counter
	    else {
                heap.pop();
            }
            heap.push(intervals[i].end);
        }
        
        return rooms;
    }
};

// Sorting takes O(nlogn). Offering to min heap takes O(logn) so the for loop takes O(nlogn). The overall time complexity is O(nlogn).
