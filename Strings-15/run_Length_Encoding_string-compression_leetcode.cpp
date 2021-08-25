/*

Your input
["a","a","b","b","c","c","c"]
["a"]
["a","b","b","b","b","b","b","b","b","b","b","b","b"]
["a","a","a","b","b","a","a"]
Output
["a","2","b","2","c","3"]
["a"]
["a","b","1","2"]
["a","3","b","2","a","2"]
Expected
["a","2","b","2","c","3"]
["a"]
["a","b","1","2"]
["a","3","b","2","a","2"]

*/

class Solution {
public:
    int compress(vector<char>& chars) {
        
        
        std::string retStr;
        if (chars.size() == 0)
            return 0;

        char prevChar = chars[0];
        int counter = 1;
        vector<char>::iterator charIter;
        // base case check if only 1 character
        if (chars.size() >= 2)
        {
            charIter = chars.begin() + 1;


            for (; charIter < chars.end(); charIter++)
            {
                if (*charIter == prevChar)
                {
                    counter++;
                }
                else
                {
                    retStr.push_back(prevChar);
                    if (counter > 1)
                        retStr.append(to_string(counter));
                    prevChar = *charIter;
                    counter = 1;
                }
            }
            retStr.push_back(prevChar);
            if (counter > 1)
                retStr.append(to_string(counter));
        }
        else
        {
            retStr.push_back(chars[0]);
        }

        chars.clear();
        // now convert string to input vector 
        std::copy(retStr.begin(), retStr.end(), std::back_inserter(chars));

        return retStr.length();
    }
};
