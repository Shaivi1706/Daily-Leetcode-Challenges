// LEETCODE 1353. Maximum Number of Events That Can Be Attended
// Medium

// You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.
// You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.
// Return the maximum number of events you can attend.

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
      // we will first sort on the basis of first day
        sort(events.begin(), events.end());
      // minHeap to maintain order of second day
        priority_queue<int, vector<int>, greater<int>> mh;

        int day=1, i=0, res=0;
        int n=events.size();

        while(i<n || !mh.empty()) {
            // adding events of that day starting
            while (i < n && events[i][0] == day) {
                mh.push(events[i][1]);
                i++;
            }

            // Removing events that already ended
            while (!mh.empty() && mh.top() < day) {
                mh.pop();
            }

            // Attending the event that ends earliest
            // we are using if condition because in one day only one event can be covered.
            if (!mh.empty()) {
                mh.pop();
                res++;
            }
            day++;
        }
        return res;
    }
};

TC = O(NLogN)  SC = O(N)
