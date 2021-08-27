class Solution {
public:
    
    vector<int> p;

    int dsu_get(int v) {
        return p[v] == v ? v : p[v] = dsu_get(p[v]);
    }
    
    void dsu_unite(int a, int b) {
        p[dsu_get(a)] = dsu_get(b);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        p.resize(edges.size() + 1);
        iota(p.begin(), p.end(), 0); // p[i] = i afther this
        
        for(auto& edge : edges) {
            int a = edge[0], b = edge[1];
            // greedy unite nodes while not all of them are connected
            if(dsu_get(a) != dsu_get(b)) {
                dsu_unite(a, b);
            } else {
                return edge;
            }
        }
        return {};
    }
};
