a = int(input())
if a >= 2000 and a <= 9999:
    if a % 4 == 0 and a % 100 != 0:
        print("YES")
    elif a % 400 == 0:
        print("YES")
    else:
        print("NO")
