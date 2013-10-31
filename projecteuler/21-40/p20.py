def cal(i):
    acc = 0
    while i:
        i/=10
        acc+=i%10
    return acc
def fac(n):
    if n == 1: return 1
    else: return n*fac(n-1)

if __name__ == '__main__':
    print fac(100)
    print cal(fac(100))
