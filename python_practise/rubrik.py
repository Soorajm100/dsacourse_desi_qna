from  collections import defaultdict 

def main():
    n,x,y = map(int, input().split())
    b = [0] + list(map(int, input().split()))
    count = 0 
    mp = defaultdict(int)
    arr = [0]

    for i in range(1,n+1):
        if b[i]==x : 
            arr.append(1)
        elif b[i]==y:
            arr.append(-1)
    pref = [0]*(len(arr))
    pref[1] = arr[1]
    for  i in range(2,n+1):
        pref[i] = pref[i-1] + arr[i] 
    mp[0] = 1 
    for i in range(1 , n+1):
        target = pref[i] 
        count = count + mp[target]
        mp[target]+=1
    
    return count 


print(main())
