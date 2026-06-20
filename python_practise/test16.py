from  collections import defaultdict



def main() : 

    mp = defaultdict(int)
    arr = list(map(int, input().split()))
    k = int(input())
    n = len(arr)
    pref = [0 for _ in range(n+1)]

    pref[0] = arr[0]
    count = 0 

    for i in range(1,n):
        pref[i] = pref[i-1] + arr[i] 
    
    for  i  in range(n):
        target = pref[i] - k 

        if target in  mp : 
            count +=mp[target]
        
        mp[pref[i]]+=1
    return count 



print(main())