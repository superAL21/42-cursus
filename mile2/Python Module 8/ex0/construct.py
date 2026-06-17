import sys
import os
import site


def is_virtual_enviroment() -> None:
    if sys.prefix == sys.base_prefix:
        print("\nMATRIX STATUS: You're still plugged in\n")
        print(f"Current Python: {sys.executable}")
        print("Virtual Environment: None detected\n")
        print("WARNING: You're in the global enviroment!")
        print("The machines can see everything you install.\n")
        print("To enter the construct, run:")
        print("python -m venv matrix_env")
        print("source matrix_env/bin/activate #On Unix")
        print(r"matrix_env\Scripts\activate #On Windows")
        print("\nThen run this program again.")
    else:
        print("\nMATRIX STATUS: Welcome to the construct\n")
        print(f"Current Python: {sys.executable}")
        env_name = os.path.basename(sys.prefix)
        print(f"Virtual Environment: {env_name}")
        print(f"Enviroment Path: {sys.prefix}\n")
        print("SUCCESS: You're in an isolated environment!")
        print("Safe to install packages"
              " without affecting\nthe global system.\n")
        package_path = site.getsitepackages()[0]
        print("Package installation path:")
        print(f"{package_path}")


if __name__ == "__main__":
    is_virtual_enviroment()
