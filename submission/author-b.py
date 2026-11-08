def main():
    n, k = list(map(int, input().split()))
    A = input()
    B = input()
    dp = [0] * 4
    for i in range(n):
        a, b = int(A[i]), int(B[i])
        dp[a*2+b] += 1
    f = 0
    for _ in range(k):
        if dp[1] == dp[2] == 0:
            return "Yes"
        if dp[1]:
            dp[1] -= 1
            dp[3] += 1
        else:
            dp[2] -= 1
            dp[0] += 1
        if f:
            f = 0
        else:
            if dp[0]:
                dp[0] -= 1
                dp[1] += 1
            else:
                dp[3] -= 1
                dp[2] += 1
                f = 1
    else:
        return "No"

for _ in range(int(input())):
    print(main())
