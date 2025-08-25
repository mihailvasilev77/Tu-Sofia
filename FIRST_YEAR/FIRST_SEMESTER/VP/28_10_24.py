import random as r

def func1():
    x = int(input("Enter number: "))

    if not type(x) is int:
        raise TypeError("Only integers are allowed")
    
    l = [int (d) for d in str(x)]

    tup = tuple(l)
    tup2 = tuple(l[::-1])

    return tup,tup2
        

def func2():
    l = [r.randint(0,100) for x in range(10)]

    print(l)

    for i in range(0,len(l)*2-2,2):
        l.insert(i+1, (l[i]+l[i+1]))

    return l

def func3():
    stri = input("Enter text: ")

    dict = {}
    
    for x in stri:
        dict[x] = dict.get(x,0) + 1
    
    return dict

def func4():
    n = int(input("Enter a number:"))
    l = [i for i in range(1,n+1)]
    lr = l[::-1]

    dic = dict()

    for i in range(n):
        dic[l[i]] = lr[i]

    return dic

def func5():
    film1 = ("Avengers:Endgame", 8.8)
    film2 = ("Fight club", 9.7)
    film3 = ("Gundi",7.5)
    film4 = ("Pursuit of happyness", 9.5)
    film5 = ("Terifier 3", 2.3)
    film6 = ("American Pie", 8.8)
    x = []
            
    films = [film1, film2, film3, film4, film5, film6]

    for i in range(len(films)):
        for j in range(len(films)-1):
            if films[j][1] < films[i][1]:
                x = films[j]
                films[j] = films[i]
                films[i] = x

    return films



if __name__ == "__main__":
    print(func1())