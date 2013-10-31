one=[0,3,3,5,4,4,3,5,5,4] # one 3 two 3 three 5
two=[0,3,6,6,5,5,5,7,6,6] #ten, twenty thirty forty fifty sixty seventy eighty  ninty
eleven=[3,6,6,8,8,7,7,9,8,8]#ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen
def cal(i):
    a = i / 100
    b = (i - a*100) /10
    c = i % 10
    ans = 0
    if a != 0:
        if b == 0 and c == 0:
            ans += one[a] + 7 # hundred = 7
        else:
            ans += one[a] + 10 # hundred and = 10

    if b == 1:
        ans += eleven[c]
    else:
        ans += one[c] + two[b]

    return ans
if __name__ == '__main__':
    ans = 0
    for i in range(1,1000):
        ans += cal(i)

    ans += 3+8 # one thounsand
    print ans
    print 342,' ', cal(342)
    print 100, ' ', cal(100)
    print 370,' ',cal(370)
    print 10,' ',cal(10)
    print 50,' ',cal(50)
    print 35,' ', cal(35)
