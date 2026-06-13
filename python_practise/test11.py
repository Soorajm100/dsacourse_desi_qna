from collections import deque





def  main():

    arr = list(map(int, input().split()))
    maxProduct = max(arr)
    minProduct = min(arr)
    for i  in  range(len(arr)) : 
        if maxProduct == arr[i] : 
            start = i 
            break  
    
    for i in range(len(arr)) : 
        if minProduct == arr[i] : 
            end = i 
            break 
    
    #circular array  concept 

    q = deque()

    total_cost_final = 10**9
    n = len(arr)

    if start  < end : 
        avg = sum(arr)//len(arr)
        total_cost = 0 

        for  i  in  range(start , end+1):
            if arr[i] > avg : 
                q.append((abs(arr[i] - avg) , i))
            else :
                # poor product 
                cost = abs(arr[i] - avg) 
                while  cost > 0  and q: 
                    if q[0][0] > cost : 
                        q[0] = (q[0][0] - cost , q[0][1])
                        total_cost += ( (i - q[0][1] + n)%n)
                        cost = 0
                    else : 
                        cost-=q[0][0]
                        total_cost += ((i - q[0][1] + n)%n)
                        q.popleft()
        
        # go  backwards in a cycle 
        total_cost_final = min(total_cost , total_cost_final) 
        total_cost = 0 
        i = start
        print("in if")
        print("one possibility" , total_cost)
        while i!=end : 
            i = (i-1+n)%n
            if arr[i] > avg : 
                q.append((abs(arr[i] - avg) , i))

            else :
                # poor product 
                cost = abs(arr[i] - avg) 
                while  cost > 0  and q: 
                    if q[0][0] > cost : 
                        q[0] = (q[0][0] - cost , q[0][1])
                        total_cost += ( (i - q[0][1] + n)%n)
                        cost = 0
                    else : 
                        cost-=q[0][0]
                        total_cost += ( (i - q[0][1] + n)%n)
                        q.popleft()
        print("one possibility" , total_cost)
        total_cost_final = min(total_cost , total_cost_final) 
    else  : 

        avg = sum(arr)//len(arr)

        total_cost = 0 
        

        for  i  in  range(start , end , -1 ):
            if arr[i] > avg : 
                q.append((abs(arr[i] - avg) , i))
            else :
                # poor product 
                cost = abs(arr[i] - avg) 
                while  cost > 0  and q: 
                    if q[0][0] > cost : 
                        q[0] = (q[0][0] - cost , q[0][1])
                        total_cost += ( (i - q[0][1] + n)%n)
                        cost = 0
                    else : 
                        cost-=q[0][0]
                        total_cost += ( (i - q[0][1] + n)%n)
                        q.popleft()
            # go  backwards in a cycle 
        total_cost_final = min(total_cost , total_cost_final)
        print("in else")
        print("one possibility" , total_cost)
        total_cost = 0
        i = start
        n = len(arr)
        while i!=end : 
            i = (i+1+n)%n
            if arr[i] > avg : 
                q.append((abs(arr[i] - avg) , i))
            else :
                # poor product 
                cost = abs(arr[i] - avg) 
                while  cost > 0 : 
                    if q[0][0] > cost : 
                        q[0] = (q[0][0] - cost , q[0][1])
                        total_cost += ( (i - q[0][1] + n)%n)
                        cost = 0
                    else : 
                        cost-=q[0][0]
                        total_cost += ( (i - q[0][1] + n)%n)
                        q.popleft()
        total_cost_final = min(total_cost , total_cost_final)
        print("one possibility" , total_cost)
    return total_cost_final

        
                        
print(main())

                