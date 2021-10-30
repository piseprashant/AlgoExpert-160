// Union by rank and join by path compression Understanding https://www.youtube.com/watch?v=kaBX2s3pYO4&t=391s
// Use union and find in actual pb https://www.youtube.com/watch?v=Kn-nw7VbWak

class UnionFind {
private:
    vector<int> parents_;
    vector<int> ranks_;
public:
    
    UnionFind(int len) {
        ranks_ = vector<int>(len, 0);
        parents_ = vector<int>(len, 0);
        for (int i = 0; i < len; i++) 
            parents_[i] = i;
    }
    bool Union(int a, int b) {
        int pa = Find(a);
        int pb = Find(b);
        //      (AP)
		//    /  	\
		//   from    to // if already from and to point to same root, then don't add below union line
		//   from -X-To // we detect a cycle stop the algo and return graph has cycle, else do union operation

        if (pa == pb)
            return false;
        
        //UNION by RANK
	    // Rule 2 from if and else if case - // 2 - Having diff rank - Rank doesn't change.
	    // Rule 3. Height shouldn't be increased.   
	    //            (AP 1 has higher rank/height)
	    //                        \
	    //						(AP 2 has lowe rank/height) 
	    // so AP 1 will be parent of AP 2
        
        if (ranks_[pa] > ranks_[pb])
            parents_[pb] = pa;
        else if (ranks_[pa] < ranks_[pb])
            parents_[pa] = pb;
        else {
            //Both have same rank and so anyone can be made as parent as my choice
            parents_[pa] = pb;
            ranks_[pa]++;
            // Edge 0 - 1
		    // Node (no of vertices) - 0 , 1,  2,  3,  4
		    // Each node will store
            // parent init to -1	- 1, -1, -1, -1, -1, 
            // and rank init to 0   =  0, +1,  0,  0,  0,
        }
        return true;
    }
    int Find(int a) {
        if (parents_[a] == a) return a;
        return (parents_[a] = Find(parents_[a])); //Path Compression
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
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int len = isConnected.size();
        UnionFind s(len);
        int count = 0;
// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
// check all edges
// i = 0 j - 0, 1 , 2 

// 0 0 - 1, // A -A connected 
// 0 1 - 1, // A -B connected 
// 0 2 - 0 // C is diconnected

// B = A connected C is diconnected
// i = 1 j - 0, 1 , 2
// 1 0 - 1, - B = A connected
// 1 1 - 1 -  B = B connected
// 1 2 - 0 -  B = C disconnected

// i = 2 j - 0, 1 , 2
// 2 0 - 0,- C = A is disconnected, 
// 2 1 - 0 - C = B is disconnected 
// 2 2 - 1 - C - C is connected
                if (isConnected[i][j]) {
                    if (s.Union(i, j)) 
                        count++;
                }
            }
        }
        return len - count;
    }
};


