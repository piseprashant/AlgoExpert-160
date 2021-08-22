// https://leetcode.com/problems/longest-valid-parentheses/submissions/#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {

public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        std::stack<int> StringStack;
        StringStack.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s.at(i) == '(') {
                // step 3 - add  ( index 1
                // step 6 - add  ( index 3
                StringStack.push(i);
            }
            else {
                // step 1 -  Here eg 2 - )()()(
                // step 1 - remove -1 from stack

                // step 4 - remove ) index 2
                // step 7 - remove ) index 4
                StringStack.pop();
                // step 2 - now stack is empty so push index 0 i.e. )
                if (StringStack.empty()) {
                    StringStack.push(i);
                }
                else {
                    // step 5 - stack is not empty as it has index 0 - ')'. max(0, (i)2-(stack has index 0 ))0) = 2
                    // step 8 - stack is not empty as it has index 0 - ')'. max(1, (i)4-(stack has still index 0 element )0) = 4
                    std::cout << "top-" << StringStack.top() << std::endl;
                    maxans = max(maxans, i - StringStack.top());
                }
            }
        }
        return maxans;
    }
};

int main()
{ 
   Solution s;
   int maxValid= s.longestValidParentheses(")()()(");
   
   std::cout << "maxValid-" << maxValid  << std::endl;
    
	return 0;
}

