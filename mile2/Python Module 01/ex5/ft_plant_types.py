#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name: str = name.capitalize()
        self._height: float = 0.0
        self._age: int = 0
        
        self.set_height(height)
        self.set_age(age)

    def set_height(self, value: float) -> None:
            if value < 0:
                print (f"{self.name}: Error, height can't be negative"
                "\nHeight update rejected")
            else:
                self._height = value

    def get_height(self) -> float:
        return self._height
    
    def set_age(self, value: int) -> None:
        if value < 0:
            print(f"{self.name}: Error, age can't be negative"
            f"Age update rejected")
        else:
            self._age = value

    def get_age(self) -> int:
        return self._age
    

    def show(self, prefix: str = "") -> None:
        p = f"{prefix}: " if prefix else ""
        print(
            f"{p}{self.name}: {self._height:.1f}cm,"
            f" {self._age} days old")

    def grow(self, large: float) -> None:
        if large < 0:
                print (f"{self.name}: Error, height can't be negative"
                "\nHeight update rejected")
        else:
            self.set_height(round(self._height + large, 1))
            print(f"Height update: {self._height}cm")

    def age(self, days: int) -> None:
        if days < 0:
                print (f"{self.name}: Error, age can't be negative"
                "\nAge update rejected")
        else:
            self.set_age(self._age + days)
            print(f"Age update: {self._age} days")
            
class Flower(Plant):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self._color: str = color
        self._is_bloomed = False

    def bloom(self):
        self._is_bloomed = True
    
    def show(self):
        super().show()
        if self._is_bloomed == False:
            data = " has not bloomed yet"
        else:
            data = " is blooming beautifully!"
        
        print(
            f" Color: {self._color}\n"
            f" {self.name}{data}")


class Tree(Plant):
    def __init__(self, name: str, height: float, age: int, trunk_diameter: float) -> None:
        super().__init__(name, height, age)
        self._trunk_diameter = round(trunk_diameter, 1)
    
    def	produce_shadow(self):
        print (f"Tree {self.name} now produces a shade"
                f"of {self._height:.1f}cm long and {self._trunk_diameter:.1f}cm wide.")
    
    def show(self):
        super().show()
        print(f" Trunk diameter: {self._trunk_diameter:.1f}cm")

class Vegetable(Plant):
    def __init__(self, name: str, height: float, age: int,
                haverst_season: str, nutritional_value: int) -> None:
        super().__init__(name, height, age)
        self._harvest_season = haverst_season
        self._nutritional_value = nutritional_value
    
    def age(self, days: int) -> None:
        if days < 0:
                print (f"{self.name}: Error, age can't be negative"
                "\nAge update rejected")
        else:
            self.set_age(self._age + days)
            self._nutritional_value += days

    def show(self):
        print(
            f"{self.name}: {self._height:.1f}cm,"
            f" {self._age} days old\n"
            f" Harvest season: {self._harvest_season}\n"
            f" Nutritional value: {self._nutritional_value}")

    def grow(self, large: float) -> None:
        if large < 0:
                print (f"{self.name}: Error, height can't be negative"
                "\nHeight update rejected")
        else:
            self.set_height(round(self._height + large, 1))


if __name__ == "__main__":
    print("=== Garden Plant Types ===\n"
        "=== Flower")
    plant = Flower("rose", 15, 10, "red")
    plant.show()
    plant.bloom()
    plant.show()
    print("\n=== Tree")
    plant2 = Tree("oak", 200, 365, 5)
    plant2.show()
    plant2.produce_shadow()
    print("\n=== Vegetable")
    plant3 = Vegetable("tomato", 5, 10, "April", 0)
    plant3.show()
    plant3.grow(42)
    plant3.age(20)
    plant3.show()