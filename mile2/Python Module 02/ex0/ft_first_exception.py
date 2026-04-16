#!/usr/bin/env python3

def input_temperature(temp_str: str) -> int:
    print(f"Input data is '{temp_str}'")
    temp_int = int(temp_str)
    print(f"Temperature is now {temp_int}°C\n")
    return temp_int


def test_temperature() -> None:
    try:
        input_temperature("25")
    except Exception as error:
        print(f"Caught input_temperature error: "
              f"{error}")
    try:
        input_temperature("abc")
    except Exception as error:
        print(f"Caught input_temperature error: "
              f"{error}")
    print("\nAll tests completed - program didn't crash!")


if __name__ == "__main__":
    print("=== Garden Temperature ===\n")
    test_temperature()
