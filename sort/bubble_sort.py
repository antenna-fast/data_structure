a = [3,2,10,5,4,6,8,0]

num = len(a)

# we want to from small to big
for l in range(num-1):
    for i in range(num-1):
        if(a[i] > a[i+1]):
            tmp = a[i]
            a[i] = a[i+1]
            a[i+1] = tmp

print(a)
