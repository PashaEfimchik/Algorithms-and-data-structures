from itertools import permutations
num = int(input())
arr = [int(''.join(n)) for n in permutations(str(num))]
def func(arr):
    if num > 10:
        for i in arr:
            if i > num:
                return i
    return -1
tmp = []
for i in range(len(arr)):
    mn = min(arr)
    arr.remove(mn)
    tmp.append(mn)
tmp.extend(arr)
print(func(tmp))
