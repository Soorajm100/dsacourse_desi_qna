def dfs( node, gp , vis, parent , dp , color, c) : 
    vis[node] = True

    for x in  gp[node] : 
        if vis[x]==False : 
            parent[x] = node
            dfs(x , gp, vis,parent ,  dp , color, c)
    for x in  gp[node] : 
        if x!=parent[node]:
            dp[node] = dp[node]  + dp[x] + c[x]
            c[node] = c[node] + c[x]
    if color[node]==1:
        c[node] = c[node] +1 
    


def main():
    n = int(input())
    dp = [0]*(n+1)
    c =[0]*(n+1)
    color =[0]  + list(map(int,input().split()))
    vis =[0]*(n+1)
    parent=[-1]*(n+1)
    gp =[[] for _ in  range(n+1)]


    for i in range(n-1):
        x, y = map(int,input().split())
        gp[x].append(y)
        gp[y].append(x)
    
    dfs(1 , gp, vis, parent , dp , color , c)

    print(dp)
    


main()