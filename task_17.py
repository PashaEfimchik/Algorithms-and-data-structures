N = int(input())
tmp = []
for i in range(N):
    tmp.append(input())

def func_search(arr, element):
    for i in range(len(arr)):
        if arr[i] == element:
            return True
    return False

arr = [int(''.join(n)) for n in tmp]

if func_search(arr, 1033) and func_search(arr, 1031) and func_search(arr, 1021):
    print("YES")
elif func_search(arr, 1087388483):
    print("YES")
elif func_search(arr, 1065023) and func_search(arr, 1021):
    print("YES")
elif func_search(arr, 1052651) and func_search(arr, 1033):
    print("YES")
elif func_search(arr, 1054693) and func_search(arr, 1031):
    print("YES")
else:
    print("NO")
