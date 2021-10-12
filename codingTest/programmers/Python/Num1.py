def solution(citations):
    answer = 0
    citations.sort()
    abc = {}
    lenCitations = len(citations)
    answerLow = 0
    answerHigh = lenCitations
    answerKey = -1

    for x in citations:
        if x not in abc.keys():
            abc[x] = 1
        else:
            abc[x] += 1

    a = list(abc.keys())
    for x in range(len(a)):
        lowNum = 0
        for y in range(x+1):
            lowNum += abc[a[y]]
        highNum = lenCitations - lowNum
        if highNum >= a[x] and lowNum <= a[x]:
            answer = a[x]
            answerKey = x
            answerLow = lowNum
            answerHigh = highNum

    if answerKey < len(a)-1:
        if answerKey == -1:
            for x in range(0,a[0]):
                if answerHigh >= x and answerLow <= x:
                    answer = x
                else:
                    break
        else:
            for x in range(a[answerKey], a[answerKey+1]):
                if answerHigh >= x and answerLow <= x:
                    answer = x
                else: break

    return answer


print(solution([660, 48, 7, 402, 969, 639, 432, 124, 461, 909, 92, 594, 891, 702, 298, 936, 62, 940, 946, 505]))
