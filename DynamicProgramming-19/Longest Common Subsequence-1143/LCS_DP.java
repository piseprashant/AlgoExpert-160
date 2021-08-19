class Solution {
    public int longestCommonSubsequence(String x, String y) {
        int[][]  dp = new int[x.length()+1][y.length()+1];
    
    for(int i=0;i<x.length()+1;i++)
    {
        for(int j=0;j<y.length()+1;j++)
        {
			// Initialize DP 1st row and 1st column with 0's
            if(i==0 || j==0)
            {
                dp[i][j] = 0;
            }
        }
    }
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
    
    for(int i=1;i<x.length()+1;i++)
    {
        for(int j=1;j<y.length()+1;j++)
        {
			
            if(x.charAt(i-1) == y.charAt(j-1))
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[x.length()][y.length()];
        
    }
}

