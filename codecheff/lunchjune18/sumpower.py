t = int(input())
for _ in range(t):
    n , k = map(int, input().split())
    s = input()
    ans = 0
    if float(n/k) > 1:
        if float(n/k) <= 2.0 :
            for i in range(1, k):
                if(s[i] != s[i-1]):
                    if( n - i - 1 >= k):
                        ans += i
                else:
                    ans += n - i - 1
        else:
        
    # if float(n / k) > 1:
    #     if  float(n / k) >= 2.0:
    #         for i in range(1, k):
    #             if(s[i] != s[i-1]):
    #                 if( n - i - 1 >= k):
    #                     ans += i
    #                 else:
    #                     ans += n - i - 1
    #     print(1, ans)
    #     if float(n / k) > 2.0:
    #         print("hi2")
    #         for i in range(k, n - k):
    #             if(s[i] != s[i-1]):
    #                 if( n - i - 1 >= k):
    #                     ans += k
    #                 else:
    #                     ans += n - i - 1
    #     # print(2, ans)
    #     if  float(n / k) > 1.0:
    #         print("hi")
    #         for i in range( n - k, n):
    #             if(s[i] != s[i-1]):
    #                 ans += n - i
    # print(ans)
