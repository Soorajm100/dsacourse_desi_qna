




def  solve() :

    s = input()
    n = len(s)

    dp = [[0 for _ in  range(n)] for _ in  range(n)]
    dp1 = [[0 for _ in  range(n)] for _ in  range(n)]
    i = 0 

    # length 1 string
    while i < n : 
        dp[i][i] = 1 
        dp1[i][i] = 1 
        i+=1
    

    i = 0 

    # length 2  string 
    while i<n-1 : 
        if s[i]==s[i+1]:
            dp[i][i+1] = 1 
        else : 
            dp[i][i+1] = 0 ; 
        dp1[i][i+1] = dp1[i][i] + dp1[i+1][i+1] + dp[i][i+1] 
        i+=1
    

    # you know that s[i] == s[j] and yu know that i+1 to  j-1 you knoe it is plaindrome
    #then  it is a plaindrome from i to j 


    # length 3 ... n  string 

    length = 3 
    while length <=n : 
        i = 0 

        while  i< n-length+1 : 
            j = i + length -1 

            if s[i] ==s[j] and dp[i+1][j-1] ==1 : 
                dp[i][j] = 1 
            
            dp1[i][j] = dp1[i][j-1] + dp1[i+1][j] - dp1[i+1][j-1] + dp[i][j] 
            i+=1
        length+=1
    q = int(input())

    for k in  range(q) : 
        l ,r = map(int, input().split())
        print(dp1[l][r]) 



solve()