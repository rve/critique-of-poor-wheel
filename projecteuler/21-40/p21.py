import math
def sum(n):
    ans = 0
    for i in range(1,int((n))):
        if n % i == 0:
            ans += i
    return ans

def cal():
    ans = 0
    for i in range(1, 10000):
        if sum(sum(i)) == i:
           ans += i

    print  ans

if __name__ == '__main__':
    print 'sum(220): ',sum(220),' and sum(284): ',sum(284)
    cal()
        
