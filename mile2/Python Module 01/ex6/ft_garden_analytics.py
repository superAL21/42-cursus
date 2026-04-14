#!/usr/bin/env python3

class Plant:
    class Counter:
        def __init__(self) -> None:
            self._show_count = 0
            self._grow_count = 0
            self._age_count = 0
            self._shade_count = 0

        def count_show(self) -> None:
            self._show_count += 1

        def count_grow(self) -> None:
            self._grow_count += 1

        def count_age(self) -> None:
            self._age_count += 1

        def count_shade(self) -> None:
            self._shade_count += 1

        def get_stats(self) -> str:
            return (f"{self._grow_count} grow, {self._age_count} age, "
                    f"{self._show_count} show")

        def get_shade(self) -> str:
            return f"{self._shade_count} shade"

    def __init__(self, name: str, height: float, age: int) -> None:
        self.stats = self.Counter()
        self.name: str = name.capitalize()
        self._height: float = 0.0
        self._age: int = 0

        self.set_height(height)
        self.set_age(age)

    def set_height(self, value: float) -> None:
        if value < 0:
            print(f"{self.name}: Error, height can't be negative"
                  f"\nHeight update rejected")
        else:
            self._height = value

    def get_height(self) -> float:
        return self._height

    def set_age(self, value: int) -> None:
        if value < 0:
            print(f"{self.name}: Error, age can't be negative"
                  f"\nAge update rejected")
        else:
            self._age = value

    def get_age(self) -> int:
        return self._age

    @staticmethod
    def check_year_old(age: int) -> None:
        if age < 365:
            data = False
        else:
            data = True
        print(f"Is {age} days more than a year? —> {data}")

    def show(self, prefix: str = "") -> None:
        self.stats.count_show()
        p = f"{prefix}: " if prefix else ""
        print(
            f"{p}{self.name}: {self._height:.1f}cm,"
            f" {self._age} days old")

    def grow(self, large: float) -> None:
        self.stats.count_grow()
        if large < 0:
            print(f"{self.name}: Error, height can't be negative"
                  f"\nHeight update rejected")
        else:
            self.set_height(round(self._height + large, 1))

    def age(self, days: int) -> None:
        self.stats.count_age()
        if days < 0:
            print(f"{self.name}: Error, age can't be negative"
                  f"\nAge update rejected")
        else:
            self.set_age(self._age + days)

    @classmethod
    def create_anon_plant(cls) -> "Plant":
        return cls("Unknown plant", 0.0, 0)


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int,
                 color: str = "Unknown") -> None:
        super().__init__(name, height, age)
        self._color: str = color
        self._is_bloomed = False

    def bloom(self):
        self._is_bloomed = True

    def show(self, prefix: str = ""):
        super().show(prefix)
        if self._is_bloomed is False:
            data = " has not bloomed yet"
        else:
            data = " is blooming beautifully!"

        print(
            f" Color: {self._color}\n"
            f" {self.name}{data}")


class Seed(Flower):
    def __init__(self, name: str, height: float, age: int,
                 color: str = "Unknown", number_of_seeds: int = 0) -> None:
        super().__init__(name, height, age, color)
        self._num_of_seeds = number_of_seeds

    def show(self, prefix: str = ""):
        super().show(prefix)
        if self._is_bloomed is True:
            print(f" Seeds: {self._num_of_seeds}")
        else:
            print(" Seeds: 0")


class Tree(Plant):
    def __init__(self, name: str, height: float, age: int,
                 trunk_diameter: float = 0.0) -> None:
        super().__init__(name, height, age)
        self._trunk_diameter = round(trunk_diameter, 1)

    def produce_shadow(self):
        self.stats.count_shade()
        print(f"Tree {self.name} now produces a shade"
              f"of {self._height:.1f}cm long and "
              f"{self._trunk_diameter:.1f}cm wide.")

    def show(self, prefix: str = ""):
        super().show(prefix)
        print(f" Trunk diameter: {self._trunk_diameter:.1f}cm")


def statistics(plant: Plant) -> None:
    data = plant.stats.get_stats()
    if isinstance(plant, Tree):
        print(f"Stats: {data},\n {plant.stats.get_shade()}")
    else:
        print(f"Stats: {data}")


if __name__ == "__main__":
    print("=== Garden statistics ===\n"
          "=== Check year-old")
    Plant.check_year_old(30)
    Plant.check_year_old(400)
    print("\n=== Flower")
    plant = Flower("rose", 15, 10, "red")
    plant.show()
    print("[statistics for Rose]")
    statistics(plant)
    print("[asking the rose to grow and bloom]")
    plant.grow(8)
    plant.bloom()
    plant.show()
    print("[statistics for Rose]")
    statistics(plant)
    print("\n=== Tree")
    plant2 = Tree("oak", 200, 365, 5)
    plant2.show()
    print("[statistics for Oak]")
    statistics(plant2)
    print("[asking the oak to produce shade]")
    plant2.produce_shadow()
    print("[statistics for Oak]")
    statistics(plant2)
    print("\n=== Seed")
    plant3 = Seed("sunflower", 80, 45, "yellow", 42)
    plant3.show()
    print("[make sunflower grow, age and bloom]")
    plant3.grow(30)
    plant3.age(20)
    plant3.bloom()
    plant3.show()
    print("[statistics for Sunflower]")
    statistics(plant3)
    print("\n=== Anonymous")
    plant_nn = Plant.create_anon_plant()
    plant_nn.show()
    print("[statistics for Unknown plant]")
    statistics(plant_nn)
