


def  solve():
    n = int(input())
    s1 = input()
    s2 = input()
    dp = [0]*(n+1)

    if n == 1:
        print(0 if s1[0] == s2[0] else 1)
        return

    c1 = 0 
    c2 = 0 

    if s1[0]==s2[0] : 
        dp[0] = 0
    else:
        dp[0] = 1
        c1+=1

    if s1[1]!=s2[1]: 
        c1+=1 
    
    if n>=2 : 
        if s1[0]!=s1[1] : 
            c2+=1 
        if s2[0]!=s2[1] : 
            c2+=1 
    dp[1] = min(c1,c2)

    for  i in  range(2,n): 
        v1=  0
        v2 = 0 
        if s1[i]!=s2[i]:
            v1+=1 
        if s1[i]!=s1[i-1]:
            v2+=1
        if s2[i]!=s2[i-1]:
            v2+=1
        dp[i] = min(dp[i-1]+v1,dp[i-2]+v2)
    print(dp[n-1])
    return 




if __name__ == "__main__":
    t = int(input())
    while t:
        solve()
        t -= 1
    