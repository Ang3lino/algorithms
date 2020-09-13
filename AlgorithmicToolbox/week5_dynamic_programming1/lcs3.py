#Uses python3

import sys

def lcs3(a, b, c):
    m, n, p = len(a), len(b), len(c)
    dp = [[[0] * p for _ in range(n)] for _ in range(m)]  # matrix of dimension (m,n,p)
    for i in range(m):
        for j in range(n):
            for k in range(p):
                # print(a, b, c)   
                # print(i, j, k)   
                if a[i] == b[j] and b[j] == c[k]:
                    dp[i][j][k] = (0 if i + j + k == 0 else dp[i - 1][j - 1][k - 1]) + 1
                else:
                    dp[i][j][k] = max(dp[i - 1][j][k] if i > 0 else 0, 
                            dp[i][j - 1][k] if j > 0 else 0,
                            dp[i][j][k - 1] if k > 0 else 0)
    return dp[m - 1][n - 1][p - 1]

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    an = data[0]
    data = data[1:]
    a = data[:an]
    data = data[an:]
    bn = data[0]
    data = data[1:]
    b = data[:bn]
    data = data[bn:]
    cn = data[0]
    data = data[1:]
    c = data[:cn]
    print(lcs3(a, b, c))
