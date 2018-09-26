t = int(input())
for i in range(t):
    n = int(input())
    totalSellPrice = float(0.0)
    for j in range(n):
        temp = float(0.0)
        p, q, d = map(int, input().split())
        temp += (p +  (d * p) / 100) 
        temp -= (temp * d) / 100
        totalSellPrice +=  q * (p - temp)
    print(totalSellPrice)
