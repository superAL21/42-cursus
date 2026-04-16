#!/usr/bin/env python3

def input_temperature(temp_str: str) -> int:
    print(f"Input data is '{temp_str}'")
    temp_int = int(temp_str)

    if temp_int < 0:
        raise ValueError(f"{temp_int}°C is too cold for plants (min 0°C)")
    elif temp_int > 40:
        raise ValueError(f"{temp_int}°C is too hot for plants (max 40°C)")

    print(f"Temperature is now {temp_int}°C\n")
    return temp_int


def test_temperature() -> None:
    try:
        input_temperature("25")
    except Exception as error:
        print(f"Caught input_temperature error: "
              f"{error}\n")
    try:
        input_temperature("abc")
    except Exception as error:
        print(f"Caught input_temperature error: "
              f"{error}\n")
    try:
        input_temperature("100")
    except Exception as error:
        print(f"Caught input_temperature error: "
              f"{error}\n")
    try:
        input_temperature("-50")
    except Exception as error:
        print(f"Caught input_temperature error: "
              f"{error}\n")
    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    print("=== Garden Temperature Checker ===\n")
    test_temperature()
