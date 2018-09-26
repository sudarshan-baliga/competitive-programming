t = int( input())
for i in range(t):
    n = int(input())
    if n == 1:
        print(1, 1)
    else:
        # first half should be equal to next half if it is a palindrome
        # probability that i th digit is equal to (n - i)th is 1 / 10
        half = int(n / 2)
        print(1, 10 ** half)