class C1:
    def __init__(self, ls):
        self.list = self.only_num(ls)

    def only_num(self, list):
        return [i for i in list if type(i) is int]
    
    def print_list(self):
        print(self.list)

    def avg(self):
        avg = 0
        
        for i in self.list:
            avg += i
        
        return avg/len(self.list)
    
class Shape:
    def __init__(self, shape):
        self.shape = shape

    def area(self):
        return 0

class Square(Shape):
    def __init__(self, shape, radius):
        super().__init__(shape)
        self.radius = radius

    def area(self):
        return self.radius * self.radius

class Circle(Shape):
    def __init__(self, shape, radius):
        super().__init__(shape)
        self.radius = radius

    def area(self):
        return self.radius * self.radius * 3.14

class TriangleChecker():
    def __init__(self,a,b,c):
        self.list = [a,b,c]
    
    def is_triangle(self):
        try:
            for i in self.list:
                if type(i) is not (int or float):
                    raise ArithmeticError("Трябва да въведете само числа!")
            
            for i in self.list:
                if i < 0:
                    raise ArithmeticError("Нищо няма да работи с отрицателни числа")
                
            if self.list[0]+self.list[1]>self.list[2] and self.list[2]+self.list[0]>self.list[1] and self.list[1]+self.list[2]>self.list[0]:
                 print("Ура, можете да построите триъгълник!")
            else:
                print("Жалко, но не можете да напражите триъгълник от това!")

        except ArithmeticError as error:
            print(error)

class Food:
    def __init__(self, carbs, protein, fat):
        self.carbs = carbs
        self.protein = protein
        self.fat = fat

    def cals(self):
        return 4*self.carbs + 4*self.protein + 9*self.fat

class Recipe:
    def __init__(self, name, ingr):
        self.name = name
        self.ingr = ingr

    def cals(self):
        return sum(food.cals() for food in self.ingr)

    def __str__(self):
        return self.name
    
class Employee:
    def __init__(self, name, position, salary):
        self.name = name
        self.position = position
        self.salary = salary
    
    def display_info(self):
        print(f"Name:{self.name}, Position:{self.position}, Salary:{self.salary}")

class Manager(Employee):
    def __init__(self, name, position, salary, department):
        super().__init__(name, position, salary)
        self.department = department

    def calc_bonus(self):
        return 1000 + 0.1*self.salary
    
    def display_info(self):
        super().display_info()
        print(f"Department:{self.department}")
    
class Developer(Employee):
    def __init__(self, name, position, salary, langs):
        super().__init__(name, position, salary)
        self.langs = langs
    
    def calc_bonus(self):
        return 200*len(self.langs) + 0.15*self.salary
    
    def display_info(self):
        super().display_info()
        print(f"Languages:{self.langs}")

class Company:
    def __init__(self, employees):
        self.employees = employees

    def add_employee(self, employee):
        self.employees.append(employee)

    def total_salary_expense(self):
        return sum(employee.salary+employee.calc_bonus() for employee in self.employees)
    
    def display_employees(self):
        for employee in self.employees:
            employee.display_info()
            

if __name__ == '__main__':
    c = TriangleChecker(4,2,3)
    c.is_triangle()

    banan = Food(12,213,23)
    apple = Food(0,12,2)
    orange = Food(10,10,10)

    r1 = Recipe("Fruit salad", [banan,apple,orange])
    print(r1)
    print(r1.cals())

    m1 = Manager("Asam","manag", 2000, "Nz")
    d1 = Developer("Tisi","dev", 8000, ["Py", "C"])
    d2 = Developer("Toie","dev", 8000, ["Py", "C"])

    c1 = Company([m1,d1])
    c1.add_employee(d2)
    print(c1.total_salary_expense())
    c1.display_employees()
