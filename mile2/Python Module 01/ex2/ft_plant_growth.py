#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: float, age_days: int) -> None:
        self.name: str = name.capitalize()
        self.height: float = round(height, 1)
        self.age_days: int = age_days

    def show(self) -> None:
        print(
            f"{self.name}: {self.height:.1f}cm,"
            f"{self.age_days} days old"
            )

    def grow(self) -> None:
        self.height = round(self.height + 0.8, 1)

    def age(self) -> None:
        self.age_days += 1


if __name__ == "__main__":
    print("=== Garden Plant Growth ===")
    plant1 = Plant("Rose", 25, 30)
    start = plant1.height
    plant1.show()
    for day in range(1, 8):
        plant1.grow()
        plant1.age()
        print(f"=== Day {day} ===")
        plant1.show()
    end = plant1.height
    print(f"Growth this week: {round(end - start, 1)}cm")
