import bisect 


INF = -10**8 
def  main():
    n = int(input())
    arr = [0] + list(map(int, input().split()))
    pref = [1e8 for _ in range(n+1)]
    pref[1] = arr[1]
    for i in  range(2,n+1):
        pref[i] = min(pref[i-1] , arr[i]) 
    ans = False

    st =[] 
    bk = INF
    count = 0 
    for j in range(n , 1  , -1 ):
        bj = arr[j] 
        bi = pref[j-1]

        while len(st) > 0 and st[-1] < bj :
            bk = max(bk, st[-1]) 
            st.pop()
        if bj > bk and bk > bi :
            count+=1
        st.append(arr[j])

    print(count)


main()


