# https://www.acmicpc.net/problem/1009

a=int(input())
b=list()
for x in range(a):
    b.append(list(map(int,input().split(" "))))
c=[[1,10],[1,1],[4,2,4,8,6],[4,3,9,7,1],[2,4,6],[1,5],[1,6],[4,7,9,3,1],[4,8,4,2,6],[2,9,1]]
for x in range(a):
    d=b[x][0]%10
    print(c[d][(b[x][1]-1)%c[d][0]+1])