def div(a,b):
    try:
        if b == 0:
            raise ValueError("Cannot divide by zero!")
        else:
            return a/b
    except ValueError as error:
        print(error)
