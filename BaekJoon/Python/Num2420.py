# https://www.acmicpc.net/problem/2420

a,b=map(int,input().split(" "))
print(a-b if a>b else b-a)