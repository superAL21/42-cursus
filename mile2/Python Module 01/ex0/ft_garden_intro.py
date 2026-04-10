#!/usr/bin/env python3

def ft_garden_intro() -> None:
    name: str = input("Plant: ")
    height: int = int(input("Height: "))
    age: int = int(input("Age: "))
    print("=== Welcome to My Garden ===")
    print(f"Plant: {name.capitalize()}")
    print(f"Height: {height}cm")
    print(f"Age: {age} days\n")
    print("=== End of program ===")


if __name__ == "__main__":
    ft_garden_intro()
