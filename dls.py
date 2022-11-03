graph={
    'S':['A','B'],
    'A':['C','D'],
    'B':['I','J'],
    'C':['E','F'],
    'D':['G'],
    'I':['H'],
    'J':[]
}
def dls(start,goal,path,level,maxLimit):
    print('\nCurrent level -->',level)
    print('Goal node testing',start)
    path.append(start)
    if start==goal:
        print('Test successfull goal found')
        return path
    print('Goal node test failed')
    if level==maxLimit:
        return False
    print('Expanding current node:',start)
    for child in graph[start]:
        if dls(child, goal, path, level+1, maxLimit):
            return path
    return False
 
start='S'
goal=input('Enter goal:')
maxLimit=int(input("Enter max limit:"))
print()
path=list()
res=dls(start, goal, path, 0, maxLimit)
if(res):
    print('Path exists')
    print('Path',path)
else:
    print('Path does not exist')




