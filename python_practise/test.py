
def  main():
    n = int(input())
    s = input()
    dp =[ [[-10**18 for i  in range(27)] for _ in  range(n+1)] for _  in range(n+1)]
    if s[0] == '.':
        for j  in  range(1,27):
            dp[0][1][j] = 1 ; 
    else:
        u  = ord(s[0]) - 97 
        u = u+1 
        dp[0][1][u] = 1 ; 
    
    for  i in range(1,n): 
        if s[i]=='.':
            u = 1 
            while u<=26:
                m = -10**18
                for p in range(1,27):
                    if p!=u:
                        for l in range(1,i+1) :
                            m = max(m , dp[i-1][1][p])
                dp[i][1][u] = 1 + m  
                j =2 
                while j<=i+1 : 
                    dp[i][j][u] = max(dp[i][j][u] , dp[i-1][j-1][u] + j) ; 
                    j+=1
                    
                u+=1
        else:
            u = ord(s[i]) - 97 
            u = u +1 
            m = -10**18 
            for p  in  range(1,27):
                if p!=u:
                    for l in  range(1,i+1):
                        m = max(m , dp[i-1][1][p])
            dp[i][1][u] = 1 +m 
            j =2 
            while j<=i+1 : 
                dp[i][j][u] = max(dp[i][j][u] , dp[i-1][j-1][u]+j)
                j+=1
            

    ans = 0 

    for i  in range(1,27) : 
        for j  in  range(1 ,n+1):
            ans = max(ans , dp[n-1][j][i]) 
    return ans 









print(main())