


def convert_string_minutes(time_string):
    h1 = time_string[0]
    h2 = time_string[1]

    m1 = time_string[3]
    m2 = time_string[4]


    total = (int(h1)*10 + int(h2))*60 + int(m1)*10 + int(m2)
    return total 


def convert_minutes_string(minutes):
    hr = minutes//60
    mint = minutes%60
    ans =""
    if hr <=9 and mint <=9 : 
        ans = f"0{hr}:0{mint}"
    elif hr<=9:
        ans = f"0{hr}:{mint}"
    elif mint<=9:
         ans = f"{hr}:0{mint}"
    else:
        ans = f"{hr}:{mint}"
    return ans




def  main():

    n, k = map(int, input().split())
    arr = [0]*1440
    time_arr =[] 
    for i in range(n):
        name , work, start_string , end_string = map(str , input().split())
        starttimeminutes = convert_string_minutes(start_string)
        endtimeminutes = convert_string_minutes(end_string)
        
        for i in range(starttimeminutes ,endtimeminutes+1 ):
            arr[i] = arr[i] +1 
    count= 0 
    ans = -1
    ans_string =""
    for i in range(0,1440):
        if arr[i]==0:
            count+=1
            if count==k:
                ans = i-k+1
                ans_string = convert_minutes_string(ans)
                break
                
        else:
            count = 0 
        
    return ans_string



    




print(main())