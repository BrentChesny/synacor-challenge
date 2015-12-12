import sys
sys.setrecursionlimit(100000000)

def A(m, n, r7):
	a = [[0 for x in xrange(32768)] for y in xrange(m + 1)]

	for x in xrange(32768):
		a[0][x] = (x + 1) % 32768

	for x in xrange(1, m + 1):
		a[x][0] = a[x - 1][r7]
		for y in xrange(1, 32768):
			a[x][y] = a[x - 1][a[x][y - 1]]
	return a[m][n]

for i in xrange(1, 32768):
	result = A(4, 1, i)
	print i, result
	if result == 6:
		break
