#!/usr/bin/env python3

import sys


def open_file() -> None:

    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <file>\n")
        return

    print("=== Cyber Archives Recovery ===")
    data = None

    try:
        print(f"Accessing file '{sys.argv[1]}'")
        data = open(sys.argv[1], "r")
        content = data.read()

        print("---\n")
        print(content)
        print("---")
    except Exception as error:
        print(f"Error opening file '{sys.argv[1]}': {error}\n")
        return

    finally:
        if data is not None:
            data.close()
            print(f"File '{sys.argv[1]}' closed.")


if __name__ == "__main__":
    open_file()
