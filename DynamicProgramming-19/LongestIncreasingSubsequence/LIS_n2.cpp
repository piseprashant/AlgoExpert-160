
int longestIncreasingSubsequence(vector<int> arr) {
    
    vector<int> lis(arr.size(), 1); // Initialized with 1
    int maxVal = 1;
    for (int i = 1; i <= arr.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((arr[i] >= arr[j]) 
            && (lis[i] <= lis[j]))
            {
                lis[i] = 1 + lis[j];
                maxVal = max(lis[i], maxVal);
            }
        }        
    }
    
    return maxVal;
    
}


// better solution

int longestIncreasingSubsequence(vector<int> nums) {
    
     vector<int> dp;
        for (auto& n : nums) {
	    // check first condition if ((arr[i] >= arr[j])  by lower bounds
            auto el = std::lower_bound(dp.begin(), dp.end(), n);
	    // if given n is the biggest no then lower bound has returned last index then push the number 
            if (el == dp.end()) dp.push_back(n);
            else *el = n;
        }
        return dp.size();
    
}
/*
Begin size 0

lower_bound for element 2 at position : 0 push :2 dp size - 1

lower_bound for element 5 at position : 1 push :5 dp size - 2

lower_bound for element 3 at position : 1
lower_bound for element 7 at position : 2 push :7 dp size - 3

lower_bound for element 11 at position : 3 push :11 dp size - 4

lower_bound for element 8 at position : 3
lower_bound for element 10 at position : 4 push :10 dp size - 5

lower_bound for element 13 at position : 5 push :13 dp size - 6

lower_bound for element 6 at position : 2LIS size 6

*/


