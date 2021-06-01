N, M, X1, Y1, X2, Y2 = map(int, input().split())

if abs(X1 - X2) != abs(Y1 - Y2):
    print("YES")
else:
    print("NO")
