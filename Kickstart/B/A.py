# https://code.google.com/codejam/contest/2929486/dashboard#s=p0
def checkAllLines(grid,limit,flag):
	for row in range(limit):
		unique=set()
		for col in range(limit):
			if flag:
				temp=grid[row][col] #checking rows
			else:
				temp=grid[col][row] #checking cols
			if temp>=1 and temp<=limit and temp not in unique:
				unique.add(temp)
			else:
				return False
	return True

def checkAllBoxes(grid,limit,N):
	x=0
	y=0
	while x<limit:
		while y<limit:
			# x,y to <x+N,<y+N check
			unique=set()
			for row in range(x,x+N):
				for col in range(y,y+N):
					temp=grid[row][col]
					if temp>=1 and temp<=limit and temp not in unique:
						unique.add(temp)
					else:
						return False
			y+=N
		x+=N
	return True

def verify(grid,N):
	limit=N**2
	
	if checkAllLines(grid,limit,True) and checkAllLines(grid,limit,False) and checkAllBoxes(grid,limit,N):
		return "Yes"
	return "No"

t=int(input())
for _ in range(t):
	N=int(input())
	grid=[]
	for x in range(N**2):
		arr=[int(x) for x in input().split()]
		grid.append(arr)
	print("Case #{}: {}".format(_+1,verify(grid,N)))