# e = 32 * 4
# s = 32 * 4
# f = 1 / 4 / 2

e = 4
s = 4
f = 1 / 16

def emitNeighbor(n):
    return e + (n - s) * f

n_prev = 0
n = s
while(True):
    n_prev = n
    n = s + 4 * emitNeighbor(n_prev)
    if n_prev == n or n > 1000000:
        break

print(f"stable neutron number: {n}/t")
