
def generateParentheses(n):
    L = []
    def backtrack(s = '', left = 0, right = 0):
        #print(f's is: {s}, left: {left}  right: {right}')
        if len(s) == 2 * n:
            L.append(s)
            print(s)
            return

        if left < n:
            print(f'* s is: {s}, left: {left}  right: {right}')
            backtrack(s + '(', left + 1, right)
        if right < left:
            print(f'** s is: {s}, left: {left}  right: {right}')
            backtrack(s + ')', left, right + 1)


    backtrack()
    return L
