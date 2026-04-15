

import bisect 
import sys

INF = -10**8 
def  main():
    n = int(input())
    k = int(input())

    a = list(map(int, sys.stdin.readline().split())) #list(map(int, input().split()))
    b = [0]*(10**6) 
    
    for i in range(n) : 
        l = a[i] -k 
        r = a[i] + k 
        b[l] = b[l] +1 
        if r+1<=(10**6) : 
            b[r] = b[r] -1 
    ans = -1e6 
    for i in range(1,len(b)):
        b[i] = b[i-1] + b[i]
        ans = max(ans, b[i])
    print(ans)










main()