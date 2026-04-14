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

    def show(self, prefix: str = "") -> None:
        p = f"{prefix}: " if prefix else ""
        print(
            f"{p}{self.name}: {self._height:.1f}cm,"
            f" {self._age} days old")

    def grow(self, large: float) -> None:
        if large < 0:
            print(f"{self.name}: Error, height can't be negative"
                  f"\nHeight update rejected")
        else:
            self.set_height(round(self._height + large, 1))
            print(f"Height update: {self._height}cm")

    def age(self, days: int) -> None:
        if days < 0:
            print(f"{self.name}: Error, age can't be negative"
                  f"\nAge update rejected")
        else:
            self.set_age(self._age + days)
            print(f"Age update: {self._age} days")


if __name__ == "__main__":
    print("=== Garden Security System ===")
    plant = Plant("rose", 15, 10)
    plant.show("Plant created")
    print("")
    plant.grow(10)
    plant.age(20)
    print("")
    plant.grow(-11)
    plant.age(-12)
    print("")
    plant.show("Current state")
