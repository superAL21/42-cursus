#!/usr/bin/env python3

def ft_garden_intro():
    name = input("Plant: ")
    height = int(input("Height: "))
    age = int(input("Age: "))
    print("=== Welcome to My Garden ===")
    print(f"Plant: {name}")
    print(f"Height: {height}cm")
    print(f"Age: {age} days")
    print("=== End of program ===")

if __name__ == "__main__":
    ft_garden_intro()