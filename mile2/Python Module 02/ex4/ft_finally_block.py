#!/usr/bin/env python3

class GardenError(Exception):
    def __init__(self, message: str = "Unknown garden error"):
        self.message: str = message
        super().__init__(message)


class PlantError(GardenError):
    def __init__(self, message: str = "Unknown plant error"):
        super().__init__(message)


def water_plant(plant_name: str) -> None:
    if plant_name == plant_name.capitalize():
        print(f"Watering {plant_name}: [OK]")
    else:
        raise PlantError(f"Invalid plant name to water: '{plant_name}'")


def test_watering_system() -> None:
    print("Testing valid plants...")
    print("Opening watering system")
    valid_plants = ["Tomato", "Lettuce", "Carrots"]
    try:
        for plant in valid_plants:
            water_plant(plant)
    except PlantError as error:
        print(f"Caught {error.__class__.__name__}: {error}\n"
              f".. ending tests and returning to main")
    finally:
        print("Closing watering system\n")
    print("Testing invalid plants...")
    print("Opening watering system")
    invalid_plants = ["Tomato", "lettuce", "Carrots"]
    try:
        for plant in invalid_plants:
            water_plant(plant)
    except PlantError as error:
        print(f"Caught {error.__class__.__name__}: {error}\n"
              f".. ending tests and returning to main")
    finally:
        print("Closing watering system\n")
    print("Cleanup always happens, even with errors!")


if __name__ == "__main__":
    print("=== Garden Watering System ===\n")
    test_watering_system()
