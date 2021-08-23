//https://www.youtube.com/watch?v=UPPZsSTdMN0

class Solution {
public:
    
    vector<vector<int>> adjList;
    vector<bool> isVisited;
    vector<bool> isCurrVisited;
    vector<int> sortedNodes;
    
    // return false if cycle found
    bool TopologicalSortDFS(int node)
    {
        isVisited[node] = true;
        isCurrVisited[node] = true;
        
        for (auto nextNode : adjList[node])
        {
            if (isCurrVisited[nextNode])
            {
                return false;
            }
            
            if (!isVisited[nextNode] && !TopologicalSortDFS(nextNode))
            {
                return false;
            }
        }
        sortedNodes.emplace_back(node);
        isCurrVisited[node] = false;
        return true;
        
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        // create a adjoincy list as map or vector of vector. Last time we did map lets do with vector or vector
        adjList = vector<vector<int>>(numCourses, vector<int>()); // with vector size as numCourses and init to 0
        
        isVisited = vector<bool>(numCourses, false);
        isCurrVisited = vector<bool>(numCourses, false);
        
        for (auto edge : prerequisites)
        {
            // something similar to map add outer vector with possible iner values of nodes
            adjList[edge[0]].emplace_back(edge[1]);
        }
        
        // now start DFS i.e we have numCourses
        
        for (int i=0; i < numCourses; i++)
        {
            if (!isVisited[i])
            {
                if (TopologicalSortDFS(i) == false)
                {
                    return {};
                }
            }
            
        }
        
        return sortedNodes;
    }
};
