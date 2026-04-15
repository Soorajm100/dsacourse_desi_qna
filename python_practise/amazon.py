import bisect 

def  main():
    n = int(input())
    arr = [0] + list(map(int, input().split()))
    pref = [1e8 for _ in range(n+1)]
    pref[1] = arr[1]
    for i in  range(2,n+1):
        pref[i] = min(pref[i-1] , arr[i]) 
    ans = False

    st =[] 
    bisect.insort(st , arr[n])

    for j  in  range(n-1 , 1 ,-1) : 
        arrj = arr[j]
        arri = pref[j-1]

        idx = bisect.bisect_right(st , arri )
        if idx< len(st):
            arrk = st[idx]
            if arrj > arrk and arrk > arri : 
                ans =True
                break 
        bisect.insort(st, arr[j])
    print(ans)




main()


