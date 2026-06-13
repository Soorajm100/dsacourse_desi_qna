

from  collections import defaultdict 

def  main():
    n = int(input())


    arr =  list(map(int, input().split()))

    freq_arr = defaultdict(int)

    for  ele in  arr : 
        freq_arr[ele] += 1
    
    freq_value_arr = defaultdict(int)
    
    for freq , value in  freq_arr.items() : 
        freq_value_arr[value] += 1
    freq_final = []
    for freq , res  in  freq_value_arr.items() : 
        freq_final.append((freq))
    freq_final.sort(reverse=True)

    if len(freq_final) <= 1 : 
       return -1 
    
    second_freq_value = freq_final[1] if len(freq_final)>=1 else  0 
    final_arr = [ ]
    for ele , value in  freq_arr.items(): 
        if value == second_freq_value :
            final_arr.append(ele) 
    
    maxEele = -10**8 
    for ele in  final_arr : 
        maxEele = max(maxEele,ele)
    return maxEele






print(main())


    


    


