
from collections import defaultdict
import sys


def  upper_bound(arr , target):
    start = 0
    end = len(arr)-1 
    ans = -1 

    while start <=end : 
        mid = (start + end)//2 
        if arr[mid] <=target : 
            start = mid+ 1 
        elif arr[mid] > target : 
            ans = mid 
            end = mid-1 
    return ans 



def  main():
    n = int(input())
    G = [[] for _ in range(10**5+1)]
    Q = int(input())

    arr = list(map(int, input().split()))

    for i in range(len(arr)):
        ele = arr[i] 
        G[ele].append(i)

    for i in range(Q):
        l,r, k ,y = map(int, input().split())
        ans = upper_bound(G[y] , l-1)
        if ans==-1 or ans+k-1>=len(G[y]) or G[y][ans+k-1] > r :
            print(-1)
        else:
            print(ans+k-1)
        
        

main()




