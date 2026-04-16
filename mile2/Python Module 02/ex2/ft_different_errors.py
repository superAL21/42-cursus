#!/usr/bin/env python3

def garden_operations(operation_number: int) -> int:
    temp_int = int(operation_number)
    if temp_int == 0:
        int("abc")
    elif temp_int == 1:
        res = 10 / 0
    elif temp_int == 2:
        data = open("/non/existen/file")
        print(data)
    elif temp_int == 3:
        res = "hola" + 42
        print(res)
    print("Operation completed successfully!\n")
    return temp_int


def test_error_types() -> None:
    operation = [0, 1, 2, 3, 4]
    for n in operation:
        print(f"Testing operation {n}...")
        try:
            garden_operations(n)
        except (ValueError, ZeroDivisionError,
                FileNotFoundError, TypeError) as error:
            print(f"Caught {error.__class__.__name__}: "
                  f"{error}")
    print("All error types tested successfully!")


if __name__ == "__main__":
    print("=== Garden Error Types Demo ===")
    test_error_types()
