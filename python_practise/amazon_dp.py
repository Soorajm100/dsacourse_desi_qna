


INF = 10**8

def  main():
    n, k  =map(int, input().split())
    a = [0] + list(map(int, input().split()))
    l = [0] + list(map(int, input().split()))
    s = [0] +  list(map(int, input().split()))
    dp =[[INF for _ in range(20001)] for _ in range(2001)]
    dp[0][0]=0
    #base  cases
    for i in range(1,n+1) : 
        if a[i]==a[i-1]: 
            dp[i][0] = dp[i-1][0] + s[a[i]]
            dp[0][i] = dp[0][i-1] + s[a[i]]
        else:
            dp[i][0] = dp[i-1][0] + l[a[i]]
            dp[0][i] = dp[0][i-1] + l[a[i]]
    
    for i in range(1,n+1):
        for  j in range(1,n+1):
            if i!=j:
                if i>j: 
                    if i==j+1: 
                        l1 = 2
                        while i-l1>=0 : 
                            pans = INF
                            if a[i-l1]==a[i]:
                                pans = dp[i-l1][j] + s[a[i]]
                            else:
                                pans =  dp[i-l1][j] + l[a[i]]
                            dp[i][j] = min(pans ,dp[i][j])
                            l1+=1
                    else:
                        if a[i]==a[i-1]:
                            dp[i][j] = min(dp[i][j] , dp[i-1][j] + s[a[i]])
                        else:
                            dp[i][j] =  min(dp[i][j] , dp[i-1][j] + l[a[i]])
                else:
                    if i==j-1:
                        l1 = 2 
                        while j-l1>=0:
                            pans = INF
                            if a[j-l1]==a[j]:
                                pans = dp[i][j-l1] + s[a[j]]
                            else:
                                pans =  dp[i][j-l1] + l[a[j]]
                            dp[i][j] = min(pans ,dp[i][j])
                            l1+=1
                    else:
                        if a[j]==a[j-1]:
                            dp[i][j] = min(dp[i][j] , dp[i][j-1] + s[a[j]])
                        else:
                            dp[i][j] =  min(dp[i][j] , dp[i][j-1] + l[a[j]])


    ans = INF
    for i in range(0,n):
        ans = min(dp[i][n], ans)
        ans = min(dp[n][i] , ans)
    

    return ans 



##calling the function##

print(main())