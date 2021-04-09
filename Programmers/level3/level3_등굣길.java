class Solution {
    
    static final int MOD = 1_000_000_007;
    
    public int solution(int m, int n, int[][] puddles) {
        int[][] dp = new int[m+1][n+1];
        for(int i=0;i<puddles.length;i++){
            int a = puddles[i][0];
            int b = puddles[i][1];
            dp[a][b] = -1;
        }
        
        dp[1][1]=1; 
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(dp[i][j]==-1){
                    dp[i][j]=0;
                    continue;
                }
                if(i!=1)    dp[i][j]+=dp[i-1][j]%MOD;
                if(j!=1)    dp[i][j]+=dp[i][j-1]%MOD;
            }
        }
        return dp[m][n]%MOD;
    }
}