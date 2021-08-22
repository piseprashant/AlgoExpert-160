class Solution {
    
public:
    
    static bool cmp(const vector <int>& a,const vector <int>&b)
    {
        if(a[1]==b[1])
            return a[2]<b[2];
        
        return a[1]<b[1];
    }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        sort(trips.begin(),trips.end(),cmp);
        priority_queue <pair <int,int> , vector <pair<int,int>> , greater <pair<int,int>>> pq;
        
        
        int passengers=0,step=0,idx=0;
        while(idx<trips.size())
        {
            while(idx<trips.size() && trips[idx][1] == step)
            {
                pq.push({trips[idx][2],trips[idx][0]});
                passengers+=trips[idx][0];
                idx++;
            }
            
            while(!pq.empty() && pq.top().first == step)
            {
                passengers-=pq.top().second;
                pq.pop();
            }
            
            if(passengers > capacity)
                return false;
            step++;
        }
        return true;              
    }
};
