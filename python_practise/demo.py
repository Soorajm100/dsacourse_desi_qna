from  collections import defaultdict



def main():

    n = int(input()) 
    arr = [0] + list(map(int, input().split()))
    k = int(input())
    pref = [0]*(n+1)
    pref[1] = arr[1]
    mp_count = defaultdict(int)
    mp_ind = defaultdict(int)
    mp_ind[0] =0 
    mp_ind[pref[1]] = 1
    for  i in range(2, (n)+1):
        pref[i] = pref[i-1] + arr[i]
        mp_ind[pref[i]] = i 
    
    mp_count[0] = 1 
    count = 0 
    length = 10**8 
    for i in range(1,n+1):
        target = pref[i] -k 
        if target in  mp_count :
            targetInd = mp_ind[target]
            if i-targetInd<=length:
                count+= mp_count[target] 
                length = i-targetInd
        mp_count[pref[i]]+=1
    
    return count 




print(main())