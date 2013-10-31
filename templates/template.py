import time
data = []
def solve(a):
    return 0
if __name__ == '__main__':
   FILE = open("data.in", "r")
   for blob in FILE : data.append([int(i) for i in blob.split(' ')])
   start = time.time()
   ans = solve(a)
   elapsed = time.time() - start
   print "%s found in %s seconds" %(ans, elapsed)
