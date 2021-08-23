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
        if (loop.count(begin))
        {
            if (loop[begin])
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        loop[begin] = 1;
        if (m.count(begin))
        {
            for (auto& p : m[begin])
            {
                if (checkLoop(p, loop, m))
                {
                    return true;
                }
            }
        }
        loop[begin] = 0;    //confirmed no loop
        
        return false;
    }
};
