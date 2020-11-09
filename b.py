
N = int(input())

program = [input().split() for i in range(N)]

mem = [0]*128;

def mod(k):
	k %= 256
	if k >= 128:
		k -= 256
	return k

def parseAddr(x):
	amps = 0
	while x[amps] == '&': amps += 1
	res = mod(int(x[amps:]))
	for i in range(amps):
		res = mod(mem[res])
	return res


while mem[0] != N-1:
	inst = program[mem[0]]
	cmd = inst[0]
	xa = inst[1]
	xb = inst[2]
	mem[0] = mod(mem[0]+1)
	if cmd == 'SET':
		mem[parseAddr(xa[1:])] = parseAddr(xb)
	if cmd == 'ADD':
		mem[parseAddr(xa[1:])] = mod(parseAddr(xa)+parseAddr(xb))
	if cmd == 'JMP':
		if parseAddr(xa) == 0:
			mem[0] = parseAddr(xb)
	if cmd == 'OUT':
		if parseAddr(xb)==0:
			print(chr(parseAddr(xa)),end='')
		else:
			print(parseAddr(xa),end='')


