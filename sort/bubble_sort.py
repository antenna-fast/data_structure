a = [3,2,10,5,4,6,8,0]

num = len(a)

# we want to from small to big
for l in range(num-1, 0, -1):
    # print(l) # [num-1, ..., 1]
    for i in range(l):  # i: num-1, num-2, ..., 0
        if(a[i] > a[i+1]):
            tmp = a[i]
            a[i] = a[i+1]
            a[i+1] = tmp

print(a)
