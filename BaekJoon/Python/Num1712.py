# https://www.acmicpc.net/problem/1712

a,b,c=map(int,input().split(" "))
print(-1 if b>=c else a//(c-b)+1)