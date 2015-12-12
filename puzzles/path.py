grid = [['22', '-', '9', '*'],
		['+', '4', '-', '18'],
		['4', '*', '11', '*'],
		['*', '8', '-', '1']]

steps = [(0,1), (1,0), (0,-1), (-1,0)]

def compute(i, j, e, path):
	if i > 3 or i < 0 or j > 3 or j < 0 or len(path) > 14:
		return

	if grid[i][j].isdigit():
		e = str(eval(e + grid[i][j]))
	else:
		e = e + grid[i][j]

	if (i, j) == (3, 3):
		if eval(e) == 30:
			print path[1:]
		return 

	if (i+1,j) != (0,0):
		compute(i+1, j, e, path + [(i,j)])
	if (i,j+1) != (0,0):
		compute(i, j+1, e, path + [(i,j)])
	if (i-1,j) != (0,0):
		compute(i-1, j, e, path + [(i,j)])
	if (i,j-1) != (0,0):
		compute(i, j-1, e, path + [(i,j)])

compute(0, 0, "", [(0,0)]) 