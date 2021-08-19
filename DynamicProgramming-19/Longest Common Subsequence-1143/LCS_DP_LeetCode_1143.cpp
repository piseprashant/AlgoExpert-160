class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
      
        int n=text1.length();
        int m=text2.length();
        
	// add dp tabulation with n,m +1
        int dp[n+1][m+1];
        
        for(int i = 0 ; i < n+1 ; i++)
            for(int j = 0 ; j < m+1 ; j++)
                if(i == 0 || j == 0)
                    dp[i][j]=0;// initialize 1st row and 1st column with all 0's
         /*
	Reverse of top down approach
	
	int LCS(int i, int j)
	{
	   if (a[i] == '\0' || b[j] == '\0' ) 
	    return 0;
	    else if (a[i] == b[j]) {
		return 1+ LCS(i+1, j+1);
	    }
	    else 
	    {
		return max(LCS(i+1, j), LCS(i, j+1));    
	    }   
	}
	*/
	//leave out 0th row and 0th column and iterate till n+1 and m+1
	// and check for ith -1 and jth -1 elements
        for(int i = 1 ; i < n+1 ; i++)
        {
            for(int j = 1 ; j < m+1 ; j++)
            {
                if(text1[i-1] == text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
            }
        }
       
        return dp[n][m];
       }
};
