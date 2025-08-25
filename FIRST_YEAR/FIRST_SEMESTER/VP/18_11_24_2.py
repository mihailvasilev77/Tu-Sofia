class Animal:
    def __init__(self, name, species, age, health):
        self.name = name
        self.species = species
        self.age = age
        self.health = health

    def print_info(self):
        print(f"Name:{self.name}, Species:{self.species}, Age:{self.age}, Health:{self.health}")

class Mammal(Animal):
    def __init__(self, name, species, age, health, fur_color, diet):
        super().__init__(name, species, age, health)
        self.fur_color = fur_color
        self.diet = diet

    def print_info(self):
        print(f"Name:{self.name}, Species:{self.species}, Age:{self.age}, Health:{self.health}, Fur color:{self.fur_color}, Diet:{self.diet}")

class Bird(Animal):
    def __init__(self, name, species, age, health, wing_span, can_fly):
        super().__init__(name, species, age, health)
        self.wing_span = wing_span
        self.can_fly = can_fly

    def print_info(self):
        print(f"Name:{self.name}, Species:{self.species}, Age:{self.age}, Health:{self.health}, Wing span:{self.wing_span}, flight:{self.can_fly}")

class Reptile(Animal):
    def __init__(self, name, species, age, health, is_venomous, preferred_temperature):
        super().__init__(name, species, age, health)
        self.is_venomous = is_venomous
        self.preferred_temperature = preferred_temperature

    def print_info(self):
        print(f"Name:{self.name}, Species:{self.species}, Age:{self.age}, Health:{self.health}, Venomous:{self.is_venomous}, Preferred temperature:{self.preferred_temperature}")

class Zoo:
    def __init__(self, enclosures={}):
        self.enclosures = enclosures
    
    def add_animal(self, animal, enclosure_number):
        if enclosure_number not in self.enclosures:
            self.enclosures[enclosure_number] = []
        self.enclosures[enclosure_number].append(animal)

    def remove_animal(self, name):
        for encl in self.enclosures.values():
            for animal in encl:
                if animal.name == name:
                    encl.remove(animal)
                    print("Removed successfully")
    def list_animals_in_enclosure(self): 
        for encl in self.enclosures:
            for animal in self.enclosures[encl]:
                animal.print_info()
    
    def transfer_animal(self, animal_name, from_enclosure, to_enclosure):
        if from_enclosure in self.enclosures:
            for animal in self.enclosures[from_enclosure]:
                if animal.name == animal_name:
                    self.enclosures[from_enclosure].remove(animal)
                    self.add_animal(animal, to_enclosure)

    def find_animals_by_species(self, species):
        for enclosure in self.enclosures.values():
            for animal in enclosure:
                if animal.species == species:
                    animal.print_info()
    
if __name__ == "__main__":
    m = Mammal("Mechka", "Kafqva", 30, 10, "kafqv", "mesoqdna")
    b = Bird("Spas", "chaika", 2, 8, 20, True)
    r = Reptile("Andrea", "Zmiq", 1, 5, True, 21)
    r2 = Reptile("Maria", "Zmiq", 2, 5, True, 21)
    encl = {1:[m], 2:[b], 3:[r]}
    zoo = Zoo(encl)
    zoo.list_animals_in_enclosure()
    zoo.add_animal(r2, 4)
    zoo.list_animals_in_enclosure()
    zoo.remove_animal("Andrea")
    zoo.list_animals_in_enclosure()
    zoo.transfer_animal()
