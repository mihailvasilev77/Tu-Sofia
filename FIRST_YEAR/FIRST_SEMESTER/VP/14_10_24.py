import random as ra

def above_num(x,y):
    if  x > y:
        print("x")
    elif x == y:
        print("equal")
    else:
        print("y")

def inf_while():
    i = 0
    while(1):
        i = i + 1
        print(i)
        if i > 4:
            break

def print_alph():
    a = 97
    for j in range(26):
        print(chr(a))
        a = a + 1

def max(n):
    max = n[0]
    
    for i in range(len(n)):
        if max < n[i]:
            max = n[i]

    return max

def choice(x,y):
    ch = input("Enter choice: ")

    if ch == "+":
        return x+y
    elif ch == "-":
        return x-y
    elif ch == "*":
        return x*y
    elif ch == "/":
        try:
            return x/y
        except:
            print("cannot divide by zero")
    else:
        return "Invalid opperand"

def print_triangle(n):
    for i in range(n):
        print('*'*(i+1))

def print_triangle2(n):
    for i in range(1, n + 1):
        print(" "*(n-i), end="")
        
        for k in range(1, 2*i):
            print("*", end="")
        print()

def is_prime(x):
    if x > 1:
        for i in range(2, (x//2)+1):
            if (x % i) == 0:
                print(x, "is not a prime number")
                break
        else:
            print(x, "is a prime number")
    else:
        print(x, "is not a prime number")

def is_even_odd(x):
        if (x % 2) == 0:
            print(x, "is an even number")
        else:
            print(x, "is an odd number")

def syll_cnt(string):
    syllables = ['a', 'o', 'u', 'y', 'e', 'i']
    count = 0

    for i in range(len(string)):
        for j in range(len(syllables)):
            if syllables[j] is string[i]:
                count = count + 1

    return count


if __name__ == "__main__":
    x = 5
    y = 3
    n = 5
    data = []
    l = []
    size = 10
    str = 'Hello world'
    for i in range(size):
        l.append(ra.randint(0,100))
    failed = []
    passed = []
    honored = []

    #print(x>y)

    #for i in range(10):
        #print(i+1)
    
    for i in range(n):
        z = i
        data.append(z)

    for i in range(size):
        if l[i] < 50:
            failed.append(l[i])
        elif l[i] > 75:
            honored.append(l[i])
        else:
            passed.append(l[i])

    #print(l)
    #print(failed)
    #print(passed)
    #print(honored)
    
