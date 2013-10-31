import time
a = []
b = [[3],
[7,4],
[2,4,6],
[8,5,9,3]]

def solve(a):
   l = len(a)
   for i in range(l-2, -1,-1):
      for j in range(len(a[i])):
            a[i][j] += max(a[i+1][j],a[i+1][j+1])

   return  a[0][0]
            
         
if __name__ == '__main__':
   FILE = open("p18.in", "r")
   for blob in FILE : a.append([int(i) for i in blob.split(' ')])
   start = time.time()
   ans = solve(a)
   elapsed = time.time() - start
   print "%s found in %s seconds" %(ans, elapsed)
