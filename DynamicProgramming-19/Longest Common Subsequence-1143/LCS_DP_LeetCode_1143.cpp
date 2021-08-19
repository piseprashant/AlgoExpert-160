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
		// as we started to ensure not to hit out of bounds with 1st row and 1st column
		// however we need to fill the 0th row and 0th column and iterate for last element
		// check from start 0th position for both the strings
                if(text1[i-1] == text2[j-1])
		   // if match then add 1 + dp[0][0] element onwards
                    dp[i][j]=1+dp[i-1][j-1];
                else
		   // if no match then get max (dp[1][0], dp[0][1] element onwards
                    dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
            }
        }
       
        return dp[n][m];
       }
};
	J=	a	b	c	d	\0
	I below	0	1	2	3	4
B	0	0	0/ 1+ 0	0	0	0
d	1	0	Dp[1][1] = 			
\0	2	0				



