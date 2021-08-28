// https://www.youtube.com/watch?v=kaBX2s3pYO4
// Rules
// 1 - Having same rank - Rank of new AP (absolute parent) increase by value 1
// 2 - Having diff rank - Rank doesn't change.
// 3. Height shouldn't be increased while Union operation
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
//#include<bits/stdc++.h>

using namespace std;

struct node {
	int parent;
	int rank;
};

vector<node> dsuf;
//FIND operation
int find(int v)
{
	if (dsuf[v].parent == -1)
		return v;
	return dsuf[v].parent = find(dsuf[v].parent);	//Path Compression
	// above steps 
	//			(3)
	//          / ) 3
	//        (2)
	//        / ) 3
	//		(1)
	//		/ ) 3
	//	   (0)
	// New graph
	//           (3)
	//        /  |   \   
	//      0    1    2
}

void union_op(int fromP, int toP)
{
	//fromP = find(fromP);
	//toP = find(toP);

	//UNION by RANK
	// Rule 2 from if and else if case - // 2 - Having diff rank - Rank doesn't change.
	// Rule 3. Height shouldn't be increased.   
	//            (AP 1 has higher rank/height)
	//                        \
	//						(AP 2 has lowe rank/height) 
	// so AP 1 will be parent of AP 2
	if (dsuf[fromP].rank > dsuf[toP].rank)	//fromP has higher rank
		dsuf[toP].parent = fromP;
	else if (dsuf[fromP].rank < dsuf[toP].rank)	//toP has higher rank
		dsuf[fromP].parent = toP;
	else
	{
		//Both have same rank and so anyone can be made as parent as my choice
		dsuf[fromP].parent = toP;
		dsuf[toP].rank += 1;		//Increase rank of parent
		// Edge 0 - 1
		// Node (no of vertices) - 0 , 1,  2,  3,  4
		// Each node will store
		// parent init to -1	- 1, -1, -1, -1, -1, 
		// and rank init to 0   =  0, +1,  0,  0,  0,  
	}
}

bool isCyclic(vector<pair<int, int>>& edge_List)
{
	for (auto p : edge_List)
	{
		int fromP = find(p.first);	//FIND absolute parent of subset
		int toP = find(p.second);

		//      (AP)
		//    /  	\
		//   from    to // if already from and to point to same root, then don't add below union line
		//   from -X-To // we detect a cycle stop the algo and return graph has cycle, else do union operation

		if (fromP == toP)
			return true;

		//UNION operation
		union_op(fromP, toP);	//UNION of 2 sets
	}
	return false;
}

int main()
{
	int E = 5;	//No of edges given sample input { {0,1}, {2,3}, {1,2}, {0,4}, {4,3} };
	int V = 5;	//No of vertices (0 to V-1)
	//cin >> E >> V;

	dsuf.resize(V);	//Mark all vertices as separate subsets with only 1 element

	// Node (no of vertices) - 0 , 1,  2,  3,  4
	// Each node will store
	// parent init to -1	- -1, -1, -1, -1, -1, 
	// and rank init to 0   =  0,  0,  0,  0,  0,  
	for (int i = 0; i < V; ++i)	//Mark all nodes as independent set
	{
		dsuf[i].parent = -1;
		dsuf[i].rank = 0;
	}

	vector<pair<int, int>> edge_List;	//Adjacency list
	edge_List = { {0,1}, {2,3}, {1,2}, {0,4}, {4,3} };
	/*for (int i = 0; i < E; ++i)
	{
		int from, to;
		cin >> from >> to;
		edge_List.push_back({ from,to });
	}*/

	if (isCyclic(edge_List))
		cout << "TRUE\n";
	else
		cout << "FALSE\n";

	return 0;
}

//TIME COMPLEXITY: O(E.V)
