def isRight(str):
    num = 0
    for s in str:
        if s == '(':
            num +=1
        else:
            if num ==0:
                return False
            num -=1
    return True

def isBalanced(str):
    num = 0
    for s in str:
        if s =='(':
            num +=1
        else :
            num -=1
    
    return num == 0
    
def reverse(str):
    ret =''
    for s in str:
        if s=='(':
            ret +=')'
        else:
            ret +='('

    return ret
def change(str):
    if isRight(str):
        return str
    for i in range(2,len(str)+1,2):
        
        if isBalanced(str[:i]):
            print(str[:i])
            u = str[:i]
            v = str[i:]
            if isRight(u):
                return u + change(v)
            else:
                u = u[1:-1]
                
                return '(' + change(v)+')' + reverse(u)

def solution(p):
    answer = change(p)
    return answer