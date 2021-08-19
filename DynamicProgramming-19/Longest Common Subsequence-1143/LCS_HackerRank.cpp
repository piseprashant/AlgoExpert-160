vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    int n=a.size();
    int m=b.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i=n;
    int j=m;
    vector<int> v;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            v.push_back(a[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else 
                j--;
        }
    }
    reverse(v.begin(),v.end());
    return v;
}

/*
5 6
1 2 3 4 1
3 4 1 2 1 3
Expected Output

3 4 1

*/

/*
Input (stdin)

9 10
3 9 8 3 9 7 9 7 0
3 3 9 9 9 1 7 2 0 6
Expected Output

3 3 9 9 7 0
*/
