n = int(input())
s = []
for i in range(n):
    s.append(input())
q = int(input())
for i in range(q):
    a, p = input().split()
    a= int(a)
    preindex = -1
    S = sorted(s[0:a])
    stop = 0
    for i in range(a):
        index = 0
        curr = S[i]
        maxIndex = min(len(p), len(curr))
        if maxIndex >= preindex and curr[0:preindex] == p[0:preindex] or preindex == -1:
            while(index < maxIndex and p[index] == curr[index]):
             index += 1
        #print(curr, index ,preindex)
            if index > preindex:
                ans = curr
                preindex = index
            else:
                 stop  = 1
                 break
        else:
            break
        if stop == 1:
            break
    print(ans) 