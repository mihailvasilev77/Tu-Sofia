class C:
    x=5

class Person:
    def __init__(self, fname, lname, age, nationality):
        if self.check_age(age) is None:
            raise ValueError("Age must be between 0 and 100.")
        
        self.fname = fname
        self.lname = lname
        self.age = age
        self.nationality = nationality

    def print(self):
        print(f"Name: {self.fname} {self.lname} Nationality: {self.nationality}")

    def is_legal(self):
        print("Adult" if self.age > 18 else "Underage")

    def change_nationality(self, new):
        self.nationality = new
        print("Changed successfully!")

    def check_age(self,age):
        return age if isinstance(age,int) and 0<=age<=100 else None

class Student(Person):
    def __init__(self, fname, lname, age, nationality, uni, gradyr):
        super().__init__(fname, lname, age, nationality)
        self.uni = uni
        self.gradyr = gradyr

    def print(self):
        print(f"Name: {self.fname} {self.lname} Nationality: {self.nationality} University and graduation year: {self.uni} {self.gradyr}")

class Lecturer(Person):
    def __init__(self, fname, lname, age, nationality, uni, exp):
        super().__init__(fname, lname, age, nationality)

        if self.is_exp_legal(exp) is None:
            raise ValueError("Experience must be 3 years or higher but not over age.")
        
        self.uni = uni
        self.exp = exp

    def print(self):
        print(f"Name: {self.fname} {self.lname} Nationality: {self.nationality} University: {self.uni} Years of experience:{self.exp}")

    def is_exp_legal(self,exp):
        return exp if isinstance(exp,int) and 3<=exp<=self.age else None
    
    def add_experience(self, new):
        self.exp += new
        self.age += new
        if self.is_for_promo():
            print("The proffesor can be promoted")
        else:
            print("The proffesor cannot be promoted")
    
        if self.is_for_fund():
            print("The proffesor can be funded")
        else:
            print("The proffesor cannot be funded")

        if self.is_for_pens():
            print("The proffesor can retire")
        else:
            print("The proffesor can retire")

    def is_for_promo(self):
        return self.exp >= 10
    
    def is_for_fund(self):
        return self.exp >= 5
    
    def is_for_pens(self):
        return self.age >= 65
    
    def check_title(self):
        if 3<=self.exp<=5:
            print("The professor is junior")
        elif 6<=self.exp<=10:
            print("The professor is junior")
        elif 11<=self.exp<=15:
            print("The professor is senior")
        elif 16<=self.exp<=25:
            print("The professor is grand")

if __name__ == '__main__':
    p1 = Person("Pesho", "Slepiq", 10, "Burgazliq")
    st = Student("Mihail", "Vasilev", 19, "Sofianec", "TU", 2028)
    lt = Lecturer("Svetlan", "Asparuhov", 64, "Belenec", "SU", 4)
    p1.print()
    print(p1.age)
    p1.is_legal()
    p1.change_nationality("Nesebarec")
    p1.print()
    st.print()
    lt.print()
    lt.add_experience(2)
    lt.print()
    lt.check_title()