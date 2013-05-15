def repeat(s, ex) :
    s = s * 3
    if ex:
        s += "!!!"
    return s
if __name__ == "__main__" :
    print repeat("Yooo", True)
    print repeat("Yummy", False)
    s = 'hi'
    print s[1]
    print s
    pi = 3.1415
    print "pi: " + str(pi)
    list = []
    list.append('a')
    list.append('b')
    print list
