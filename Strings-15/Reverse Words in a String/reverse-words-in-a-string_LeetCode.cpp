class Solution {
public:
    
   vector<string> split(string str, string token) {
    vector<string>result;
    while (str.size()) {
        int index = str.find(token);
        if (index != string::npos) {
            if (str.substr(0, index).compare("") == 0 )
            {
                str = str.substr(index + token.size());
                continue;
            }
            result.push_back(str.substr(0, index));
            str = str.substr(index + token.size());
            if (str.size() == 0)
            {
                result.push_back(str);
            }
                
        }
        else {
            // Push last word as no delimter found
            result.push_back(str);
            str = "";
        }
    }
    return result;
}
    
    string reverseWords(string s) {
        vector<string> result = split(s, " ");
        reverse(result.begin(), result.end());

        std::string finalStr;
        for (int i = 0; i < result.size(); i++)
        {
            finalStr += result[i];
            if (i == result.size() -1)
            {
                break;
            }
            else
            {
                finalStr += " ";

            } 
        }

        return finalStr;
    }
};
