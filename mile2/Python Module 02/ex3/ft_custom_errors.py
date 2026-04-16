#!/usr/bin/env python3

class GardenError(Exception):
    def __init__(self, message: str = "Unknown garden error"):
        self.message: str = message
        super().__init__(message)


class PlantError(GardenError):
    def __init__(self, message: str = "Unknown plant error"):
        self.message: str = message
        super().__init__(message)


class WaterError(GardenError):
    def __init__(self, message: str = "Unknown water error"):
        self.message: str = message
        super().__init__(message)


def check_plant_status() -> None:
    raise PlantError("The tomato plant is wilting!")


def is_enough_water() -> None:
    raise WaterError("Not enough water in the tank!")


def test_error() -> None:
    print("Testing Plant Error...")
    try:
        check_plant_status()
    except PlantError as error:
        print(f"Caught {error.__class__.__name__}: {error}\n")
    print("Testing WaterError...")
    try:
        is_enough_water()
    except WaterError as error:
        print(f"Caught {error.__class__.__name__}: {error}\n")
    print("Testing catching all garden errors...")
    tests = [check_plant_status, is_enough_water]
    for test in tests:
        try:
            test()
        except GardenError as error:
            print(f"Caught GardenError: {error}")
    print("\nAll custom error types work correctly!")


if __name__ == "__main__":
    print("=== Custom Garden Errors Demo ===\n")
    test_error()
