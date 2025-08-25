id = 0
orders = []

def order():
    name = input("Enter your name: ")
    dish = input("Enter dish:")
    id = id + 1
    
    return id+":"+name+":"+dish

if __name__ == "__main__":
    orders += order()
    print(orders)