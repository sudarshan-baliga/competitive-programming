t = int(input())
for _ in range(t):
    s = input()
    l = len(s)
    preFreq = [0] * 26 #number of chars which are less than current char and are already considered
    answers = [0] * 26 #number of s[j] which are greater than s[i]
    bestCase = 0
    bestPos = -1
    for i in range(l):
        pos = ord(s[i]) % 97
        preFreq[pos] += 1
        # find the number of chars which are less than current char
        j = 0
        lessThan = 0
        removed = 0
        while(j != pos):
            if(preFreq[j] > 0):
                lessThan += preFreq[j]
            j += 1
        for j in range(pos - 1, -1 , -1):
            if(preFreq[j] > 0):
                answers[j] += preFreq[j]
            if(pos - j - preFreq[j] - removed  < bestCase):
                bestPos = i
                bestCase = pos - j - preFreq[j] - removed 
                cost = pos - j
            # print(pos - j - preFreq[j] - removed , bestCase, lessThan, removed)
            removed += 1
    # print(answers)
    ans = 0
    ansWithoutChange = 0
    for j in range(26):
        ansWithoutChange += answers[j]
    # if there is a best case
    if(bestPos != -1):
        for j in range(0, bestPos):
            if(s[j] < s[bestPos]):
                answers[ord(s[j]) % 97] -= 1
        ans += cost
        #decrease the answers if j > bestPos and s[j] > changed char
        bestChar = chr(ord(s[bestPos]) -  cost)
        for j in range(bestPos + 1, l, 1):
            if(s[j] > bestChar and s[bestPos] >= s[j]):
                answers[bestPos] += 1
    # add all answers
    for j in range(26):
        ans += answers[j]
    print(min(ans, ansWithoutChange))
            
