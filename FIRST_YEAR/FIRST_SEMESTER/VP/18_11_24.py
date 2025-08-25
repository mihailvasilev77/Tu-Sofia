class Book:
    def __init__(self, tittle, author, year, status=True):
        self.tittle = tittle
        self.author = author
        self.year = year
        self.status = status
        self.count = 0
    
    def print_book(self):
        print(f"Book:{self.tittle} Author:{self.author} Year:{self.year} ")

    def get_book(self):
        if self.status == True:
            print(f"You accuqired the book {self.tittle}")
            self.count += 1
            self.change_status()
        elif self.status == False:
            print(f"The book {self.tittle} is already taken")

    def return_book(self):
        if self.status == False:
            print(f"You have returned the book {self.tittle} successfully.")
            self.change_status()
        elif self.status == True:
            print("The book is already in the library")

    def change_status(self):
        self.status = not self.status

class Library:
    def __init__(self, books=[], unv=[]):
        self.books = books
        self.unv = unv
        self.count = 1

    def add_book(self,book):
        self.books.append(book)
    
    def print_books(self):
        for book in self.books:
            book.print_book()

    def print_unavaible_books(self):
        for book in self.unv:
            book.print_book()

    def search_by_tittleor_author(self, tittle, author):
        for i in self.books:
            if tittle in i.tittle or author == i.author:
                i.print_book()

    def search_book(self, book):
        if self.count > 3:
            print("You cannot rent more than 3 books simultaneously")
            return
        
        ttl = book.tittle
        for i in self.books:
            if i.tittle == ttl and book.status == True:
                print(f"Found {ttl}.")
                book.get_book()
                self.count += 1
                self.books.remove(book)
                self.unv.append(book)

    def return_book(self, book):
        if book.status == False and book not in self.books:
            print(f"Returned {book.tittle}.")
            book.return_book()
            self.count -= 1
            self.books.append(book)
            self.unv.remove(book)
        else:
            print("Book is returned")

if __name__ == "__main__":
    a = Book("Az", "Misho", 2000)
    b = Book("Ti", "Kati", 2001)
    c = Book("Toi", "Martin", 2005)
    d = Book("Tq", "Roberto", 2014)
    #b.get_book()
    #b.get_book()
    #b.return_book()
    #b.get_book()
    lib = Library([a,b,c,d])
    lib.print_books()
    lib.search_book(a)
    lib.print_unavaible_books()
    
    
