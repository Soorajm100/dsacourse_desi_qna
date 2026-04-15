from  collections import defaultdict 
 
def  main():
    n = int(input())
    a = [0] + list(map(int,input().split())) 
    b = [0] + list(map(int,input().split()))

    k = int(input()) 

    dt = defaultdict(int)

    for i in range(1,n+1):
        dt[b[i]] = a[i]
    print(dt)
    b.sort(reverse =True)
    print(b)
    sumd = 0 
    l = 0 
    while k > 0 and l <n :
        print(f"Current k: {k}, current item: {b[l]}, current value: {dt[b[l]]}")
        if k>=dt[b[l]]:
            sumd+= dt[b[l]]*b[l]
            print(f"Using item {b[l]} with value {dt[b[l]]}")
            k-=dt[b[l]]
        else:
            sumd+= k*b[l]
            print(f"Using item {b[l]} with value {k}")
            k = 0
        l+=1 
    
    return sumd 
    
print(main())