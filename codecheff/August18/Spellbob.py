t = int(input())
for _ in range(t):
    top = input()
    bottom = input()
    bAndo = 0
    b = 0
    o = 0
    for i in range(3):
        if  (top[i] == 'o' and bottom[i] == 'b') or (top[i] == 'b' and bottom[i] == 'o'):
            bAndo += 1
        elif top[i] == 'o' or bottom[i] == 'o':
            o += 1
        elif top[i] == 'b' or bottom[i] == 'b':
            b += 1
    if(bAndo == 3):
        print("yes")
    elif(bAndo == 2 and (b == 1 or o == 1)):
        print("yes")
    elif (bAndo == 1 and ( (b == 1 and o == 1) or (b == 2) )):
        print("yes")
    elif (b== 2 and o == 1):
        print("yes")
    else:
        print("no")
