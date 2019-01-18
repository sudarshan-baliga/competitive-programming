N, r = map(int, input().split())
for i in range(N):
    R = int(input())
    if R < r:
        print("Bad boi")
        continue
    print("Good boi")