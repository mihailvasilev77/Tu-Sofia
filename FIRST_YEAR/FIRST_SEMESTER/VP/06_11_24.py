def func1(shape):
    if shape == 3:
        sides = list(map(int,input("enter 3 sides: ").split(" ")))
        a = area(sides[0], sides[1], shape)
    elif shape == 2 or shape == 1:
        sides = list(map(int,input("enter 2 sides: ").split(" ")))
        a = area(sides[0], sides[1], shape)

    p = perimeter([side for side in sides], shape)

    return a,p

def area(a,b, shape):
    area = a*b
    if shape == 3:
        return float(area/2)
    
    return area

def perimeter(sides, shape):
    p = 0
    for side in sides:
        p += side

    if shape != 3:
        p *= 2

    return p

def func2(str):
    count = 0
    ln = int(len(str)/2)

    for i in range(1,ln+1):
        if str[i-1] == str[-i]:
            count += 1
    
    return count == ln

def sum(x,y):
    return x+y

def sub(x,y):
    return x-y

def div(x,y):
    if y == 0:
        print("Cannot divide by zero.")
        return

    return x/y

def mult(x,y):
    return x*y

def pow(x,y):
    res = 1
    for i in range(y):
        res *= x
    return res
    
def func3(opp):
    x = int(input("Enter value:"))
    y = int(input("Enter second value:"))

    if opp == '+':
        res = sum(x,y)
    elif opp == '-':
        res = sub(x,y)
    elif opp == '/':
        res = div(x,y)
    elif opp == '*':
        res = mult(x,y)
    elif opp == '^':
        res = pow(x,y)

    return res

def func4(list, n):
    for i in range(len(list)):
        if n < list[i]:
            list[i] = 0

    return list

def longest_word(sentence):
    l = sentence.split()

    lw = ''

    for word in l:
        if len(word) > len(lw):
            lw = word

    return lw

def add_student(l,student):
    l.append(student)

def find_average(l):
    avg = 0
    for i in l:
        avg += i
    avg /= len(l)

    return avg

def get_average_student(student):
    grades = student.get("grades")
    return find_average(grades)

def get_oldest_student(students):
    oldest = {"age": 0}

    for student in students:
        if student.get("age") > oldest.get("age"):
            oldest = student

    return oldest

def get_students_above_average(students):
    l = []
    avg = 0

    for student in students:
        avg += get_average_student(student)
    avg = avg/len(students)

    for student in students:
        if get_average_student(student) > avg:
            l.append(student)

    return l

def get_student_names(students):
    l = []

    for student in students:
        l.append(student.get("name"))

    return l

def solve_sudoku(board):
    pass

if __name__ == '__main__':
    students = [{"name": "Mihail", "age": 19, "grades":[6,2,4,3,3]}, {"name": "Asen", "age": 21, "grades":[6,6,6,6,6]}, {"name": "Kumbata1", "age": 21, "grades":[6,6,6,6,6]}]
    add_student(students,{"name": "Mihail", "age": 19, "grades":[6,2,4,3,3]})
    print(get_student_names(students))