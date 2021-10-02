# https://www.acmicpc.net/problem/2480

a=list(map(int,input().split(" ")))
a.sort()
if a[0]==a[2]:
    r=10000+a[0]*1000
elif a[0]==a[1]:
    r=1000+a[0]*100
elif a[1]==a[2]:
    r=1000+a[1]*100
else:
    r=a[2]*100
print(r)