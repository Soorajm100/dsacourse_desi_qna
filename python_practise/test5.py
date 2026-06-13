
from  collections import defaultdict 


def  main():

    mp = defaultdict(int)

    arr = list(map(int, input().split()))

    n = len(arr)

    k =0 

    mp[0] = 1 

    pref =[0]*(n+1)
    pref[0] = arr[0]
    for i in range(1,n):
        pref[i] = pref[i-1] + arr[i]


    count = 0 
    for i in range(n):
        target= pref[i] 
        if target  in mp : 
            count +=mp[target] 
        mp[target]+=1

    return count


print(main())