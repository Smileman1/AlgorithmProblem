# https://www.acmicpc.net/problem/2525

a,b=map(int,input().split(" "))
c=int(input())
x=c//60
y=c%60
a+=x
b+=y
a+=b//60
b=b%60
a=a%24
print(a,b)