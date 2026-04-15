
from collections import defaultdict 


n, k = map(int, input().split())
a = [0] + list(map(int, input().split()))

prefix = [0]*(n+1)


for i in  range(1,n+1):
    prefix[i] = prefix[i-1] + a[i] 

mp = defaultdict(int)

mp[0] = 1 
count = 0 

for j in range(1 , n+1) : 
    target = (prefix[j]%k -j%k +k)%k 
    count = count + mp[target]
    mp[target]+=1

print(count)

