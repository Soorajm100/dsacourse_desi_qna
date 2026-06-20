





def main():

    s = input()
    n = len(s)


    dp = [[0 for _ in  range(n)] for _ in range(n)]

    for  i in  range(n):
        dp[i][i] = 1 
    

    for lent in  range(2, n+1) : 
        for i  in range(n-lent+1) : 
            j = i+ lent-1
            if s[i] ==s[j] : 
                dp[i][j] = max(2 + dp[i+1][j-1] , dp[i+1][j] , dp[i][j-1])
            else : 
                dp[i][j] = max(dp[i][j-1] , dp[i+1][j])
    
    return dp[0][n-1] 





print(main())