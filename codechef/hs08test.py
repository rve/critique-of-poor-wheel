
#getting re
def main():
    x, y = map(float, raw_input().split(" "))
    if x>0 and x < 2000 and y>0 and y < 2000 and x + 0.5 <= y and x % 5 == 0:
        print "%.2f" % (y-x-0.5)
    else:
        print "%.2f" % y

if __name__ == "__main__":
    main()
