#!/usr/bin/env python3

def secure_archive(file: str, option: str,
                   content: str | None = None) -> tuple[bool, str]:

    try:
        with open(file, option) as my_file:
            if option == 'r':
                content = my_file.read()
                return (True, content)

            elif option == 'w':
                if content is not None:
                    text_to_add = content
                else:
                    text_to_add = "Content successfully written to file"
                my_file.write(text_to_add)
                return (True, "Content successfully written to file")

            else:
                return (False, "Unsupported file mode.")

    except Exception as error:
        return (False, f"{error}")


def main():
    print("=== Cyber Archives Security ===\n")
    print("Using 'security_archive' to read from a nonexistent file:")
    result = secure_archive("/not/existing/file", "r")
    print(result)
    print()
    print("Using 'security_archive' to read from an inaccessible file:")
    result2 = secure_archive("/etc/shadow", "r")
    print(result2)
    print()
    print("Using 'security_archive' to read from a regular file:")
    result3 = secure_archive("ancient_fragment.txt", "r")
    print(result3)
    print()
    print("Using 'security_archive' to write previous to a new file:")
    result4 = secure_archive("ancient_fragment.txt", 'w',
                             "This is a fragment of text.")
    print(result4)


if __name__ == "__main__":
    main()
