
start = input()
end = 'Neil Armstrong'

n = int(input())

edges = {}

for i in range(n):
	student, teacher = tuple(input().split(' -> '))
	if student not in edges: edges[student] = []
	edges[student].append(teacher)

queue = [start]
qcur = 0
prev = {}
done = False
while qcur < len(queue) and not done:
	popped = queue[qcur]
	qcur += 1
	for elem in edges[popped]:
		if elem not in prev:
			prev[elem] = popped
			queue.append(elem)
			if elem == end:
				done = True

print(end)
while end in prev:
	end = prev[end]
	print(end)