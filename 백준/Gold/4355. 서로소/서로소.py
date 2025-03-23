while (True):
    a = int(input())
    res = a

    if (a == 0):
        break;
    if (a == 1):
        print(0)
        continue

    i = 2
    while i * i <= a:
        if a % i == 0:
            while a % i == 0:
                a //= i
            res *= (1 - 1/i)
        i += 1

    if a > 1:
        res *= (1 - 1/a)
    
    print(int(res))
    

