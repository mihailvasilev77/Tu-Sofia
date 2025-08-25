def func1():
    x, y, kgz, kgp = float(input()), float(input()), int(input()), int(input())

    while(x < 0):
        x = float(input("Enter valid amount for x (>0): "))
    
    while(y < 0):
        y = float(input("Enter valid amount for y (>0): "))
    
    while(kgz < 0):
        kgz = int(input("Enter valid amount for kgz (>0): "))

    while(kgp < 0):
        kgp = int(input("Enter valid amount for kgp (>0): "))

    return ((x*kgz)+(y*kgp)) * bgn_to_eur_rate

def func2():
    usd = float(input("Enter dollars:"))
    while(usd < 100 or usd > 5000):
        usd = float(input("Enter dollars:"))
    
    lr = int(input("Enter liras:"))
    while(lr < 100 or lr > 50000):
        lr = int(input("Enter liras:"))

    cms = int(input("Enter commission:"))
    while(cms < 1 or cms > 6):
        cms = int(input("Enter commission:"))
    
    usd_to_bgn = usd * 1.76
    lr_to_bgn = lr * 0.052
    bgn_to_eur = (usd_to_bgn+lr_to_bgn) * bgn_to_eur_rate

    return round((bgn_to_eur-(bgn_to_eur*cms/100)),2)

def func3():
    pr_dog = 2.5
    pr_cat = 4
    cnt_dog = int(input("Enter dog food amount:"))
    while(cnt_dog < 0):
        cnt_dog = int(input("Enter valid amount:"))
    cnt_cat = int(input("Enter cat food amount:"))
    while(cnt_cat < 0):
        cnt_cat = int(input("Enter valid amount:"))

    total = pr_dog*cnt_dog + pr_cat*cnt_cat

    return str(total) + " lv."

bgn_to_eur_rate = 1.96

if __name__ == '__main__':
    print(func3())