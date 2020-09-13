# Uses python3
import sys


def argmin(arr, f):
    min_i = -1
    min_fv = float('inf')
    for i, v in enumerate(arr):
        if f(v) < min_fv:
            min_fv = f(v)
            min_i = i
    return min_i 

# 0 => *3, 1 => *2, 3 => +1
def optimal_sequence(n):
    dp = [None] * (n + 1)
    dp[1] = []
    dp[2] = [1]  # or 3
    dp[3] = [0]
    for i in range(4, n + 1):
        choices = []
        if i % 3 == 0:
            choices.append((0, (dp[i // 3])))
        if i % 2 == 0:
            choices.append((1, (dp[i // 2])))
        choices.append((2, (dp[i - 1])))
        j = argmin(choices, lambda x: len(x[1]))
        dp[i] = [choices[j][0]] + choices[j][1]
    return dp[n]

input = sys.stdin.read()
n = int(input)
# n = 5
sequence = list(optimal_sequence(n))
print(len(sequence))
curr = 1
print(curr, end=' ')
for x in reversed(sequence):
    if x == 0:
        curr *= 3 
    if x == 1:
        curr *= 2
    if x == 2:
        curr += 1 
    print(curr, end=' ')
