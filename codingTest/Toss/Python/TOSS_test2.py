def solution(servers, sticky, requests):
    answer = [[] for _ in range(servers)]
    point = 0

    if sticky:
        for x in requests:
            taget = True
            for y in range(servers):
                if x in answer[y]:
                    answer[y].append(x)
                    taget = False
            if taget:
                answer[point].append(x)
                point+=1
                point%=servers

    else:
        for x in requests:
            answer[point].append(x)
            point += 1
            point %= servers


    return answer




servers = 2
sticky = True
requests = [1,2,2,3,4,1]

print(solution(servers, sticky, requests))