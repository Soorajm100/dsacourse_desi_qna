
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
    G = defaultdict(list)
    Goriginal = defaultdict(list)
    Q = int(input())

    arr = list(map(int, input().split()))

    for i in range(len(arr)):
        ele = arr[i]
        Goriginal[ele].append(i)
        G[ele].append(i)
    for key , value in G.items():
        a = value
        for i in range(1, len(a)):
            a[i] = a[i-1] +a[i]
        G[key] = a
    for i in range(Q):
        l,r, k ,y = map(int, input().split())
        ans = upper_bound(Goriginal[y] , l-1)
        if ans==-1 or ans+k-1>=len(G[y]) or G[y][ans+k-1] > r :
            print(-1)
        else:
            if ans-1>=0:
                print(G[y][ans+k-1] - G[y][ans-1])
        
        
main()




