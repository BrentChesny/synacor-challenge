import itertools

coins = ['2', '3', '5', '7', '9']

for c in itertools.permutations(coins):
	if eval("%s + %s * pow(%s, 2) + pow(%s, 3) - %s" % c) == 399:
		print c
