def func1():
    m = int(input("Enter value: "))
    n = int(input("Enter value: "))

    l = []
    sum = 1

    if m >= n:
        return "Invalid values (m >= n)"
    
    for i in range(m,n):
        if i % 12 == 0:
            l.append(i)

    for i in l:
        sum = sum*i

    return sum

def func2():
    n = int(input("Enter a number: "))
    l = []

    for i in range(n):
       l.append(int(input()))

    max = l[0]
    min = l[0]

    for i in range(len(l)):
        if l[i] > max:
            max = l[i]
        if l[i] < min:
            min = l[i]

    return max,min

def func3():
    l = ("sq" , "rec", "tri")
    form = input("Enter the form: ")
    S = 1
    P = 0
    var = 0

    sides = list(map(int,input("enter values: ").split(" ")))
    if form == l[2]:
        S = (sides[0] * sides[1]) / 2
    elif form == l[0]:
        S = sides[0] * sides[0]
    elif form == l[1]:
        S = sides[0] * sides[1]
    
    for i in sides:
        P += i

    return S,P

def func4():
        week = ["Mnd", "Thd", "Wnd", "Tsd", "Frd", "Std", "Snd"]
        months = {
            "Jan": 31, "Feb": 28, "March": 31, "April": 30,
            "May": 31, "Jun": 30, "July": 31, "Aug": 31,
            "Sept": 30, "Oct": 31, "Nov": 30, "Dec": 31
        }

        n = int(input("Въведете брой дни (n): "))
        year = int(input("Въведете година: "))
        
        if (year % 4 == 0 and (year % 100 != 0 or year % 400 == 0)):
            months["Feb"] = 29  
        
        month_input = input("Въведете месец (например Jan, Feb, March): ")
        if month_input not in months:
            return "Несъществуващ месец"
        
        day = int(input("Въведете дата: "))
        if day < 1 or day > months[month_input]:
            return "Несъществуваща дата"
        
        day_of_week = input("Въведете ден (например Mnd, Thd, Wnd, Tsd, Frd, Std, Snd): ")
        if day_of_week not in week:
            return "Несъществуващ ден"

        current_day_index = week.index(day_of_week)

        day += n
        current_month_days = months[month_input]

        while day > current_month_days:
            day -= current_month_days
            month_index = list(months.keys()).index(month_input)
            month_index += 1
            if month_index >= len(months):
                month_index = 0 
                year += 1 
            month_input = list(months.keys())[month_index]
            current_month_days = months[month_input]

        new_day_index = (current_day_index + n) % 7
        new_week_day = week[new_day_index]

        return f"Новата дата е: {day} {month_input} {year}, ден от седмицата: {new_week_day}"

def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def func5():
    sums = [0, 0]
    
    while(1):
        x = input("Enter number: ")
        if x == "stop":
            return sums
        
        x = int(x)
        if x < 0:
            print("Number is negative")
            continue

        sums[is_prime(x)] += x
    

if __name__ == '__main__':
    print(func5())