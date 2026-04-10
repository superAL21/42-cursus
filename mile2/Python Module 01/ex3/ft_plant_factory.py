#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: float, age_days: int) -> None:
        self.name: str = name.capitalize()
        self.height: float = round(height, 1)
        self.age_days: int = age_days

    def show(self) -> None:
        print(
            f"Created: {self.name}: {self.height:.1f}cm,"
            f" {self.age_days} days old"
            )

    def grow(self, large: float) -> None:
        self.height = round(self.height + large, 1)

    def age(self, days: int) -> None:
        self.age_days += days


if __name__ == "__main__":
    garden = [
            Plant("rose", 25, 30),
            Plant("Oak", 200, 365),
            Plant("Cactus", 5, 90),
            Plant("Sunflower", 80, 45),
            Plant("Fern", 15, 120)
            ]
    print("=== Plant Factory Output ===")
    for plant in garden:
        plant.show()
