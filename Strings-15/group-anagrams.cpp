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

int main()
{ 
    vector<string> input = { "eat", "tea", "tan", "ate", "nat", "bat" };
    Solution s;
    vector<vector<string>> result = s.groupAnagrams(input);
    for (const auto& r : result)
    {
        for (const auto& str : r)
            std::cout << str << std::endl;
        std::cout << "group change" << std::endl;
    }
    
	return 0;
}

