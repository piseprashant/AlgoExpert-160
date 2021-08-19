class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     vector<vector<string>>ans;
        vector<string>temp=strs;
        for(int i=0;i<strs.size();i++)
        {
            sort(strs[i].begin(),strs[i].end());
        }
        map<string,vector<string>>m;
        for(int i=0;i<strs.size();i++)
        {
            m[strs[i]].push_back(temp[i]);
        }
        for(auto it:m)
        {
            ans.push_back(it.second);
        }
        return ans;  
    }
};
