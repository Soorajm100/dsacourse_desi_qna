
import sys 
sys.setrecursionlimit(10**7)


INF = -10**18
def  dfs(i ,j ,dir, dp , arr , n , m ):
    if i< 0 or i>=n or j<0 or j>=m: 
        return INF
    
    if arr[i][j]==1 : 
        return INF
    
    if dp[i][j][dir]!=0:
        return dp[i][j][dir]
    
    if i==0 and j==0 : 
        if dir ==0 : 
            dp[i][j][dir] = 1 
            return 1 
        if dir ==2 : 
            dp[i][j][dir] = 1 
            return 1 
        if dir ==1 : 
            dp[i][j][dir]= INF 
            return INF
    if dir ==0 : 
        dp[i][j][dir]= 1 + max(dfs(i , j-1 , 0 , dp, arr , n  , m ) ,dfs(i , j-1 , 2 , dp, arr , n  , m )  )
    if dir== 2 :
        dp[i][j][dir]= 1 + max(dfs(i-1 , j , 0 , dp, arr , n  , m ) ,dfs(i-1 , j , 2 , dp, arr , n  , m )  , dfs(i-1 , j , 1 , dp, arr , n  , m ) )
    if dir ==1 : 
        dp[i][j][dir]= 1 + max(dfs(i , j+1 , 1 , dp, arr , n  , m ) ,dfs(i , j+1 , 2 , dp, arr , n  , m )  )
    
    return dp[i][j][dir]


def  main(): 
    n, m = map(int, input().split())

    arr = [[0]*m for _ in  range(n)]

    for i in  range(n): 
        row = input().strip()
        for j in  range(m):
            if row[j]=='.':
                arr[i][j] = 0 
            else:
                arr[i][j] = 1

    dp = [[[0]*3 for _ in  range(m)] for _ in range(n)]


    ans = max(dfs(n-1, m-1, 0 , dp, arr , n , m) , dfs(n-1, m-1, 2 , dp, arr , n , m))

    print(ans)

if __name__=="__main__":
    main()


