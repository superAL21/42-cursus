import functools
from collections.abc import Callable
from typing import Any
import time


def spell_timer(func: Callable) -> Callable:

    @functools.wraps(func)
    def wrapper(*args, **kwargs) -> Any:
        print(f"Casting {func.__name__}...")

        time_stamp_start = time.perf_counter()
        res = func(*args, **kwargs)
        time_stamp_finish = time.perf_counter()
        dif = time_stamp_finish - time_stamp_start
        print(f"Spell completed in {dif:.3f} seconds")
        return res

    return wrapper


def power_validator(min_power: int) -> Callable:

    def intern_decorator(func: Callable) -> Callable:

        @functools.wraps(func)
        def wrapper(*args, **kwargs) -> Any:
            actual_power: int = kwargs.get("power", 0)

            if actual_power >= min_power:
                return func(*args, **kwargs)
            else:
                return "Insufficient power for this spell!"
        return wrapper
    return intern_decorator


def retry_spell(max_attempts: int) -> Callable:

    def inter_decorator(func: Callable) -> Callable:

        @functools.wraps(func)
        def wrapper(*args, **kwargs) -> Any:
            for attempt in range(1, max_attempts + 1):
                try:
                    res = func(*args, **kwargs)
                    return res
                except Exception:
                    if attempt < max_attempts:
                        print(
                            f"Spell failed, retrying... "
                            f"(attempt {attempt}/{max_attempts})"
                        )
            return f"Spell casting failed after {max_attempts} attempts"
        return wrapper
    return inter_decorator


class MageGuild:

    @staticmethod
    def validate_mage_name(name: str) -> bool:
        clean_name = name.replace(" ", "")
        return len(name) >= 3 and clean_name.isalpha()

    @power_validator(min_power=10)
    def cast_spell(self, spell_name: str, power: int) -> str:
        return f"Successfully cast {spell_name} with {power} power"


@spell_timer
def fireball() -> str:
    time.sleep(1.5)
    return "Fireball cast!"


@power_validator(min_power=50)
def launch_spell(power: int) -> str:
    return f"Spell channeled! Spell execcuted with {power}%!"


@retry_spell(3)
def unstable_spell() -> str:
    raise Exception("Spell unstable!")


def main() -> None:
    print("\nTesting spell timer...")
    result1 = fireball()
    print(f"Result: {result1}")

    print("\nTesting power validator...")
    result2 = launch_spell(power=80)
    print(f"Result: {result2}")
    result3 = launch_spell(power=30)
    print(f"Result: {result3}")

    print("\nTesting retry spell...")
    result4 = unstable_spell()
    print(f"{result4}")
    print("Waaaaaaaaaagh spelled!")

    print("\nTesting MageGuild...")
    mage = MageGuild()
    print(f"{MageGuild.validate_mage_name('Lesly')}")
    print(f"{MageGuild.validate_mage_name('AS')}")
    print(f"{mage.cast_spell('Lightning', power=15)}")
    print(f"{mage.cast_spell('Lightning', power=5)}")


if __name__ == "__main__":
    main()
