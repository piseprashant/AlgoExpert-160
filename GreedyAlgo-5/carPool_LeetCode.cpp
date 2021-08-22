class Solution {
    static bool cmp(vector<int>&v1,vector<int>&v2)
    {
        if(v1[1]<v2[1] || (v1[1]==v2[1] && v1[2]<v2[2]))
            return true;
        else return false;
    }
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
		// 1st always sort the list for feasibility study
        sort(trips.begin(),trips.end(),cmp);
        
		int n=trips.size();
		//   template <class Type,     class Container=vector<Type>, class Compare=less<typename Container::value_type>>
        priority_queue< pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>> >heap;
		
		// take the 1st trip capacity members in count and keep counting for all the trips
        int count=trips[0][0];
		
		// base case what if 1st trip has exceeded the car capacity size so directly say false 
        if(count>capacity)
            return false;
		
		// Push in min heap end time and capacity members.
        heap.push({trips[0][2],trips[0][0]});
		
       // top.first will contain the finishing time , top.second will contain the passengers in that trip of the least finishing time.
	   for(int i=1;i<n;i++)
        {
			// top.first will contain the finishing time, that means if i am smaller than next trip start time. 
			// So i can remove from the queue and decrement the count for next trip passengers
            while(!heap.empty() && heap.top().first<= trips[i][1])
            {
                count=count-heap.top().second; heap.pop();
            }
			// add next trip members in the counter
            count+=trips[i][0];
			// again check the core condition have i exceeded the capacity
            if(count>capacity)
                return false;
			// if not then take the next trip values in min heap priority_queue
            heap.push({trips[i][2],trips[i][0]});
        }
		// if no false case and end of all trips so submit as true as trip successful.
        return true;
    }
};

//https://www.youtube.com/watch?v=Xi5_Zkszhas
