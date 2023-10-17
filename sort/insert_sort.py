a = [3,2,10,5,4,6,8,0]

num = len(a)

for i in range(1, num):
    tmp = a[i]  # pick one

    # find correct insert_idx
    insert_idx = i
    while(insert_idx>0):
        if(a[insert_idx-1] > tmp):
            insert_idx -= 1
        else:
            break
    
    # move 
    for j in range(i, insert_idx, -1):
        a[j] = a[j-1]
    
    # insert    
    a[insert_idx] = tmp

print(a)
