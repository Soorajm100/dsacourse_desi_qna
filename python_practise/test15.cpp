class Solution {
public:
    int longestPalindromicSubsequence(string s, int k) {

        int dp[201][201][201] ; 

        memset(dp , 0 ,sizeof(dp)); 

        int n = s.size() ; 

        for(int i=0;i<n;i++){
            for(int j = 0 ;j<=k;j++){
                dp[i][i][j] = 1 ; 
            }
        }

        for(int lent=2;lent<=n;lent++){
            for(int i=0 ;i<n-lent+1;i++){
                int j = i + lent -1 ; 

                for(int op=0;op<=k;op++){
                    if(s[i]==s[j]){
                        dp[i][j][op] = 2 +  ((i+1 <= j-1) ? dp[i+1][j-1][op] : 0)  ; 
                    }
                    else{
                        int cost = min(abs(s[i] - s[j]) , 26-(abs(s[i] - s[j]))) ; 

                        dp[i][j][op] = max(dp[i+1][j][op] , dp[i][j-1][op]) ; 

                        if(op >=cost){
                            dp[i][j][op] = max(dp[i][j][op] , 2 + (i+1 <= j-1 ? dp[i+1][j-1][op-cost] : 0 )) ; 
                        }
                    }
                }
            }
        }


        return dp[0][n-1][k] ; 
    }
};