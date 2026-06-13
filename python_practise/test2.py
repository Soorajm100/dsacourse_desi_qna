
def  main():
    n = int(input())
    s = input()
    dp =[ [[-10**18 for i  in range(27)] for _ in  range(n+1)] for _  in range(n+1)]
    dp2 = [[-10**18 for  i  in range(27)] for _ in range(n+1)]
    prefix = [-10**18 for _ in range(30)]
    suffix = [-10**18 for _ in range(30)]
    

    for i in  range(1,27):
        prefix[i] = max(prefix[i-1] , dp2[0][i])
    for i in range(26,0,-1):
        suffix[i] = max(suffix[i+1] , dp2[0][i])


    if s[0] == '.':
        for j  in  range(1,27):
            dp[0][1][j] = 1 ; 
            dp2[0][j] = 1 ; 
    else:
        u  = ord(s[0]) - 97 
        u = u+1 
        dp[0][1][u] = 1 ; 
        dp2[0][u] = 1 ; 
    
    for  i in range(1,n): 
        if s[i]=='.':
            u = 1 
            while u<=26:
                m = -10**18
                # same case  here we avoid the loop  byusing the prefix and suffix
                #for p in range(1,27):
                    #if p!=u:
                        #for l in range(1,i+1) :
                            #m = max(m , dp[i-1][1][p])
                m = max( prefix[u-1] , suffix[u+1])
                dp[i][1][u] = 1 + m 
                dp2[i][u]= max(dp[i][1][u] , dp2[i][u])

                j =2 
                while j<=i+1 : 
                    dp[i][j][u] = max(dp[i][j][u] , dp[i-1][j-1][u] + j) 
                    dp2[i][u]= max(dp2[i][u], dp[i][j][u])
                    j+=1
                    
                u+=1
        else:
            u = ord(s[i]) - 97 
            u = u +1 
            m = -10**18 
            #by using the suffic and prefix we avvoid this loop 
            #for p  in  range(1,27):
                #if p!=u:
                    #for l in  range(1,i+1):
                        #m = max(m , dp[i-1][1][p])
                    
            m = max(prefix[u-1] , suffix[u+1])
            dp[i][1][u] = 1 +m 
            dp2[i][u] = max(dp[i][1][u] , dp2[i][u])
            j =2 
            while j<=i+1 : 
                dp[i][j][u] = max(dp[i][j][u] , dp[i-1][j-1][u]+j)
                dp2[i][u] = max(dp2[i][u], dp[i][j][u])
                j+=1
        for r in  range(1,27):
            prefix[r] = max(prefix[r-1] , dp2[i][r])
        for r in range(26,0,-1):
            suffix[r] = max(suffix[r+1] , dp2[i][r])

    ans = 0 

    for i  in range(1,27) : 
        for j  in  range(1 ,n+1):
            ans = max(ans , dp[n-1][j][i]) 
    return ans 









print(main())