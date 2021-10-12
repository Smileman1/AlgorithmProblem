def solution(citations):
    citations.sort()
    point1 = point2 = 0
    while True:
        if len(citations) - point2 <= point1:return point1
        if citations[point2] == point1:point2 += 1
        else:point1 += 1


print(solution([660, 48, 7, 402, 969, 639, 432, 124, 461, 909, 92, 594, 891, 702, 298, 936, 62, 940, 946, 505]))
