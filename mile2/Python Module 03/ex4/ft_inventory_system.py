#!/usr/bin/env python3

import sys


def main() -> None:
    valid_args: dict = {}

    for arg in sys.argv[1:]:
        if ":" not in arg:
            print(f"Error - invalid parameter '{arg}'")
            continue
        key, value = arg.split(":")
        try:
            val: int = int(value)
        except ValueError as error:
            print(f"Quantity error for '{key}': {error}")
            continue

        if key in valid_args:
            print(f"Redundant item '{key}' - discarding")
            continue
        valid_args[key] = val

    keys = list(valid_args.keys())
    values = list(valid_args.values())
    print(f"Got inventory: {valid_args}")
    print(f"Item list: {keys}")
    print(f"Total quantity of the {len(keys)} items: {sum(values)}")
    max = valid_args[keys[0]]
    min = valid_args[keys[0]]
    key_max = key[0]
    key_min = key[0]

    for key in keys:
        element = valid_args[key]
        if element > max:
            max = element
            key_max = key
        if element < min:
            min = element
            key_min = key
        print(f"Item {key} represents {round(element/sum(values)*100, 1)}%")

    print(f"Item most abundant: {key_max} with quantity {max}")
    print(f"Item least abundant: {key_min} with quantity {min}")

    new_item = {'magic_item': 1}
    valid_args.update(new_item)
    print(f"Update inventory: {valid_args}")
    return


if __name__ == "__main__":
    if len(sys.argv) > 1:
        print("=== Inventory System Analysis ===")
        main()
