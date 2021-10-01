# https://www.acmicpc.net/problem/1297

import math
a,b,c=map(int,input().split(" "))
d=(a*a/(b*b+c*c))**0.5
print(math.floor(d*b), math.floor(d*c))