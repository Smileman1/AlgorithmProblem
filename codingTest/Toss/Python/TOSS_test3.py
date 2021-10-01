def solution(amountText):
    if amountText == "0":
        return True

    if amountText[0]=='0' or '+'in amountText or '-' in amountText:
        return False

    amountText_List=amountText.split(',')

    if len(amountText_List)==1:
        try:
            errorcheck = int(amountText_List[0])
        except:
            return False
    else:
        first = True
        for x in amountText_List:
            if (first and len(x) != 0 and len(x) <=3) or len(x)==3:
                first = False
                try:
                    errorcheck = int(x)
                except:
                    return False
            else:
                return False

    return True


print(solution("1만원"))