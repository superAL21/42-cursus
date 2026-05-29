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
            sys.stdout.write(line.strip('\n') + '\n')
        print("\n---")
    except Exception as error:
        sys.stderr.write(f"[STDERR] Error opening file "
                         f"'{sys.argv[1]}': {error}\n")
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
        new_line = f"{clean_line}{char_special}\n"
        lines_transformed.append(new_line)
        sys.stdout.write(new_line)
    print("\n---")

    sys.stdout.write("Enter new file name (or empty): ")
    sys.stdout.flush()

    new_file_name = sys.stdin.readline().strip()

    if new_file_name:
        print(f"Saving data to '{new_file_name}'")
        output_file = None
        try:
            output_file = open(new_file_name, "w")
            output_file.writelines(lines_transformed)
            print(f"Data saved to '{new_file_name}'")
        except Exception as error:
            sys.stderr.write(f"[STDERR] Error opening file "
                             f"'{new_file_name}': {error}\n")
            sys.stdout.flush()
            print("Data not saved.")
        finally:
            if output_file is not None:
                output_file.close()
                print(f"File '{new_file_name}' closed.")

    else:
        print("Not saving data.")


if __name__ == "__main__":
    open_file()
