def BFS(graph, starting):
    global node
    x = 0
    Visit = []
    newvisit = []
    depth = [0]
    newvisit.append(starting)

    while newvisit:
        x = newvisit.pop(0)
        tmp = depth.pop(0)
        if x not in Visit:
            if node[x] <= tmp:
                node[x] = tmp
            Visit.append(x)
            for i in range(0, len(graph[x])):
                depth.append(tmp+1)
            newvisit.extend(graph[x])
    return Visit

input_int = int(input())
input_string = input().split()
graph = {}
node = {}
depth = []

for a in range(0,input_int):
    tmplist = input().split()
    tmpNode = tmplist[0]
    node[tmpNode] = 0
    del(tmplist[0])
    tmplist.remove('$')
    graph[tmpNode] = tmplist

BFS(graph,input_string[0])
BFS(graph,input_string[1])
BFS(graph,input_string[2])
Result = 'Z'
MinValue = 100000
for j in node:
    if MinValue > node[j]:
        MinValue = node[j]
        Result = j
    elif Result > j and MinValue == node[j] :
        Result = j

print(Result)
print(1 + (node[Result] -1)* 3)
