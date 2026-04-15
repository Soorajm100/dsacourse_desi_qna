from  collections import defaultdict


def  main():
    cv = 0
    cw = 0
    cx = 0 
    cy = 0
    cz = 0 
    
    n = int(input())
    v,w,x,y,z = map(int,input().split())
    arr = [0] + list(map(int, input().split()))
    mp = defaultdict(int)
    mp[(0,0,0,0)] = 1
    count = 0 
    for i in range(1,n+1):
        ele = arr[i] 
        if ele == v : 
            cv+=1
        elif ele== w:
            cw+=1
        elif ele==x : 
            cx+=1
        elif ele==y:
            cy+=1
        elif ele==z:
            cz+=1
        temparr = (cv - cw , cw-cx , cx - cy , cy-cz)
        count = count + mp[temparr]
        mp[temparr]+=1
    return count


print(main())