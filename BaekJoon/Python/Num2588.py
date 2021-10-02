# https://www.acmicpc.net/problem/2588

a=int(input())
b=input()
c=len(b)
for x in range(c):
    print(int(b[c-x-1])*a)
print(a*int(b))