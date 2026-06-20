





def main():
    s = input()
    print(s)
    n = len(s)

    dp = [[0 for _ in range(n)] for _ in  range(n)] 
    dp1 = [[0 for _ in range(n)] for _ in  range(n)]


    for i in  range(n): 
        dp[i][i] = 1 
        dp1[i][i] = 1 
    

    for i in range(n-1) : 
        if s[i] == s[i+1] : 
            dp[i][i+1] = 1 
            dp1[i][i+1] = 3 
        else : 
            dp1[i][i+1] = 2 
    

    for lent in  range(3, n+1):
        for i  in  range(n-lent+1) : 
            j = i + lent -1 
            if s[i] ==s[j] and dp[i+1][j-1]==1 : 
                dp[i][j] = 1
            dp1[i][j]= dp1[i+1][j] + dp1[i][j-1] - dp1[i+1][j-1]  + dp[i][j] 
    ddpp = [0 for _ in range(n)]

    for i in  range(n) : 
        j = i 
        b= 0 

        while j >=0 : 
            if dp[j][i] ==1 : 
                b+=1 
            j-=1
        if i+1 < n : 
            rest = dp1[i+1][n-1]
            val = b*rest 
            ddpp[i] = val
    
    ddpt = [0 for _ in range(n)]

    for i  in  range(n) : 
        j = i 
        b = 0 

        while j>=0 : 
            if dp[j][i]==1 : 
                b+=1
            j-=1
        rest = 0 

        if i+1 < n : 
            for k in  range(i+1 , n):
                rest+=ddpp[k]
            val = b*rest
            ddpt[i] = val
    
    total = 0 
    for  i in  range(n) : 
        total+=ddpt[i]
    totalDuplet = 0 
    for i in  range(n) : 
        totalDuplet+=ddpp[i]
    

    return [total , totalDuplet]








print(main())