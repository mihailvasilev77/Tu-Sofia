import random as r

def func1():
    inp = input("Enter text: ")
    dic = {}
    
    for i in inp:
        dic[i] = inp.replace(i,"")

    return dic

def func2():
    txt = input("Enter text: ").split()

    lgt = txt[0]
    sht = txt[0]

    for i in txt:
        lni = len(i)
        if lni > len(lgt):
            lgt = i
        if lni < len(sht):
            sht = i
    
    txt.remove(lgt)
    txt.remove(sht)

    return txt
        
def func3():
    arr = [2,1,1,2,3,3,3,3,3,2,2,2,1]
    res = []
    dic = {}
    result = []
    first = False
    cnt = 1
    numb = 0
    max = 0
    for i in range(len(arr)):
        if arr[i] is not arr[i-1]:
            first = True
        if arr[i] == arr[i-1]:
            if first == True:
                res.append(arr[i-1])
            res.append(arr[i])
            first = False

    for i in range(len(res)):
        if res[i] == res[i-1]:
            cnt += 1
        else:
            cnt = 1
        dic[res[i]] = cnt

    for i in dic:
        if dic[i] > max:
            max = dic[i]
            numb = i
    
    for i in range(max):
        result.append(numb)

    return result

def func4():
    rows = int(input("Enter rows: "))
    cols = int(input("Enter cols: "))
    row = int(input("Enter row: ")) - 1
    col = int(input("Enter col: ")) - 1
    arr = [[r.randint(10,100) for i in range(cols)] for j in range(rows)]

    print(arr)
    
    arr.pop(row)
    for i in range(len(arr)):
        arr[i].pop(col)


    return arr

def func5():
    set1 = set(map(int, input("Enter set 1:").split(" ")))
    set2 = set(map(int, input("Enter set 2:").split(" ")))
    num = int(input("Enter number to remove: "))

    len1 = len(set1)
    len2 = len(set2)
    uni = set1.union(set2)
    diff = set1.difference(set2)
    sym = set1.symmetric_difference(set2)

    print(len1,len2,uni,diff,sym)

    set1.discard(num)
    print(set1)

    set1.clear()
    set2.clear()

    print(set1,set2)

def func6():
    inp = input("Enter a choice:")
    dic = {"Hello": "Zdrasti", "Bye": "Chao"}
    while 1:
        if inp == "search":
            word = input("Enter the word you are searching for: ")
            if word not in dic:
                transl = input("Please enter translation")
                dic[word] = transl
            else:
                print(f"The translation of {word} is {dic[word]}")
        elif inp == "add":
            word = input("Enter the word you want to add: ")
            transl = input("Please enter translation")
            dic = add_to_dict(dic,word,transl)
        elif inp == "print":
            print(dic)

        elif inp == "del":
            word = input("Enter the word you want to delete: ")
            dic = remove_from_dict(dic, word)
        elif inp == "exit":
            break

        inp = input("Enter a choice: ")


def add_to_dict(dic,eng,bg):
    dic[eng] = bg
    return dic

def remove_from_dict(dic,eng):
    del dic[eng]
    return dic


if __name__ == '__main__':
    func6()