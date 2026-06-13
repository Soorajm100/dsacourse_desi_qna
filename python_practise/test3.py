

def  main():
    n = int(input())
    k = int(input())
    maxi = 0 
    p=[0]*(10**5+5)

    for  i in range(1,n+1): 
        start, end = map(int, input().split())
        p[start] = p[start] + 1
        p[end+1] = p[end+1] - 1
        maxi = max(maxi , end) 
    

    for i in  range(1 , end+1):
        p[i] = p[i] + p[i-1] 
    
    for  i in range(1 , maxi+1): 
        if p[i] >= k :
            p[i] = 1 
        else :
            p[i] = 0 
    for i in  range(1 , end+1):
        p[i] = p[i] + p[i-1] 
    

    q = int(input())

    ans = [] 
    while q > 0 : 
        l , r = map(int, input().split())
        ans.append(p[r]  -p[l-1])
        q-=1
    return ans

    










print(main())
