



def  main():
    n  = int(input())
    b = [0] +  list(map(int, input().split()))
    left = [0 for _ in range(n+1)]

    right = [0 for _ in range(n+1)]

    valley = [0 for _ in range(n+1)]

    left[1] = 1 

    for i  in range(2 , n+1): 
        if b[i] < b[i-1] : 
            left[i] = left[i-1]+ 1 
        else : 
            left[i]= 1 
    

    right[n] = 1 

    for i in range(n-1 , 0 , -1):
        if b[i] < b[i+1] : 
            right[i] = right[i+1]+ 1
        else :
            right[i] = 1
    
    sumy = 0 

    for i in range(1,n+1):
        valley[i] = (left[i] -1)*(right[i] -1)   
        sumy += valley[i]
    

    return sumy 



print(main())