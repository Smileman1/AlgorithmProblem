# https://www.acmicpc.net/problem/1011

def Centauri(my_col, taget):

    result = 0
    tmp = taget - my_col
    key = 1

    while True:
        if tmp == 0:
            return result
        if tmp <= key:
            return result + 1
        elif tmp >= 2*key:
            tmp -= 2*key
            key += 1
            result += 2
        else:
            return result + 2


num = int(input())
result_list = []
for x in range(num):
    my_col, taget = map(int, input().split(" "))
    result_list.append(Centauri(my_col, taget))

for x in result_list:
    print(x)