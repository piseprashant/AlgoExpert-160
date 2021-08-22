// Minimum Number of Refueling Stops

int minRefuelStops(int target, int fuel, vector<vector<int>>& stations) {
    int n=stations.size(),ans=0;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        while(fuel<stations[i][0] && !pq.empty()){
            fuel+=pq.top();
            pq.pop();
            ans++;
        }
        pq.push(stations[i][1]);
        if(fuel<stations[i][0]) return -1;
    }
    while(target>fuel && !pq.empty()){
        fuel+=pq.top();
        pq.pop();
        ans++;
    }
    if(target>fuel) return -1;
    return ans;
}
};

