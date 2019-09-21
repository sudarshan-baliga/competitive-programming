a = [[1,2,3], [4, 5, 6]]
for i in range(2):
    for j in range(3):
        print(a[i][j], end ='')
        if(j != 3):
            print(' ', end = '')
    print()