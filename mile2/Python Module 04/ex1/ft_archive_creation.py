#!/usr/bin/env python3

import sys


def open_file() -> None:

    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <file>\n")
        return

    print("=== Cyber Archives Recovery & Preservation ===")
    data = None
    original_content = []

    try:
        print(f"Accessing file '{sys.argv[1]}'")
        data = open(sys.argv[1], "r")

        for line in data:
            original_content.append(line)

        print("---\n")
        for line in original_content:
            print(line.strip())
        print("---")
    except Exception as error:
        print(f"Error opening file '{sys.argv[1]}': {error}\n")
        return

    finally:
        if data is not None:
            data.close()
            print(f"File '{sys.argv[1]}' closed.")

    print("\nTransform data:")
    print("---\n")
    lines_transformed = []
    char_special = "#"
    for line in original_content:
        clean_line = line.rstrip('\n')
        new_line = f"{clean_line}{char_special}"
        lines_transformed.append(new_line)
        print(new_line)
    print("\n---")

    new_file_name = input("Enter new file name (or empty): ")
    if new_file_name.strip():
        try:
            new_file = open(new_file_name, "w")
            final_str = "\n".join(lines_transformed)
            new_file.write(final_str)
            print(f"Saving data to '{new_file_name}'")
            print(f"Data saved to '{new_file_name}'")
        except Exception as error:
            print(f"Error saving file: {error}")
    else:
        print("Not saving data.")


if __name__ == "__main__":
    open_file()
