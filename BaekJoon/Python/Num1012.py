# https://www.acmicpc.net/problem/1012

def o(i,j):
    if l[i + 1][j] == 1:
        que.append([i + 1, j])
        l[i+1][j]=0
    if l[i - 1][j] == 1:
        que.append([i - 1, j])
        l[i-1][j]=0
    if l[i][j + 1] == 1:
        que.append([i, j + 1])
        l[i][j+1]=0
    if l[i][j - 1] == 1:
        que.append([i, j - 1])
        l[i][j-1]=0
    l[i][j] = 0
    while que!=[]:
        tmp=que.pop(0)
        i=tmp[0]
        j=tmp[1]
        if l[i+1][j]==1:
            que.append([i+1,j])
            l[i + 1][j] = 0
        if l[i-1][j]==1:
            que.append([i-1,j])
            l[i - 1][j] = 0
        if l[i][j+1]==1:
            que.append([i,j+1])
            l[i][j + 1] = 0
        if l[i][j-1]==1:
            que.append([i,j-1])
            l[i][j - 1] = 0
        l[i][j]=0
    return
a=int(input())
if a==0:
    print("0")
l=list()
q=list()
que=list()
count=0
for x in range(a):
    b, c, d = map(int, input().split())
    for y in range(b+2):
        l.insert(y,list())
        for z in range(c+2):l[y].insert(z,0)
    for y in range(d):
        i,j=map(int,input().split())
        l[i+1][j+1]=1
    for y in range(b+2):
        for z in range(c+2):
            if(l[y][z]==1):
                o(y,z)
                count+=1
    l=list()
    q.insert(x,count)
    count=0
for x in q:print(x)