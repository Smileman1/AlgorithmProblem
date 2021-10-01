# https://www.acmicpc.net/problem/2163

a,b=map(int,input().split())
if a>b:
    big=a
    small=b
else :
    big=b
    small=a
print((small-1)+(big-1)*small)