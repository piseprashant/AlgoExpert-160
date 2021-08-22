class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        std::sort(trips.begin(), trips.end(), [](auto & t1, auto & t2) {
            if(t1[1] == t2[1]){
                return t1[2] < t2[2];
            }
            return t1[1] < t2[1];
        });
        if(trips.empty()){
            return true;
        }
        
        if(trips.size() == 1){
            return trips[0][0]  <= capacity;
        }
        priority_queue<pair<int, int>> pq;
        int sum = trips[0][0];
        int lastEnd = trips[0][2];
        pq.push(std::make_pair(-1 * lastEnd, sum));
        // keep a running sum of weights, if weight gets above capacity return false
        // priority queue that contains the least end and the weight
        // while merging, each time we add another interval, we check if the start is larger than the least end,
        // while this is true, pop off from the heap and subtract from the capacity
        for(int i = 1; i < trips.size(); i++){
            if(sum > capacity){
                return false;
            }
            if(lastEnd > trips[i][1]){
                //merge them together
                while(!pq.empty() && (pq.top().first * -1) <= trips[i][1]){
                    sum -= (pq.top().second);
                    pq.pop();
                }
                sum += trips[i][0];
                pq.push(std::make_pair(-1*trips[i][2], trips[i][0]));
                if(sum > capacity){
                    return false;
                }
                lastEnd = max(lastEnd, trips[i][2]);
            }
            else{
                sum = trips[i][0];
                lastEnd = trips[i][2];
                while(!pq.empty()){
                    pq.pop();
                }
                pq.push(std::make_pair(-1*trips[i][2], trips[i][0]));
            }
        }
        return true;
    }
};
