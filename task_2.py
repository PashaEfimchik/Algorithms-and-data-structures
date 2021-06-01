def FuncMax(arr):
    arr.sort()
    max_1 = arr[0] * arr[1]
    max_2 = arr[-1] * arr[-2]
    return max(max_1, max_2)

N = int(input())
arr = list(map(int, input().split()[:N]))
print(FuncMax(arr))
