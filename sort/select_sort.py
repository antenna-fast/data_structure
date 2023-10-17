a = [3,2,5,4,6,8,0]

num = len(a)

for l in range(num-1):
    for i in range(l+1, num): 
        if(a[l] > a[i]):
            tmp = a[l]
            a[l] = a[i] 
            a[i] = tmp

print(a)
