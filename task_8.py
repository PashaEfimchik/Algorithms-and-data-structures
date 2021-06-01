def check_palindrom(s):
    return s == s[::-1]

def max_nepalindrom(str):
    flag = True
    for i in range(0, len(str) - 1):
        if str[i] != str[i + 1]:
            flag = False
            break
    if flag:
        return -1
    else:
        if check_palindrom(str):
            return len(str) - 1
        else:
            return len(str)
    
str = input()[:-1]
print(max_nepalindrom(str))
