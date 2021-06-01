N = int(input())
seq = list(map(int, input().split()[:N]))

def func(s):
    ct = 0
    for j in range(1, len(s)):
        if s[j] > s[0]:
            ct += s[j] - s[0]
            s[0] = s[j]
        else:
            if s[j] < s[j-1]:
                ct += s[j-1] - s[j]
    return ct

print(func(seq))
