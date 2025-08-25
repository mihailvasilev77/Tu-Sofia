import random as r

def find_day_winner(*args):
    c1 = 0
    c2 = 0
    for i in args:
        c1 += int(i == "Team 1")
        c2 += int(i == "Team 2")

    if c1 > c2:
        print("Team 1 wins.")
    elif c2 > c1:
        print("Team 2 wins.")
    elif c1 == c2:
        print("Tie.")

def check_perfect_num(num):
    if num < 0 or type(num) is not int:
        return False
    
    sum = 0
    for i in range(1,num):
        if num % i == 0:
            sum += i
    
    return sum == num

def check_for_perfect_nums(numbers):
    perfcet = []
    for i in numbers:
        if check_perfect_num(i):
            perfcet.append(i)
    return perfcet

def func3(l1, l2):
    ln1 = len(l1)
    ln2 = len(l2)
    max_len = max(ln1,ln2)

    extended_l1 = l1 * (max_len // len(l1)) + l1[:(max_len % len(l1))]
    extended_l2 = l2 * (max_len // len(l2)) + l2[:(max_len % len(l2))]

    return sum(a*b for a, b in zip(extended_l1,extended_l2))

def func4(str, *args):
    ln = len(args)
    res = ''

    for i in args:
        if 0 < i < len(str):
            res += ''.join(str[i])

    return res

def nod(a,b):
    while b != 0:
        a,b = b, a%b
    return a

def nok(a,b):
    return abs(a*b) // nod(a,b)

def check_prime(num):
    if type(num) != int or num <=1:
        return False
    
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
        
    return True

def func6(num):
    for i in range(num):
        if check_prime(i) and check_prime(num-i):
            return True
        
    return False

def create_matrix(cols,rows):
    return [[r.randint(10,100) for i in range(cols)] for j in range(rows)]

def print_matrix(matrix):
    for i in range(len(matrix)):
        print(end="|")
        for j in range(len(matrix[i])):
            print(matrix[i][j], end="|")
        print("\n")

def sum_of_cols(matrix):
    ln = len(matrix[0])
    s = [0 for i in range(ln)]
    for i in range(len(matrix)):
        for j in range(ln):
            s[j] += matrix[i][j]
    
    for i in range(len(s)):
        print(f"Sum of col {i+1}: {s[i]}")


if __name__ == '__main__':
    find_day_winner("Team 1", "Team 2", "Team 1")
    print(check_perfect_num(28))
    print(check_for_perfect_nums([6, 28, 12, 496, 8128, 45]))
    print(func3([1,2,3],[4,5]))
    print(func4("qvorabaaaher",1,2,3))
    print(nok(15,20))
    print(check_prime(11))
    print(func6(11))
    arr = create_matrix(4,5)
    print_matrix(arr)
    sum_of_cols(arr)
