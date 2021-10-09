def solution(citations):
    answer = 0
    citations.sort()
    abc = {}
    lenCitations = len(citations)

    for x in citations:
        if x not in abc.keys():
            abc[x] = 1
        else:
            abc[x] += 1

    a = list(abc.keys())
    for x in range(len(a)):
        lowNum = 0
        for y in range(x):
            lowNum += abc[a[y]]
        highNum = lenCitations - lowNum
        if highNum >= a[x] and lowNum <= a[x]:
            answer = a[x]

    return answer


print(solution([660, 48, 7, 402, 969, 639, 432, 124, 461, 909, 92, 594, 891, 702, 298, 936, 62, 940, 946, 505]))
