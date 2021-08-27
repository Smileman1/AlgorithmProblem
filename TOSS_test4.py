def solution(input):
    input = input.split('\n')
    M,N = input.pop(0).split(' ')
    M = int(M)
    N = int (N)
    answer = ''
    show_List = []
    today_show = 0
    Lock=False
    LockDay = 0

    answer += str(M) + ' ' + str(N)

    for x in input:
        if x == "SHOW":
            if not Lock :
                check_show = 0
                if len(show_List) < M-1:
                    for x in show_List:
                        check_show += x
                    check_show += today_show
                else:
                    taget = len(show_List) - M + 1
                    for x in show_List[taget:]:
                        check_show += x
                    check_show += today_show

                if check_show<=N:
                    answer+='\n1'
                    today_show+=1
                else:
                    answer+='\n0'
                    lock=True
            else :
                answer+='\n0'

        elif x == "NEXT":
            answer += '\n-'
            show_List.append(today_show)
            today_show = 0
            LockDay+=1
            if LockDay>M:
                Lock=False
                LockDay=0
                pass

        elif x == "NEGATIVE":
            answer += '\n0'
            Lock=True
        elif x == "EXIT":
            answer += '\nBYE'
            return answer
        else:
            answer += '\nERROR'
    return answer




input = "1 3\nSHOW\nNEXT\nEXIT"


print(solution(input))