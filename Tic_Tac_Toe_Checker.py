board = [[1, 2, 3],
         [4, 5, 6],
         [7, 8, 9]]

a = set()
a.add(1)
b = set()
b.add(2)

L = []
for i in board:
    L.append(i)

for i in range(len(board[0])):
    l = []
    for j in range(len(board)):
        l.append(board[j][i])
        print(l, '***')
    L.append(l)

l = []
for i in range(len(board)):
    l.append(board[i][i])
L.append(l)

l = []
for i in range(len(board)):
    l.append(board[i][len(board) - i - 1])

L.append(l)

print(L)

##for line in L:
##    if set(line) == a:
##        return 1
##    elif set(line) == b:
##        return 2
##
##for line in L:
##    if 0 in line:
##        return -1
##
##
##return 0
