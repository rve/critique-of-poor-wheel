import datetime

months=[0,31,28,31,30,31,30,31,31,30,31,30,31]
def leap(i):
    #if i%400 == 0  or (i%4==0 and i%100!=0): return 1
    if i%4 == 0 and (i%100 != 0 or i%400 == 0): return 1
    else: return 0

def cal(r):
    acc=0
    ans=0
    for i in range(1900,r):
        for m in range(1,13):
            # or use  lib func
#            d = datetime.date(i,m,1)
#            if d.weekday() == 6:
            if  acc % 7 == 6:
                 ans += 1
            acc += months[m]
            if m==2:
                acc += leap(i)
    return ans
if __name__ == '__main__':
    print cal(2001) - cal(1901)


