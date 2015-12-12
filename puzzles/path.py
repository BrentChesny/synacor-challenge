import random

grid = [['22', '-', '9', '*'],
		['+', '4', '-', '18'],
		['4', '*', '11', '*'],
		['*', '8', '-', '1']]

steps = [(0,1), (1,0), (0,-1), (-1,0)]

def compute(i, j, e, path):
	if i > 3 or i < 0 or j > 3 or j < 0 or len(path) > 14:
		return

	if grid[i][j].isdigit():
		newe = str(eval(e + grid[i][j]))
	else:
		newe = e + grid[i][j]

	if (i, j) == (3, 3):
		#print newe
		if eval(newe) == 30:
			print path
		return 

	if (i+1,j) != (0,0):
		compute(i+1, j, newe, path + [(i,j)])
	if (i,j+1) != (0,0):
		compute(i, j+1, newe, path + [(i,j)])
	if (i-1,j) != (0,0):
		compute(i-1, j, newe, path + [(i,j)])
	if (i,j-1) != (0,0):
		compute(i, j-1, newe, path + [(i,j)])

compute(0, 0, "", [(0,0)])

# def compute():
# 	i, j = (0, 0)
# 	path = []
# 	expr = ""

# 	while (i, j) != (3, 3):
# 		path += [(i, j)]
# 		if grid[i][j].isdigit():
# 			expr = str(eval(expr + grid[i][j]))
# 		else:
# 			expr = expr + grid[i][j]

# 		while True:
# 			step = steps[random.randint(0,3)]
# 			newi = i + step[0]
# 			newj = j + step[1]
# 			if newi < 0 or newi > 3 or newj < 0 or newj > 3 or (i == 0 and j == 0):
# 				continue
# 			break

# 		i = newi
# 		j = newj

# 	path += [(i, j)]
# 	if grid[i][j].isdigit():
# 		expr = str(eval(expr + grid[i][j]))
# 	else:
# 		expr = expr + grid[i][j]

# 	return eval(expr), path



# while True:
# 	result, path = compute()
# 	if result == 30:
# 		print path





















# grid = [
# 	['1', '-', '8', '*'],
# 	['*', '11', '*', '4'],
# 	['18', '-', '4', '+'],
# 	['*', '9', '-', '22'],
# ]

# import operator
# import random

# delta_x = [-1, 0, 1, 0]
# delta_y = [0, -1, 0, 1]
# directions = [
# 	'east',
# 	'north',
# 	'west',
# 	'south',
# ]

# ops = {
# 	'+': operator.add,
# 	'-': operator.sub,
# 	'*': operator.mul,
# }

# def random_walk():
# 	x, y = 3, 3
# 	current = 0
# 	op = operator.add
# 	expr = ''
# 	moves = []
# 	while x or y:
# 		ch = grid[y][x]
# 		expr += ch
# 		if ch in '+-*':
# 			op = ops[ch]
# 		else:
# 			current = op(current, int(ch))
# 			if current <= 0:
# 				return 0, expr, moves

# 		while True:
# 			idx = random.choice(xrange(4))
# 			new_x, new_y = x + delta_x[idx], y + delta_y[idx]
# 			if new_x >= 0 and new_y >= 0 and new_x < 4 and new_y < 4 and not (new_x == 3 and new_y == 3):
# 				x, y = new_x, new_y
# 				moves.append(directions[idx])
# 				break

# 	assert x == 0 and y == 0
# 	current = op(current, int(grid[0][0]))
# 	expr += grid[0][0]
# 	return current, expr, moves

# while True:
# 	res, expr, moves = random_walk()
# 	if res == 30 and len(moves) < 14:
# 		print len(moves)
# 		print expr
# 		for m in moves:
# 			print 'go ' + m
# 		break