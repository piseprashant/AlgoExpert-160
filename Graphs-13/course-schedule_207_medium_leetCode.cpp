/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> m;
        unordered_map<int, int> loop;
        
        for (auto& p : prerequisites)
        {
            if (p[0] == p[1])
            {
                return false;
            }
            
            m[p[0]].push_back(p[1]);
        }
        
        for (auto& p : m)
        {
            if (! loop.count(p.first))
            {
		// 
		// step 2 - 1, empty loop, adj List - m 
		// step 13 - now take key 2
		// step 16 - now take key 3 that has 2 values 1,2
                if (checkLoop(p.first, loop, m))
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool checkLoop(int begin, unordered_map<int, int>& loop, unordered_map<int, list<int>>& m)
    {
	// step 3 - loop is empty skip
	// step 8 - has key 0 has values, as 0 has no values no further dfs skip
	// step 14 - for key 2, no values in already explored loops. 
	// step 17 - check if we detect any loops for key 3. so its not traced yet
        if (loop.count(begin))
        {
            if (loop[begin])
            {
                return true;
            }
            else
            {
		// step  16 - as 0 was already explored and said no loops return no loops false
                return false;
            }
        }
	// step 4 - visited list - begin elements is say we could have a loop. set 1
	// step 9 - say 0 is visited
	// step 15 - so lets say we have loop for key 2
	// step 18 - iterate for key 3 and lets say it has cycle
        loop[begin] = 1;
	// step 5 - check if given key has elements. Ans is yes . Key is 1 value - 0
	// step  10 - no elements for 0 to enter dfs check loop
        if (m.count(begin))
        {
	    //step 6 -  so iterate to all the elements of that key and do DFS. where p = 0
            for (auto& p : m[begin])
            {
		//step 7 -  no check value 0 as key and do recurrsive DFS
		// step 12, as 0 no loop take next from adj list i.e key -2 
                if (checkLoop(p, loop, m))
                {
                    return true;
                }
            }
        }
	// step 11 - confirmed no loop for value 0
        loop[begin] = 0;    //confirmed no loop
        
        return false;
    }
};

// same concept using set and hash map in python.
// https://www.youtube.com/watch?v=EgI5nU9etnU
