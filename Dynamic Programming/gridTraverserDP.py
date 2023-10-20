"""Dynamic programming solution"""
"""Grid traverser problem"""

def gridTraverserDP(n , m , Dict = {}):
    if n==0 or m==0: return 0
    if n == 1 or m == 1: return 1 
    if((n,m) in Dict.keys()):
        return  Dict[(n,m)]
    Dict[(n,m)] = gridTraverser(n - 1,m) + gridTraverser(n,m - 1)
    return Dict[(n,m)]

def gridTraverser(n , m):
    if n==0 or m==0: return 0
    if n == 1 or m == 1: return 1 
    return gridTraverser(n - 1,m) + gridTraverser(n,m - 1)


def main():
    print(gridTraverserDP(18,18))

main()