#!/usr/bin/env python3

import math


def get_player_pos() -> tuple[float, float, float]:
    entry = input("Enter new coordinates as floats in format 'x,y,z': ")
    coordinates = entry.split(",")
    if len(coordinates) != 3:
        print("Invalid syntax")
        return get_player_pos()

    list1 = []
    for number in coordinates:
        try:
            value = float(number.strip())
            list1.append(value)
        except ValueError as error:
            for num in coordinates:
                try:
                    float(num.strip())
                except ValueError:
                    print(f"Error on parameter '{num.strip()}': {error}")
            return get_player_pos()
    final_coords = (list1[0], list1[1], list1[2])
    return final_coords


def main() -> None:
    print("Get a first set of coordinates")
    x1, y1, z1 = get_player_pos()
    print(f"Got a first tuple: {x1, y1, z1}")
    print(f"It includes: X={x1}, Y={y1}, Z={z1}")
    dist_center = round(math.sqrt(x1**2 + y1**2 + z1**2), 4)
    print(f"Distance to center: {dist_center}")
    print()
    print("Get a second set of coordinates")
    x2, y2, z2 = get_player_pos()
    dist_center2 = round(math.sqrt((x2-x1)**2 + (y2-y1)**2 + (z2-z1)**2), 4)
    print(f"Distance between the 2 sets of coordinates: {dist_center2}")


if __name__ == "__main__":
    print("=== Game Coordinate System ===\n")
    main()
