import packet as p

def can_vote():
    try:
        name = input("Enter name: ")
        age = int(input("Enter age: "))

        if not name.isalpha():
            raise ArithmeticError('Name can contain only letters.')
        
        if age<0 or age>120:
            raise ArithmeticError('Invalid age value.')
        
        if age >= 18:
            print(f'You can vote {name}.')

    except ArithmeticError as error:
        print(error)

    except ArithmeticError as error:
        print(error)

    except Exception:
        print("Error")

def calculator(a,b,op):
    cmd = ["+", "-", "*", "/"]
    try:
        if op not in cmd:
            raise AttributeError("Invalid command.")
        
        if op == "+":
            return p.sum(a,b)
        elif op == "-":
            return p.sub(a,b)
        elif op == "*":
            return p.mult(a,b)
        elif op == "/":
            return p.div(a,b)

    except AttributeError as error:
        print(error)    
    
    except Exception:
        print("Error")
        


if __name__ == '__main__':
    print(calculator(12,0,"/"))