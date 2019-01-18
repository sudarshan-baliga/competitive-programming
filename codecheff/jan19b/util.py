n, p = map(int, input().split())
opti = 0
for i in range(1, p+1):
    for j in range(1, p+1):
        for k in range(1, p+1):
            temp = (((n % i) % j) %k) % n
            if temp > opti:
                opti = temp
count = 0
for i in range(1, p+1):
    for j in range(1, p+1):
        for k in range(1, p+1):
            temp = (((n % i) % j) %k) % n
            if temp == opti:
                # print(i, j, k)
                count += 1
print(opti, count)