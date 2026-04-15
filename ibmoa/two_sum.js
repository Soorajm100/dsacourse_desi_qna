




const arr = [1,2,3,4,5,6]




let start = 0 ; 
let target = 3 ; 
let end = arr.length ; 
let ans = -1 ; 



while(start<=end){
    let  mid = (start + end)/2 ; 

    if(arr[mid]===target){
        ans = mid ; 
        break ;
    }
    else if(arr[mid] > target){
        end = mid -1 ; 
    }
    else{
        start = mid +1 ; 
    }
}


console.log("element found at the pos" , ans)





s= "wqdwkmdkwmdke" 


d = s.split('')

console.log(d)


const ele = new Set() 

ele.add('a')

console.log(ele)