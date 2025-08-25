import random as r

def func1():
    x = int(input("Enter number:"))
    l = [int (d) for d in str(x)]
    t1 = tuple(l)
    l.reverse()
    t2 = tuple(l)
    
    return t1,t2

def func2():
    l = [r.randint(0,100) for x in range(10)]

    #print(l)

    for i in range(0,len(l),3):
        l.insert(i+1, (l[i+2]+l[i+1]))

    return l

def func3():
    #string = input("Enter text:")
    d = dict()

    st = "SSSWWWTFW"
    count = 0
    for s in st:
        if s in st:
            count = count + 1
        d[s] = d[s].value + 1
    
    print(count)
    print(d)
    
def func4():
    n = int(input("Enter a number:"))
    l = [i for i in range(1,n+1)]
    lr = l[::-1]

    dic = dict()

    for i in range(n):
        dic[l[i]] = lr[i]

    return dic


if __name__ == "__main__":
    print(func1())