# https://www.acmicpc.net/problem/1024

taget, con = map(int, input().split(" "))
sum = 0
posobel = False
for x in range(con):
    sum += x
print(sum)
for x in range(con, con + (taget // con)):
    if (taget - sum) % x == 0:
        for y in range(x):
            print((taget - sum) // x + y, end=" ")
        posobel = True
        break
    else: sum += x
if not posobel:
    print(-1)