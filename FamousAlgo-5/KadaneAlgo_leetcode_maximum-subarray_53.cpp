

//-5, 4 , 6, -3, 4, -1

int maxSubArray(vector<int>& nums) {
	//kadane algo
	int maxSum=INT_MIN;   //max_so_far maxSum = -2147483648
	int curSum=0; //max_ending here or current
	for (int i=0;i<nums.size();i++)
	{
		// 0 + -5 = -5
		// -1
		// 10 (prev 4 + 6)
		// 7 (prev 10 -3)
		// 11 (prev 7 + 4)
		// 10 (prev 11 - 1
		curSum += nums[i];
		
		// -5 < -5 skip
		// -1 < 4
		// 10 < 6 skip
		// 7 < -3 skip
		// 11 < 4 skip
		// 10 < -1 skip
		// Remember - reset curSum if sumation is less than current value. as there is no good way to carry sumation of -ve values, as addition always leads greater value
		if (curSum < nums[i])
		{
			// 4
			curSum=nums[i];
		}
		// -5 > INT_MIN
		// 4 > -5
		// 10 > 4
		// 7 > 10 skip
		// 11 > 10 yes
		// 10 > 11 skip
		// Remember - we always keep maxSum of previous sumed values
		if(curSum > maxSum)
		{
			// -5
			// 4
			// 10
			// 11
			maxSum=curSum;
		}
	}
	return maxSum;
}
	

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    vector<int> nums = { -5, 4 , 6, -3, 4, -1 };
    vector<int> nums2 = { -1 };
    
    std::cout << maxSubArray(nums) << std::endl;
    std::cout << maxSubArray(nums2) << std::endl;
    return 0;
}

