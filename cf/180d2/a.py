import sys

n = int(sys.stdin.readline())
r = sys.stdin.readline()
print r.find('R') + 1 if 'R' in r else r.rfind('L') + 1, r.find('L') if 'L' in r else r.rfind('R') + 2
