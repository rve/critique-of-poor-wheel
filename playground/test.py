#!/usr/bin/env python2.7
import os
def main() :
    elf1 = "./camelot_try3.o <input"
    elf11 = ".txt"
    elf2 = "cat ./ans/output"
    elf22 = ".txt"
    for i in range(19):
        print "Run #%d" % (i+1)
        os.system(elf1 + str(i+1) + elf11)
        os.system(elf2 + str(i+1) + elf22)

if __name__ == "__main__":
    
    main()
