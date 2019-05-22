


def Sn(n):
    if n == 0:
        return 8
    else:
        prod = 1
        for _ in range(0,n):
            prod *= (Sn(_))/2
        return prod
