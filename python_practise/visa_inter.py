
from collections import defaultdict
import sys


def  main():
    n = int(input())
    q = int(input())
    b =[]
    G= defaultdict()
    for  i in range(q):
        l,r = map(int, input().split())
        b.append((l,0))
        b.append((r,2))
    points = list(map(int, sys.stdin.readline().split())) 

    for i in range(len(points)):
        b.append((points[i] , 1))
    
    b.sort(key = lambda x : (x[0] , x[1]))
    c= 0 
    for i in  range(len(b)):
        point = b[i][0]

        if b[i][1]==0 :
            c=c+1
        elif b[i][1]==1:
            G[point] = c
        elif b[i][1]==2 : 
            c=c-1 
    
    for  i in range(len(points)):
        print(G[points[i]])


main()