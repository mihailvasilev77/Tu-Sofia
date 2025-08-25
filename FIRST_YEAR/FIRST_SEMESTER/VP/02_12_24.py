import packet2 as p2
import json

def find_area():
    x = input("Enter form:")
    
    if x == "Rect":
        a = int(input("Enter side a: "))
        b = int(input("Enter side b: "))
        return p2.rectangle(a, b)
    elif x == "Romb":
        a = int(input("Enter side a: "))
        h = int(input("Enter side h: "))
        return p2.romb(a, h)
    elif x == "Square":
        a = int(input("Enter side a: "))
        return p2.square(a)
    elif x == "Trapec":
        a = int(input("Enter side a: "))
        b = int(input("Enter side b: "))
        h = int(input("Enter side h: "))
        return p2.trapec(a, b, h)
    elif x == "Triangle":
        a = int(input("Enter side a: "))
        b = int(input("Enter side b: "))
        c = int(input("Enter side c: "))
        return p2.triangle(a, b, c)

def to_json(obj):
    return json.dumps(obj)

def read_f(dir):
    with open(dir,"r") as f:
        for line in f:
            print(line, end="")
    print("\n")

def write_to_bin(dir,text):
    with open(dir, "wb") as f:
        hexStr = "".join(str(ord(x)) for x in text)
        f.write(hexStr.encode())

def read_bin(dir):
    with open(dir, "rb") as f:
        print((f.read()))

if __name__ == "__main__":
   print(to_json({"asen":19,"Misho":20}))
   read_f("files/test.txt") 
   text4 = "This is good"
   write_to_bin("files/document.bin",text4)
   read_bin("files/document.bin")

